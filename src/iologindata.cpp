/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2016  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "otpch.h"

#include "iologindata.h"
#include "configmanager.h"
#include "game.h"

extern ConfigManager g_config;
extern Game g_game;

Account IOLoginData::loadAccount(uint32_t accno)
{
	Database& db = Database::getInstance();
	Account account;

	auto query = db.createQuery("SELECT `id`, `name`, `password`, `type`, `premdays`, `lastday` FROM `accounts` WHERE `id` = %0");
	query << accno;
	DBResult_ptr result = Database::getInstance().storeQuery(query);
	if (!result) {
		return account;
	}

	account.id = result->getNumber<uint32_t>("id");
	account.name = result->getString("name");
	account.accountType = static_cast<AccountType_t>(result->getNumber<int32_t>("type"));
	account.premiumDays = result->getNumber<uint16_t>("premdays");
	account.lastDay = result->getNumber<time_t>("lastday");
	return account;
}

bool IOLoginData::saveAccount(const Account& acc)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("UPDATE `accounts` SET `premdays` = %0, `lastday` = %1 WHERE `id` = %2");
	query << acc.premiumDays << acc.lastDay << acc.id;
	return db.executeQuery(query);
}

std::string decodeSecret(const std::string& secret)
{
	// simple base32 decoding
	std::string key;
	key.reserve(10);

	uint32_t buffer = 0, left = 0;
	for (const auto& ch : secret) {
		buffer <<= 5;
		if (ch >= 'A' && ch <= 'Z') {
			buffer |= (ch & 0x1F) - 1;
		} else if (ch >= '2' && ch <= '7') {
			buffer |= ch - 24;
		} else {
			// if a key is broken, return empty and the comparison
			// will always be false since the token must not be empty
			return {};
		}

		left += 5;
		if (left >= 8) {
			left -= 8;
			key.push_back(static_cast<char>(buffer >> left));
		}
	}

	return key;
}

bool IOLoginData::loginserverAuthentication(const std::string& name, const std::string& password, Account& account)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `id`, `name`, `password`, `secret`, `type`, `premdays`, `lastday` FROM `accounts` WHERE `name` = %0q");
	query << query.escapeString(name);
	DBResult_ptr result = db.storeQuery(query);
	if (!result) {
		return false;
	}

	if (transformToSHA1(password) != result->getString("password")) {
		return false;
	}

	account.id = result->getNumber<uint32_t>("id");
	account.name = result->getString("name");
	account.key = decodeSecret(result->getString("secret"));
	account.accountType = static_cast<AccountType_t>(result->getNumber<int32_t>("type"));
	account.premiumDays = result->getNumber<uint16_t>("premdays");
	account.lastDay = result->getNumber<time_t>("lastday");

	query = db.createQuery("SELECT `name`, `deletion` FROM `players` WHERE `account_id` = %0") << account.id;
	if ((result = db.storeQuery(query))) {
		do {
			if (result->getNumber<uint64_t>("deletion") == 0) {
				account.characters.push_back(result->getString("name"));
			}
		} while (result->next());
		std::sort(account.characters.begin(), account.characters.end());
	}
	return true;
}

uint32_t IOLoginData::gameworldAuthentication(const std::string& accountName, const std::string& password, std::string& characterName)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `id`, `password` FROM `accounts` WHERE `name` = %0q");
	query << query.escapeString(accountName);
	DBResult_ptr result = db.storeQuery(query);
	if (!result) {
		return 0;
	}

	if (transformToSHA1(password) != result->getString("password")) {
		return 0;
	}

	uint32_t accountId = result->getNumber<uint32_t>("id");

	query = db.createQuery("SELECT `account_id`, `name`, `deletion` FROM `players` WHERE `name` = %0q");
	query << query.escapeString(characterName);
	result = db.storeQuery(query);
	if (!result) {
		return 0;
	}

	if (result->getNumber<uint32_t>("account_id") != accountId || result->getNumber<uint64_t>("deletion") != 0) {
		return 0;
	}
	characterName = result->getString("name");
	return accountId;
}

void IOLoginData::setAccountType(uint32_t accountId, AccountType_t accountType)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("UPDATE `accounts` SET `type` = %0 WHERE `id` = %1");
	query << accountId << static_cast<uint16_t>(accountType);
	db.executeQuery(query);
}

void IOLoginData::updateOnlineStatus(uint32_t guid, bool login)
{
	if (g_config.getBoolean(ConfigManager::ALLOW_CLONES)) {
		return;
	}

	Database& db = Database::getInstance();

	auto query = db.createQuery(login ? "INSERT INTO `players_online` VALUES (%0)" : "DELETE FROM `players_online` WHERE `player_id` = %0");
	query << guid;
	db.executeQuery(query);
}

