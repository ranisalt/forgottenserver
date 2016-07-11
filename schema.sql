CREATE TABLE IF NOT EXISTS "accounts" (
  "name" TEXT NOT NULL UNIQUE,
  "password" TEXT NOT NULL,
  "secret" TEXT,
  "type" INTEGER NOT NULL DEFAULT 1,
  "premdays" INTEGER NOT NULL DEFAULT 0,
  "lastday" INTEGER NOT NULL DEFAULT 0,
  "email" TEXT,
  "creation" INTEGER NOT NULL DEFAULT 0
);

CREATE TABLE IF NOT EXISTS "players" (
  "name" TEXT NOT NULL UNIQUE,
  "group_id" INTEGER NOT NULL DEFAULT 1,
  "account_id" INTEGER NOT NULL,
  "level" INTEGER NOT NULL DEFAULT 1,
  "vocation" INTEGER NOT NULL DEFAULT 0,
  "health" INTEGER NOT NULL DEFAULT 150,
  "healthmax" INTEGER NOT NULL DEFAULT 150,
  "experience" INTEGER NOT NULL DEFAULT 0,
  "lookbody" INTEGER NOT NULL DEFAULT 0,
  "lookfeet" INTEGER NOT NULL DEFAULT 0,
  "lookhead" INTEGER NOT NULL DEFAULT 0,
  "looklegs" INTEGER NOT NULL DEFAULT 0,
  "looktype" INTEGER NOT NULL DEFAULT 136,
  "lookaddons" INTEGER NOT NULL DEFAULT 0,
  "maglevel" INTEGER NOT NULL DEFAULT 0,
  "mana" INTEGER NOT NULL DEFAULT 0,
  "manamax" INTEGER NOT NULL DEFAULT 0,
  "manaspent" INTEGER NOT NULL DEFAULT 0,
  "soul" INTEGER NOT NULL DEFAULT 0,
  "town_id" INTEGER NOT NULL DEFAULT 0,
  "posx" INTEGER NOT NULL DEFAULT 0,
  "posy" INTEGER NOT NULL DEFAULT 0,
  "posz" INTEGER NOT NULL DEFAULT 0,
  "conditions" blob NOT NULL,
  "cap" INTEGER NOT NULL DEFAULT 0,
  "sex" INTEGER NOT NULL DEFAULT 0,
  "lastlogin" INTEGER NOT NULL DEFAULT 0,
  "lastip" INTEGER NOT NULL DEFAULT 0,
  "save" INTEGER NOT NULL DEFAULT 1,
  "skull" INTEGER NOT NULL DEFAULT 0,
  "skulltime" INTEGER NOT NULL DEFAULT 0,
  "lastlogout" INTEGER NOT NULL DEFAULT 0,
  "blessings" INTEGER NOT NULL DEFAULT 0,
  "onlinetime" INTEGER NOT NULL DEFAULT 0,
  "deletion" INTEGER NOT NULL DEFAULT 0,
  "balance" INTEGER NOT NULL DEFAULT 0,
  "offlinetraining_time" INTEGER NOT NULL DEFAULT 43200,
  "offlinetraining_skill" INTEGER NOT NULL DEFAULT -1,
  "stamina" INTEGER NOT NULL DEFAULT 2520,
  "skill_fist" INTEGER NOT NULL DEFAULT 10,
  "skill_fist_tries" INTEGER NOT NULL DEFAULT 0,
  "skill_club" INTEGER NOT NULL DEFAULT 10,
  "skill_club_tries" INTEGER NOT NULL DEFAULT 0,
  "skill_sword" INTEGER NOT NULL DEFAULT 10,
  "skill_sword_tries" INTEGER NOT NULL DEFAULT 0,
  "skill_axe" INTEGER NOT NULL DEFAULT 10,
  "skill_axe_tries" INTEGER NOT NULL DEFAULT 0,
  "skill_dist" INTEGER NOT NULL DEFAULT 10,
  "skill_dist_tries" INTEGER NOT NULL DEFAULT 0,
  "skill_shielding" INTEGER NOT NULL DEFAULT 10,
  "skill_shielding_tries" INTEGER NOT NULL DEFAULT 0,
  "skill_fishing" INTEGER NOT NULL DEFAULT 10,
  "skill_fishing_tries" INTEGER NOT NULL DEFAULT 0,
  FOREIGN KEY ("account_id") REFERENCES "accounts" ON DELETE CASCADE
);
CREATE INDEX "players_vocation" ON "players" ("vocation");