bool IOLoginData::preloadPlayer(Player* player, const std::string& name)
{
	Database& db = Database::getInstance();

	std::ostringstream ss;
	ss << "SELECT `id`, `account_id`, `group_id`, `deletion`, (SELECT `type` FROM `accounts` WHERE `accounts`.`id` = `account_id`) AS `account_type`";
	if (!g_config.getBoolean(ConfigManager::FREE_PREMIUM)) {
		ss << ", (SELECT `premdays` FROM `accounts` WHERE `accounts`.`id` = `account_id`) AS `premium_days`";
	}
	ss << " FROM `players` WHERE `name` = %0q";

	auto query = db.createQuery(ss.str());
	query << query.escapeString(name);
	DBResult_ptr result = db.storeQuery(query);
	if (!result) {
		return false;
	}

	if (result->getNumber<uint64_t>("deletion") != 0) {
		return false;
	}

	player->setGUID(result->getNumber<uint32_t>("id"));
	Group* group = g_game.groups.getGroup(result->getNumber<uint16_t>("group_id"));
	if (!group) {
		std::cout << "[Error - IOLoginData::preloadPlayer] " << player->name << " has Group ID " << result->getNumber<uint16_t>("group_id") << " which doesn't exist." << std::endl;
		return false;
	}
	player->setGroup(group);
	player->accountNumber = result->getNumber<uint32_t>("account_id");
	player->accountType = static_cast<AccountType_t>(result->getNumber<uint16_t>("account_type"));
	if (!g_config.getBoolean(ConfigManager::FREE_PREMIUM)) {
		player->premiumDays = result->getNumber<uint16_t>("premium_days");
	} else {
		player->premiumDays = std::numeric_limits<uint16_t>::max();
	}
	return true;
}

bool IOLoginData::loadPlayerById(Player* player, uint32_t id)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `id`, `name`, `account_id`, `group_id`, `sex`, `vocation`, `experience`, `level`, `maglevel`, `health`, `healthmax`, `blessings`, `mana`, `manamax`, `manaspent`, `soul`, `lookbody`, `lookfeet`, `lookhead`, `looklegs`, `looktype`, `lookaddons`, `posx`, `posy`, `posz`, `cap`, `lastlogin`, `lastlogout`, `lastip`, `conditions`, `skulltime`, `skull`, `town_id`, `balance`, `offlinetraining_time`, `offlinetraining_skill`, `stamina`, `skill_fist`, `skill_fist_tries`, `skill_club`, `skill_club_tries`, `skill_sword`, `skill_sword_tries`, `skill_axe`, `skill_axe_tries`, `skill_dist`, `skill_dist_tries`, `skill_shielding`, `skill_shielding_tries`, `skill_fishing`, `skill_fishing_tries` FROM `players` WHERE `id` = %0");
	query << id;
	return loadPlayer(player, db.storeQuery(query));
}

bool IOLoginData::loadPlayerByName(Player* player, const std::string& name)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `id`, `name`, `account_id`, `group_id`, `sex`, `vocation`, `experience`, `level`, `maglevel`, `health`, `healthmax`, `blessings`, `mana`, `manamax`, `manaspent`, `soul`, `lookbody`, `lookfeet`, `lookhead`, `looklegs`, `looktype`, `lookaddons`, `posx`, `posy`, `posz`, `cap`, `lastlogin`, `lastlogout`, `lastip`, `conditions`, `skulltime`, `skull`, `town_id`, `balance`, `offlinetraining_time`, `offlinetraining_skill`, `stamina`, `skill_fist`, `skill_fist_tries`, `skill_club`, `skill_club_tries`, `skill_sword`, `skill_sword_tries`, `skill_axe`, `skill_axe_tries`, `skill_dist`, `skill_dist_tries`, `skill_shielding`, `skill_shielding_tries`, `skill_fishing`, `skill_fishing_tries` FROM `players` WHERE `name` = %0q");
	query << query.escapeString(name);
	return loadPlayer(player, db.storeQuery(query));
}

bool IOLoginData::loadPlayer(Player* player, DBResult_ptr result)
{
	if (!result) {
		return false;
	}

	Database& db = Database::getInstance();

	uint32_t accno = result->getNumber<uint32_t>("account_id");
	Account acc = loadAccount(accno);

	player->setGUID(result->getNumber<uint32_t>("id"));
	player->name = result->getString("name");
	player->accountNumber = accno;

	player->accountType = acc.accountType;

	if (g_config.getBoolean(ConfigManager::FREE_PREMIUM)) {
		player->premiumDays = std::numeric_limits<uint16_t>::max();
	} else {
		player->premiumDays = acc.premiumDays;
	}

	Group* group = g_game.groups.getGroup(result->getNumber<uint16_t>("group_id"));
	if (!group) {
		std::cout << "[Error - IOLoginData::loadPlayer] " << player->name << " has Group ID " << result->getNumber<uint16_t>("group_id") << " which doesn't exist" << std::endl;
		return false;
	}
	player->setGroup(group);

	player->bankBalance = result->getNumber<uint64_t>("balance");

	player->setSex(static_cast<PlayerSex_t>(result->getNumber<uint16_t>("sex")));
	player->level = std::max<uint32_t>(1, result->getNumber<uint32_t>("level"));

	uint64_t experience = result->getNumber<uint64_t>("experience");

	uint64_t currExpCount = Player::getExpForLevel(player->level);
	uint64_t nextExpCount = Player::getExpForLevel(player->level + 1);
	if (experience < currExpCount || experience > nextExpCount) {
		experience = currExpCount;
	}

	player->experience = experience;

	if (currExpCount < nextExpCount) {
		player->levelPercent = Player::getPercentLevel(player->experience - currExpCount, nextExpCount - currExpCount);
	} else {
		player->levelPercent = 0;
	}

	player->soul = result->getNumber<uint16_t>("soul");
	player->capacity = result->getNumber<uint32_t>("cap") * 100;
	player->blessings = result->getNumber<uint16_t>("blessings");

	unsigned long conditionsSize;
	const char* conditions = result->getStream("conditions", conditionsSize);
	PropStream propStream;
	propStream.init(conditions, conditionsSize);

	Condition* condition = Condition::createCondition(propStream);
	while (condition) {
		if (condition->unserialize(propStream)) {
			player->storedConditionList.push_front(condition);
		} else {
			delete condition;
		}
		condition = Condition::createCondition(propStream);
	}

	if (!player->setVocation(result->getNumber<uint16_t>("vocation"))) {
		std::cout << "[Error - IOLoginData::loadPlayer] " << player->name << " has Vocation ID " << result->getNumber<uint16_t>("vocation") << " which doesn't exist" << std::endl;
		return false;
	}

	player->mana = result->getNumber<uint32_t>("mana");
	player->manaMax = result->getNumber<uint32_t>("manamax");
	player->magLevel = result->getNumber<uint32_t>("maglevel");

	uint64_t nextManaCount = player->vocation->getReqMana(player->magLevel + 1);
	uint64_t manaSpent = result->getNumber<uint64_t>("manaspent");
	if (manaSpent > nextManaCount) {
		manaSpent = 0;
	}

	player->manaSpent = manaSpent;
	player->magLevelPercent = Player::getPercentLevel(player->manaSpent, nextManaCount);

	player->health = result->getNumber<int32_t>("health");
	player->healthMax = result->getNumber<int32_t>("healthmax");

	player->defaultOutfit.lookType = result->getNumber<uint16_t>("looktype");
	player->defaultOutfit.lookHead = result->getNumber<uint16_t>("lookhead");
	player->defaultOutfit.lookBody = result->getNumber<uint16_t>("lookbody");
	player->defaultOutfit.lookLegs = result->getNumber<uint16_t>("looklegs");
	player->defaultOutfit.lookFeet = result->getNumber<uint16_t>("lookfeet");
	player->defaultOutfit.lookAddons = result->getNumber<uint16_t>("lookaddons");
	player->currentOutfit = player->defaultOutfit;

	if (g_game.getWorldType() != WORLD_TYPE_PVP_ENFORCED) {
		const time_t skullSeconds = result->getNumber<time_t>("skulltime") - time(nullptr);
		if (skullSeconds > 0) {
			//ensure that we round up the number of ticks
			player->skullTicks = (skullSeconds + 2) * 1000;

			uint16_t skull = result->getNumber<uint16_t>("skull");
			if (skull == SKULL_RED) {
				player->skull = SKULL_RED;
			} else if (skull == SKULL_BLACK) {
				player->skull = SKULL_BLACK;
			}
		}
	}

	player->loginPosition.x = result->getNumber<uint16_t>("posx");
	player->loginPosition.y = result->getNumber<uint16_t>("posy");
	player->loginPosition.z = result->getNumber<uint16_t>("posz");

	player->lastLoginSaved = result->getNumber<time_t>("lastlogin");
	player->lastLogout = result->getNumber<time_t>("lastlogout");

	player->offlineTrainingTime = result->getNumber<int32_t>("offlinetraining_time") * 1000;
	player->offlineTrainingSkill = result->getNumber<int32_t>("offlinetraining_skill");

	Town* town = g_game.map.towns.getTown(result->getNumber<uint32_t>("town_id"));
	if (!town) {
		std::cout << "[Error - IOLoginData::loadPlayer] " << player->name << " has Town ID " << result->getNumber<uint32_t>("town_id") << " which doesn't exist" << std::endl;
		return false;
	}

	player->town = town;

	const Position& loginPos = player->loginPosition;
	if (loginPos.x == 0 && loginPos.y == 0 && loginPos.z == 0) {
		player->loginPosition = player->getTemplePosition();
	}

	player->staminaMinutes = result->getNumber<uint16_t>("stamina");

	static const std::string skillNames[] = {"skill_fist", "skill_club", "skill_sword", "skill_axe", "skill_dist", "skill_shielding", "skill_fishing"};
	static const std::string skillNameTries[] = {"skill_fist_tries", "skill_club_tries", "skill_sword_tries", "skill_axe_tries", "skill_dist_tries", "skill_shielding_tries", "skill_fishing_tries"};
	static const size_t size = sizeof(skillNames) / sizeof(std::string);
	for (uint8_t i = 0; i < size; ++i) {
		uint16_t skillLevel = result->getNumber<uint16_t>(skillNames[i]);
		uint64_t skillTries = result->getNumber<uint64_t>(skillNameTries[i]);
		uint64_t nextSkillTries = player->vocation->getReqSkillTries(i, skillLevel + 1);
		if (skillTries > nextSkillTries) {
			skillTries = 0;
		}

		player->skills[i].level = skillLevel;
		player->skills[i].tries = skillTries;
		player->skills[i].percent = Player::getPercentLevel(skillTries, nextSkillTries);
	}

	auto query = db.createQuery("SELECT `guild_id`, `rank_id`, `nick` FROM `guild_membership` WHERE `player_id` = %0");
	query << player->getGUID();
	if ((result = db.storeQuery(query))) {
		uint32_t guildId = result->getNumber<uint32_t>("guild_id");
		uint32_t playerRankId = result->getNumber<uint32_t>("rank_id");
		player->guildNick = result->getString("nick");

		Guild* guild = g_game.getGuild(guildId);
		if (!guild) {
			query = db.createQuery("SELECT `name` FROM `guilds` WHERE `id` = %0");
			query << guildId;
			if ((result = db.storeQuery(query))) {
				guild = new Guild(guildId, result->getString("name"));
				g_game.addGuild(guild);

				query = db.createQuery("SELECT `id`, `name`, `level` FROM `guild_ranks` WHERE `guild_id` = %0");
				query << guildId;

				if ((result = db.storeQuery(query))) {
					do {
						guild->addRank(result->getNumber<uint32_t>("id"), result->getString("name"), result->getNumber<uint16_t>("level"));
					} while (result->next());
				}
			}
		}

		if (guild) {
			player->guild = guild;
			const GuildRank* rank = guild->getRankById(playerRankId);
			if (!rank) {
				query = db.createQuery("SELECT `id`, `name`, `level` FROM `guild_ranks` WHERE `id` = %0");
				query << playerRankId;

				if ((result = db.storeQuery(query))) {
					guild->addRank(result->getNumber<uint32_t>("id"), result->getString("name"), result->getNumber<uint16_t>("level"));
				}

				rank = guild->getRankById(playerRankId);
				if (!rank) {
					player->guild = nullptr;
				}
			}

			player->guildRank = rank;

			IOGuild::getWarList(guildId, player->guildWarList);

			query = db.createQuery("SELECT COUNT(*) AS `members` FROM `guild_membership` WHERE `guild_id` = %0");
			query << guildId;
			if ((result = db.storeQuery(query))) {
				guild->setMemberCount(result->getNumber<uint32_t>("members"));
			}
		}
	}

	query = db.createQuery("SELECT `player_id`, `name` FROM `player_spells` WHERE `player_id` = %0");
	query << player->getGUID();
	if ((result = db.storeQuery(query))) {
		do {
			player->learnedInstantSpellList.emplace_front(result->getString("name"));
		} while (result->next());
	}

	//load inventory items
	ItemMap itemMap;

	query = db.createQuery("SELECT `pid`, `sid`, `itemtype`, `count`, `attributes` FROM `player_items` WHERE `player_id` = %0 ORDER BY `sid` DESC");
	query << player->getGUID();
	if ((result = db.storeQuery(query))) {
		loadItems(itemMap, result);

		for (ItemMap::const_reverse_iterator it = itemMap.rbegin(), end = itemMap.rend(); it != end; ++it) {
			const std::pair<Item*, int32_t>& pair = it->second;
			Item* item = pair.first;
			int32_t pid = pair.second;
			if (pid >= 1 && pid <= 10) {
				player->internalAddThing(pid, item);
			} else {
				ItemMap::const_iterator it2 = itemMap.find(pid);
				if (it2 == itemMap.end()) {
					continue;
				}

				Container* container = it2->second.first->getContainer();
				if (container) {
					container->internalAddThing(item);
				}
			}
		}
	}

	//load depot items
	itemMap.clear();

	query = db.createQuery("SELECT `pid`, `sid`, `itemtype`, `count`, `attributes` FROM `player_depotitems` WHERE `player_id` = %0 ORDER BY `sid` DESC");
	query << player->getGUID();
	if ((result = db.storeQuery(query))) {
		loadItems(itemMap, result);

		for (ItemMap::const_reverse_iterator it = itemMap.rbegin(), end = itemMap.rend(); it != end; ++it) {
			const std::pair<Item*, int32_t>& pair = it->second;
			Item* item = pair.first;

			int32_t pid = pair.second;
			if (pid >= 0 && pid < 100) {
				DepotChest* depotChest = player->getDepotChest(pid, true);
				if (depotChest) {
					depotChest->internalAddThing(item);
				}
			} else {
				ItemMap::const_iterator it2 = itemMap.find(pid);
				if (it2 == itemMap.end()) {
					continue;
				}

				Container* container = it2->second.first->getContainer();
				if (container) {
					container->internalAddThing(item);
				}
			}
		}
	}

	//load inbox items
	itemMap.clear();

	query = db.createQuery("SELECT `pid`, `sid`, `itemtype`, `count`, `attributes` FROM `player_inboxitems` WHERE `player_id` = %0 ORDER BY `sid` DESC");
	query << player->getGUID();
	if ((result = db.storeQuery(query))) {
		loadItems(itemMap, result);

		for (ItemMap::const_reverse_iterator it = itemMap.rbegin(), end = itemMap.rend(); it != end; ++it) {
			const std::pair<Item*, int32_t>& pair = it->second;
			Item* item = pair.first;
			int32_t pid = pair.second;

			if (pid >= 0 && pid < 100) {
				player->getInbox()->internalAddThing(item);
			} else {
				ItemMap::const_iterator it2 = itemMap.find(pid);

				if (it2 == itemMap.end()) {
					continue;
				}

				Container* container = it2->second.first->getContainer();
				if (container) {
					container->internalAddThing(item);
				}
			}
		}
	}

	//load storage map
	query = db.createQuery("SELECT `key`, `value` FROM `player_storage` WHERE `player_id` = %0");
	query << player->getGUID();
	if ((result = db.storeQuery(query))) {
		do {
			player->addStorageValue(result->getNumber<uint32_t>("key"), result->getNumber<int32_t>("value"), true);
		} while (result->next());
	}

	//load vip
	query = db.createQuery("SELECT `player_id` FROM `account_viplist` WHERE `account_id` = %0");
	query << player->getAccount();
	if ((result = db.storeQuery(query))) {
		do {
			player->addVIPInternal(result->getNumber<uint32_t>("player_id"));
		} while (result->next());
	}

	player->updateBaseSpeed();
	player->updateInventoryWeight();
	player->updateItemsLight(true);
	return true;
}