CREATE TABLE IF NOT EXISTS "account_bans" (
  "account_id" INTEGER NOT NULL PRIMARY KEY,
  "reason" TEXT NOT NULL,
  "banned_at" INTEGER NOT NULL,
  "expires_at" INTEGER NOT NULL,
  "banned_by" INTEGER NOT NULL,
  FOREIGN KEY ("account_id") REFERENCES "accounts" ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY ("banned_by") REFERENCES "players" ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE IF NOT EXISTS "account_ban_history" (
  "account_id" INTEGER NOT NULL,
  "reason" TEXT NOT NULL,
  "banned_at" INTEGER NOT NULL,
  "expired_at" INTEGER NOT NULL,
  "banned_by" INTEGER NOT NULL,
  FOREIGN KEY ("account_id") REFERENCES "accounts" ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY ("banned_by") REFERENCES "players" ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE IF NOT EXISTS "ip_bans" (
  "ip" INTEGER NOT NULL PRIMARY KEY,
  "reason" TEXT NOT NULL,
  "banned_at" INTEGER NOT NULL,
  "expires_at" INTEGER NOT NULL,
  "banned_by" INTEGER NOT NULL,
  FOREIGN KEY ("banned_by") REFERENCES "players" ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE IF NOT EXISTS "player_namelocks" (
  "player_id" INTEGER NOT NULL PRIMARY KEY,
  "reason" TEXT NOT NULL,
  "namelocked_at" INTEGER NOT NULL,
  "namelocked_by" INTEGER NOT NULL,
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY ("namelocked_by") REFERENCES "players" ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE IF NOT EXISTS "account_viplist" (
  "account_id" INTEGER NOT NULL /* id of account whose viplist entry it is */,
  "player_id" INTEGER NOT NULL /* id of target player of viplist entry */,
  "description" TEXT NOT NULL DEFAULT '',
  "icon" INTEGER NOT NULL DEFAULT 0,
  "notify" INTEGER NOT NULL DEFAULT 0,
  UNIQUE (account_id, player_id) ON CONFLICT REPLACE,
  FOREIGN KEY ("account_id") REFERENCES "accounts" ON DELETE CASCADE,
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "guilds" (
  "name" TEXT NOT NULL UNIQUE,
  "ownerid" INTEGER NOT NULL UNIQUE,
  "creationdata" INTEGER NOT NULL,
  "motd" TEXT NOT NULL DEFAULT '',
  FOREIGN KEY ("ownerid") REFERENCES "players" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "guild_invites" (
  "player_id" INTEGER NOT NULL,
  "guild_id" INTEGER NOT NULL,
  PRIMARY KEY ("player_id", "guild_id"),
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE,
  FOREIGN KEY ("guild_id") REFERENCES "guilds" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "guild_ranks" (
  "guild_id" INTEGER NOT NULL,
  "name" TEXT NOT NULL,
  "level" INTEGER NOT NULL,
  FOREIGN KEY ("guild_id") REFERENCES "guilds" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "guild_membership" (
  "player_id" INTEGER NOT NULL PRIMARY KEY,
  "guild_id" INTEGER NOT NULL,
  "rank_id" INTEGER NOT NULL,
  "nick" TEXT NOT NULL DEFAULT '',
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY ("guild_id") REFERENCES "guilds" ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY ("rank_id") REFERENCES "guild_ranks" ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE IF NOT EXISTS "guild_wars" (
  "guild1" INTEGER NOT NULL DEFAULT 0,
  "guild2" INTEGER NOT NULL DEFAULT 0,
  "name1" TEXT NOT NULL,
  "name2" TEXT NOT NULL,
  "status" INTEGER NOT NULL DEFAULT 0,
  "started" INTEGER NOT NULL DEFAULT 0,
  "ended" INTEGER NOT NULL DEFAULT 0
);
CREATE INDEX "guild_wars_guild1" ON "guild_wars" ("guild1");
CREATE INDEX "guild_wars_guild2" ON "guild_wars" ("guild2");

CREATE TABLE IF NOT EXISTS "guildwar_kills" (
  "killer" TEXT NOT NULL,
  "target" TEXT NOT NULL,
  "killerguild" INTEGER NOT NULL DEFAULT 0,
  "targetguild" INTEGER NOT NULL DEFAULT 0,
  "warid" INTEGER NOT NULL DEFAULT 0,
  "time" INTEGER NOT NULL,
  FOREIGN KEY ("warid") REFERENCES "guild_wars" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "houses" (
  "owner" INTEGER NOT NULL,
  "paid" INTEGER NOT NULL DEFAULT 0,
  "warnings" INTEGER NOT NULL DEFAULT 0,
  "name" TEXT NOT NULL,
  "rent" INTEGER NOT NULL DEFAULT 0,
  "town_id" INTEGER NOT NULL DEFAULT 0,
  "bid" INTEGER NOT NULL DEFAULT 0,
  "bid_end" INTEGER NOT NULL DEFAULT 0,
  "last_bid" INTEGER NOT NULL DEFAULT 0,
  "highest_bidder" INTEGER NOT NULL DEFAULT 0,
  "size" INTEGER NOT NULL DEFAULT 0,
  "beds" INTEGER NOT NULL DEFAULT 0
);
CREATE INDEX "houses_owner" ON "houses" ("owner");
CREATE INDEX "houses_town_id" ON "houses" ("town_id");

CREATE TABLE IF NOT EXISTS "house_lists" (
  "house_id" INTEGER NOT NULL,
  "listid" INTEGER NOT NULL,
  "list" TEXT NOT NULL,
  FOREIGN KEY ("house_id") REFERENCES "houses" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "market_history" (
  "player_id" INTEGER NOT NULL,
  "sale" INTEGER NOT NULL DEFAULT 0,
  "itemtype" INTEGER NOT NULL,
  "amount" INTEGER NOT NULL,
  "price" INTEGER NOT NULL DEFAULT 0,
  "expires_at" INTEGER NOT NULL,
  "inserted" INTEGER NOT NULL,
  "state" INTEGER NOT NULL,
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE
);
CREATE INDEX "market_history_player_id" ON "market_history" ("player_id", "sale");

CREATE TABLE IF NOT EXISTS "market_offers" (
  "player_id" INTEGER NOT NULL,
  "sale" INTEGER NOT NULL DEFAULT 0,
  "itemtype" INTEGER NOT NULL,
  "amount" INTEGER NOT NULL,
  "created" INTEGER NOT NULL,
  "anonymous" INTEGER NOT NULL DEFAULT 0,
  "price" INTEGER NOT NULL DEFAULT 0,
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE
);

CREATE INDEX "market_offers_sale" ON "market_offers" ("sale", "itemtype");
CREATE INDEX "market_created" ON "market_offers" ("created");

CREATE TABLE IF NOT EXISTS "players_online" (
  "player_id" INTEGER NOT NULL PRIMARY KEY
);

CREATE TABLE IF NOT EXISTS "player_deaths" (
  "player_id" INTEGER NOT NULL,
  "time" INTEGER NOT NULL DEFAULT 0,
  "level" INTEGER NOT NULL DEFAULT 1,
  "killed_by" TEXT NOT NULL,
  "is_player" INTEGER NOT NULL DEFAULT 1,
  "mostdamage_by" TEXT NOT NULL,
  "mostdamage_is_player" INTEGER NOT NULL DEFAULT 0,
  "unjustified" INTEGER NOT NULL DEFAULT 0,
  "mostdamage_unjustified" INTEGER NOT NULL DEFAULT 0,
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE
);
CREATE INDEX "player_deaths_killed_by" ON "player_deaths" ("killed_by");
CREATE INDEX "player_deaths_mostdamage_by" ON "player_deaths" ("mostdamage_by");

CREATE TABLE IF NOT EXISTS "player_depotitems" (
  "player_id" INTEGER NOT NULL,
  "sid" INTEGER NOT NULL,
  "pid" INTEGER NOT NULL DEFAULT 0,
  "itemtype" INTEGER NOT NULL,
  "count" INTEGER NOT NULL DEFAULT 0,
  "attributes" blob NOT NULL,
  UNIQUE ("player_id", "sid"),
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "player_inboxitems" (
  "player_id" INTEGER NOT NULL,
  "sid" INTEGER NOT NULL,
  "pid" INTEGER NOT NULL DEFAULT 0,
  "itemtype" INTEGER NOT NULL,
  "count" INTEGER NOT NULL DEFAULT 0,
  "attributes" blob NOT NULL,
  UNIQUE ("player_id", "sid"),
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "player_items" (
  "player_id" INTEGER NOT NULL,
  "pid" INTEGER NOT NULL DEFAULT 0,
  "sid" INTEGER NOT NULL DEFAULT 0,
  "itemtype" INTEGER NOT NULL DEFAULT 0,
  "count" INTEGER NOT NULL DEFAULT 0,
  "attributes" blob NOT NULL,
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE
);
CREATE INDEX "player_items_sid" ON "player_items" ("sid");

CREATE TABLE IF NOT EXISTS "player_spells" (
  "player_id" INTEGER NOT NULL,
  "name" TEXT NOT NULL,
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "player_storage" (
  "player_id" INTEGER NOT NULL DEFAULT 0,
  "key" INTEGER NOT NULL DEFAULT 0,
  "value" INTEGER NOT NULL DEFAULT 0,
  PRIMARY KEY ("player_id", "key"),
  FOREIGN KEY ("player_id") REFERENCES "players" ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS "server_config" (
  "config" TEXT NOT NULL PRIMARY KEY,
  "value" TEXT NOT NULL DEFAULT ''
);

INSERT INTO "server_config" ("config", "value") VALUES ('db_version', '19'), ('motd_hash', ''), ('motd_num', '0'), ('players_record', '0');

CREATE TABLE IF NOT EXISTS "tile_store" (
  "house_id" INTEGER NOT NULL,
  "data" blob NOT NULL,
  FOREIGN KEY ("house_id") REFERENCES "houses" ON DELETE CASCADE
);

DROP TRIGGER IF EXISTS "ondelete_players";
DROP TRIGGER IF EXISTS "oncreate_guilds";

CREATE TRIGGER "ondelete_players" BEFORE DELETE ON "players"
 FOR EACH ROW BEGIN
    UPDATE "houses" SET "owner" = 0 WHERE "owner" = OLD."rowid";
END;

CREATE TRIGGER "oncreate_guilds" AFTER INSERT ON "guilds"
 FOR EACH ROW BEGIN
    INSERT INTO "guild_ranks" ("name", "level", "guild_id") VALUES ('the Leader', 3, NEW."id");
    INSERT INTO "guild_ranks" ("name", "level", "guild_id") VALUES ('a Vice-Leader', 2, NEW."id");
    INSERT INTO "guild_ranks" ("name", "level", "guild_id") VALUES ('a Member', 1, NEW."id");
END;