bool IOLoginData::saveItems(const Player* player, const ItemBlockList& itemList, Query& query_insert, PropWriteStream& propWriteStream)
{
	std::ostringstream ss;

	typedef std::pair<Container*, int32_t> containerBlock;
	std::list<containerBlock> queue;

	int32_t runningId = 100;

	Database& db = Database::getInstance();
	for (const auto& it : itemList) {
		int32_t pid = it.first;
		Item* item = it.second;
		++runningId;

		propWriteStream.clear();
		item->serializeAttr(propWriteStream);

		size_t attributesSize;
		const char* attributes = propWriteStream.getStream(attributesSize);

		query_insert << player->getGUID() << pid << runningId << item->getID() << item->getSubType() << query_insert.escapeBlob(attributes, attributesSize);
		if (!db.executeQuery(query_insert)) {
			return false;
		}

		if (Container* container = item->getContainer()) {
			queue.emplace_back(container, runningId);
		}
	}

	while (!queue.empty()) {
		const containerBlock& cb = queue.front();
		Container* container = cb.first;
		int32_t parentId = cb.second;
		queue.pop_front();

		for (Item* item : container->getItemList()) {
			++runningId;

			Container* subContainer = item->getContainer();
			if (subContainer) {
				queue.emplace_back(subContainer, runningId);
			}

			propWriteStream.clear();
			item->serializeAttr(propWriteStream);

			size_t attributesSize;
			const char* attributes = propWriteStream.getStream(attributesSize);

			query_insert << player->getGUID() << parentId << runningId << item->getID() << item->getSubType() << query_insert.escapeBlob(attributes, attributesSize);
			if (!db.executeQuery(query_insert)) {
				return false;
			}
		}
	}
	return true;
}

bool IOLoginData::savePlayer(Player* player)
{
	if (player->getHealth() <= 0) {
		player->changeHealth(1);
	}

	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `save` FROM `players` WHERE `id` = %0");
	query << player->getGUID();
	DBResult_ptr result = db.storeQuery(query.str());
	if (!result) {
		return false;
	}

	if (result->getNumber<uint16_t>("save") == 0) {
		query = db.createQuery("UPDATE `players` SET `lastlogin` = %0, `lastip` = %1 WHERE `id` = %2");
		query << player->lastLoginSaved << player->lastIP << player->getGUID();
		return db.executeQuery(query);
	}

	//serialize conditions
	PropWriteStream propWriteStream;
	for (Condition* condition : player->conditions) {
		if (condition->isPersistent()) {
			condition->serialize(propWriteStream);
			propWriteStream.write<uint8_t>(CONDITIONATTR_END);
		}
	}

	size_t conditionsSize;
	const char* conditions = propWriteStream.getStream(conditionsSize);

	//First, an UPDATE query to write the player itself
	std::stringstream ss;
	ss << "UPDATE `players` SET ";
	ss << "`level` = " << player->level << ',';
	ss << "`group_id` = " << player->group->id << ',';
	ss << "`vocation` = " << player->getVocationId() << ',';
	ss << "`health` = " << player->health << ',';
	ss << "`healthmax` = " << player->healthMax << ',';
	ss << "`experience` = " << player->experience << ',';
	ss << "`lookbody` = " << static_cast<uint32_t>(player->defaultOutfit.lookBody) << ',';
	ss << "`lookfeet` = " << static_cast<uint32_t>(player->defaultOutfit.lookFeet) << ',';
	ss << "`lookhead` = " << static_cast<uint32_t>(player->defaultOutfit.lookHead) << ',';
	ss << "`looklegs` = " << static_cast<uint32_t>(player->defaultOutfit.lookLegs) << ',';
	ss << "`looktype` = " << player->defaultOutfit.lookType << ',';
	ss << "`lookaddons` = " << static_cast<uint32_t>(player->defaultOutfit.lookAddons) << ',';
	ss << "`maglevel` = " << player->magLevel << ',';
	ss << "`mana` = " << player->mana << ',';
	ss << "`manamax` = " << player->manaMax << ',';
	ss << "`manaspent` = " << player->manaSpent << ',';
	ss << "`soul` = " << static_cast<uint16_t>(player->soul) << ',';
	ss << "`town_id` = " << player->town->getID() << ',';

	const Position& loginPosition = player->getLoginPosition();
	ss << "`posx` = " << loginPosition.getX() << ',';
	ss << "`posy` = " << loginPosition.getY() << ',';
	ss << "`posz` = " << loginPosition.getZ() << ',';

	ss << "`cap` = " << (player->capacity / 100) << ',';
	ss << "`sex` = " << player->sex << ',';

	if (player->lastLoginSaved != 0) {
		ss << "`lastlogin` = " << player->lastLoginSaved << ',';
	}

	if (player->lastIP != 0) {
		ss << "`lastip` = " << player->lastIP << ',';
	}

	ss << "`conditions` = " << query.escapeBlob(conditions, conditionsSize) << ',';

	if (g_game.getWorldType() != WORLD_TYPE_PVP_ENFORCED) {
		int32_t skullTime = 0;

		if (player->skullTicks > 0) {
			skullTime = time(nullptr) + player->skullTicks / 1000;
		}

		ss << "`skulltime` = " << skullTime << ',';

		Skulls_t skull = SKULL_NONE;
		if (player->skull == SKULL_RED) {
			skull = SKULL_RED;
		} else if (player->skull == SKULL_BLACK) {
			skull = SKULL_BLACK;
		}
		ss << "`skull` = " << static_cast<uint32_t>(skull) << ',';
	}

	ss << "`lastlogout` = " << player->getLastLogout() << ',';
	ss << "`balance` = " << player->bankBalance << ',';
	ss << "`offlinetraining_time` = " << player->getOfflineTrainingTime() / 1000 << ',';
	ss << "`offlinetraining_skill` = " << player->getOfflineTrainingSkill() << ',';
	ss << "`stamina` = " << player->getStaminaMinutes() << ',';

	ss << "`skill_fist` = " << player->skills[SKILL_FIST].level << ',';
	ss << "`skill_fist_tries` = " << player->skills[SKILL_FIST].tries << ',';
	ss << "`skill_club` = " << player->skills[SKILL_CLUB].level << ',';
	ss << "`skill_club_tries` = " << player->skills[SKILL_CLUB].tries << ',';
	ss << "`skill_sword` = " << player->skills[SKILL_SWORD].level << ',';
	ss << "`skill_sword_tries` = " << player->skills[SKILL_SWORD].tries << ',';
	ss << "`skill_axe` = " << player->skills[SKILL_AXE].level << ',';
	ss << "`skill_axe_tries` = " << player->skills[SKILL_AXE].tries << ',';
	ss << "`skill_dist` = " << player->skills[SKILL_DISTANCE].level << ',';
	ss << "`skill_dist_tries` = " << player->skills[SKILL_DISTANCE].tries << ',';
	ss << "`skill_shielding` = " << player->skills[SKILL_SHIELD].level << ',';
	ss << "`skill_shielding_tries` = " << player->skills[SKILL_SHIELD].tries << ',';
	ss << "`skill_fishing` = " << player->skills[SKILL_FISHING].level << ',';
	ss << "`skill_fishing_tries` = " << player->skills[SKILL_FISHING].tries << ',';

	if (!player->isOffline()) {
		ss << "`onlinetime` = `onlinetime` + " << (time(nullptr) - player->lastLoginSaved) << ',';
	}
	ss << "`blessings` = " << static_cast<uint32_t>(player->blessings);
	ss << " WHERE `id` = " << player->getGUID();
	query = db.createQuery(ss.str());

	auto transaction = db.createTransaction();
	if (!transaction.begin()) {
		return false;
	}

	if (!db.executeQuery(query)) {
		return false;
	}

	// learned spells
	query = db.createQuery("DELETE FROM `player_spells` WHERE `player_id` = %0");
	query << player->getGUID();
	if (!db.executeQuery(query)) {
		return false;
	}

	auto spellsQuery = db.createQuery("INSERT INTO `player_spells` (`player_id`, `name`) VALUES (%0, %1q)");
	for (const std::string& spellName : player->learnedInstantSpellList) {
		query << player->getGUID() << spellsQuery.escapeString(spellName);
		query.execute();
	}

	//item saving
	query = db.createQuery("DELETE FROM `player_items` WHERE `player_id` = %0");
	query << player->getGUID();
	if (!db.executeQuery(query)) {
		return false;
	}

	auto itemsQuery = db.createQuery("INSERT INTO `player_items` (`player_id`, `pid`, `sid`, `itemtype`, `count`, `attributes`) VALUES (%0, %1, %2, %3, %4, %5)");

	ItemBlockList itemList;
	for (int32_t slotId = 1; slotId <= 10; ++slotId) {
		Item* item = player->inventory[slotId];
		if (item) {
			itemList.emplace_back(slotId, item);
		}
	}

	if (!saveItems(player, itemList, itemsQuery, propWriteStream)) {
		return false;
	}

	if (player->lastDepotId != -1) {
		//save depot items
		query = db.createQuery("DELETE FROM `player_depotitems` WHERE `player_id` = %0");
		query << player->getGUID();

		if (!db.executeQuery(query)) {
			return false;
		}

		auto depotQuery = db.createQuery("INSERT INTO `player_depotitems` (`player_id`, `pid`, `sid`, `itemtype`, `count`, `attributes`) VALUES (%0, %1, %2, %3, %4, %5)");
		itemList.clear();

		for (const auto& it : player->depotChests) {
			DepotChest* depotChest = it.second;
			for (Item* item : depotChest->getItemList()) {
				itemList.emplace_back(it.first, item);
			}
		}

		if (!saveItems(player, itemList, depotQuery, propWriteStream)) {
			return false;
		}
	}

	//save inbox items
	query = db.createQuery("DELETE FROM `player_inboxitems` WHERE `player_id` = %0");
	query << player->getGUID();
	if (!db.executeQuery(query)) {
		return false;
	}

	auto inboxQuery = db.createQuery("INSERT INTO `player_inboxitems` (`player_id`, `pid`, `sid`, `itemtype`, `count`, `attributes`) VALUES (%0, %1, %2, %3, %4, %5)");
	itemList.clear();

	for (Item* item : player->getInbox()->getItemList()) {
		itemList.emplace_back(0, item);
	}

	if (!saveItems(player, itemList, inboxQuery, propWriteStream)) {
		return false;
	}

	query = db.createQuery("DELETE FROM `player_storage` WHERE `player_id` = %0");
	query << player->getGUID();
	if (!db.executeQuery(query)) {
		return false;
	}

	auto storageQuery = db.createQuery("INSERT INTO `player_storage` (`player_id`, `key`, `value`) VALUES (%0, %1, %2)");
	player->genReservedStorageRange();

	for (const auto& it : player->storageMap) {
		query << player->getGUID() << it.first << it.second;
		if (!storageQuery.execute()) {
			return false;
		}
	}

	if (!storageQuery.execute()) {
		return false;
	}

	//End the transaction
	return transaction.commit();
}

std::string IOLoginData::getNameByGuid(uint32_t guid)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `name` FROM `players` WHERE `id` = %0");
	query << guid;
	DBResult_ptr result = db.storeQuery(query);
	if (!result) {
		return {};
	}
	return result->getString("name");
}

uint32_t IOLoginData::getGuidByName(const std::string& name)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `id` FROM `players` WHERE `name` = %0q");
	query << query.escapeString(name);
	DBResult_ptr result = db.storeQuery(query);
	if (!result) {
		return 0;
	}
	return result->getNumber<uint32_t>("id");
}

bool IOLoginData::getGuidByNameEx(uint32_t& guid, bool& specialVip, std::string& name)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `name`, `id`, `group_id`, `account_id` FROM `players` WHERE `name` = %0q");
	query << query.escapeString(name);
	DBResult_ptr result = db.storeQuery(query);
	if (!result) {
		return false;
	}

	name = result->getString("name");
	guid = result->getNumber<uint32_t>("id");
	Group* group = g_game.groups.getGroup(result->getNumber<uint16_t>("group_id"));

	uint64_t flags;
	if (group) {
		flags = group->flags;
	} else {
		flags = 0;
	}

	specialVip = (flags & PlayerFlag_SpecialVIP) != 0;
	return true;
}

bool IOLoginData::formatPlayerName(std::string& name)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `name` FROM `players` WHERE `name` = %0q");
	query << query.escapeString(name);

	DBResult_ptr result = db.storeQuery(query);
	if (!result) {
		return false;
	}

	name = result->getString("name");
	return true;
}

void IOLoginData::loadItems(ItemMap& itemMap, DBResult_ptr result)
{
	do {
		uint32_t sid = result->getNumber<uint32_t>("sid");
		uint32_t pid = result->getNumber<uint32_t>("pid");
		uint16_t type = result->getNumber<uint16_t>("itemtype");
		uint16_t count = result->getNumber<uint16_t>("count");

		unsigned long attrSize;
		const char* attr = result->getStream("attributes", attrSize);

		PropStream propStream;
		propStream.init(attr, attrSize);

		Item* item = Item::CreateItem(type, count);
		if (item) {
			if (!item->unserializeAttr(propStream)) {
				std::cout << "WARNING: Serialize error in IOLoginData::loadItems" << std::endl;
			}

			std::pair<Item*, uint32_t> pair(item, pid);
			itemMap[sid] = pair;
		}
	} while (result->next());
}

void IOLoginData::increaseBankBalance(uint32_t guid, uint64_t bankBalance)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("UPDATE `players` SET `balance` = `balance` + %0 WHERE `id` = %1");
	query << bankBalance << guid;
	db.executeQuery(query);
}

bool IOLoginData::hasBiddedOnHouse(uint32_t guid)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("SELECT `id` FROM `houses` WHERE `highest_bidder` = %0 LIMIT 1");
	query << guid;
	return db.storeQuery(query).get() != nullptr;
}

std::forward_list<VIPEntry> IOLoginData::getVIPEntries(uint32_t accountId)
{
	Database& db = Database::getInstance();

	std::forward_list<VIPEntry> entries;
	auto query = db.createQuery("SELECT `player_id`, (SELECT `name` FROM `players` WHERE `id` = `player_id`) AS `name`, `description`, `icon`, `notify` FROM `account_viplist` WHERE `account_id` = %0");
	query << accountId;

	DBResult_ptr result = db.storeQuery(query);
	if (result) {
		do {
			entries.emplace_front(
				result->getNumber<uint32_t>("player_id"),
				result->getString("name"),
				result->getString("description"),
				result->getNumber<uint32_t>("icon"),
				result->getNumber<uint16_t>("notify") != 0
			);
		} while (result->next());
	}
	return entries;
}

void IOLoginData::addVIPEntry(uint32_t accountId, uint32_t guid, const std::string& description, uint32_t icon, bool notify)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("INSERT INTO `account_viplist` (`account_id`, `player_id`, `description`, `icon`, `notify`) VALUES (%0, %1, %2q, %3, %4)");
	query << accountId << guid << query.escapeString(description) << icon << notify;
	db.executeQuery(query);
}

void IOLoginData::editVIPEntry(uint32_t accountId, uint32_t guid, const std::string& description, uint32_t icon, bool notify)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("UPDATE `account_viplist` SET `description` = %0q, `icon` = %1, `notify` = %2 WHERE `account_id` = %3 AND `player_id` = %4");
	query << query.escapeString(description) << icon << notify << accountId << guid;
	db.executeQuery(query);
}

void IOLoginData::removeVIPEntry(uint32_t accountId, uint32_t guid)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("DELETE FROM `account_viplist` WHERE `account_id` = %0 AND `player_id` = %1");
	query << accountId << guid;
	db.executeQuery(query);
}

void IOLoginData::addPremiumDays(uint32_t accountId, int32_t addDays)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("UPDATE `accounts` SET `premdays` = `premdays` + %0 WHERE `id` = %1");
	query << addDays << accountId;
	db.executeQuery(query);
}

void IOLoginData::removePremiumDays(uint32_t accountId, int32_t removeDays)
{
	Database& db = Database::getInstance();

	auto query = db.createQuery("UPDATE `accounts` SET `premdays` = `premdays` - %0 WHERE `id` = %1");
	query << removeDays << accountId;
	db.executeQuery(query);
}
