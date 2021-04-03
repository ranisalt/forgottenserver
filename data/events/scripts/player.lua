function Player:onBrowseField(position)
	if hasEventCallback(EVENT_CALLBACK_ONBROWSEFIELD) then
		return EventCallback(EVENT_CALLBACK_ONBROWSEFIELD, self, position)
	else
		return true
	end
end

function Player:onLook(thing, position, distance)
	local ret = EventCallback(EVENT_CALLBACK_ONLOOK, self, thing, position, distance)
	self:sendTextMessage(MESSAGE_INFO_DESCR, ret)
end

function Player:onLookInBattleList(creature, distance)
	local ret = EventCallback(EVENT_CALLBACK_ONLOOKINBATTLELIST, self, creature, distance)
	self:sendTextMessage(MESSAGE_INFO_DESCR, ret)
end

function Player:onLookInTrade(partner, item, distance)
	local description = "You see " .. item:getDescription(distance)
	local ret = hasEventCallback(EVENT_CALLBACK_ONLOOKINTRADE) and EventCallback(EVENT_CALLBACK_ONLOOKINTRADE, self, partner, item, distance, description) or description
	self:sendTextMessage(MESSAGE_INFO_DESCR, ret)
end

function Player:onLookInShop(itemType, count, description)
	local description = "You see " .. description
	local ret = hasEventCallback(EVENT_CALLBACK_ONLOOKINSHOP) and EventCallback(EVENT_CALLBACK_ONLOOKINSHOP, self, itemType, count, description) or description
	self:sendTextMessage(MESSAGE_INFO_DESCR, ret)
end

function Player:onMoveItem(item, count, fromPosition, toPosition, fromCylinder, toCylinder)
	if hasEventCallback(EVENT_CALLBACK_ONMOVEITEM) then
		return EventCallback(EVENT_CALLBACK_ONMOVEITEM, self, item, count, fromPosition, toPosition, fromCylinder, toCylinder)
	else
		return true
	end
end

function Player:onItemMoved(item, count, fromPosition, toPosition, fromCylinder, toCylinder)
	if hasEventCallback(EVENT_CALLBACK_ONITEMMOVED) then
		EventCallback(EVENT_CALLBACK_ONITEMMOVED, self, item, count, fromPosition, toPosition, fromCylinder, toCylinder)
	end
end

function Player:onMoveCreature(creature, fromPosition, toPosition)
	if hasEventCallback(EVENT_CALLBACK_ONMOVECREATURE) then
		return EventCallback(EVENT_CALLBACK_ONMOVECREATURE, self, creature, fromPosition, toPosition)
	else
		return true
	end
end

function Player:onReportRuleViolation(targetName, reportType, reportReason, comment, translation)
	if hasEventCallback(EVENT_CALLBACK_ONREPORTRULEVIOLATION) then
		EventCallback(EVENT_CALLBACK_ONREPORTRULEVIOLATION, self, targetName, reportType, reportReason, comment, translation)
	end
end

function Player:onReportBug(message, position, category)
	if hasEventCallback(EVENT_CALLBACK_ONREPORTBUG) then
		return EventCallback(EVENT_CALLBACK_ONREPORTBUG, self, message, position, category)
	else
		return true
	end
end

function Player:onTurn(direction)
	if hasEventCallback(EVENT_CALLBACK_ONTURN) then
		return EventCallback(EVENT_CALLBACK_ONTURN, self, direction)
	else
		return true
	end
end

function Player:onTradeRequest(target, item)
	if hasEventCallback(EVENT_CALLBACK_ONTRADEREQUEST) then
		return EventCallback(EVENT_CALLBACK_ONTRADEREQUEST, self, target, item)
	else
		return true
	end
end

function Player:onTradeAccept(target, item, targetItem)
	if hasEventCallback(EVENT_CALLBACK_ONTRADEACCEPT) then
		return EventCallback(EVENT_CALLBACK_ONTRADEACCEPT, self, target, item, targetItem)
	else
		return true
	end
end

function Player:onTradeCompleted(target, item, targetItem, isSuccess)
	if hasEventCallback(EVENT_CALLBACK_ONTRADECOMPLETED) then
		EventCallback(EVENT_CALLBACK_ONTRADECOMPLETED, self, target, item, targetItem, isSuccess)
	end
end

local soulCondition = Condition(CONDITION_SOUL, CONDITIONID_DEFAULT)
soulCondition:setTicks(4 * 60 * 1000)
soulCondition:setParameter(CONDITION_PARAM_SOULGAIN, 1)

local function useStamina(player)
	local staminaMinutes = player:getStamina()
	if staminaMinutes == 0 then
		return
	end

	local playerId = player:getId()
	local currentTime = os.time()
	local timePassed = currentTime - nextUseStaminaTime[playerId]
	if timePassed <= 0 then
		return
	end

	if timePassed > 60 then
		if staminaMinutes > 2 then
			staminaMinutes = staminaMinutes - 2
		else
			staminaMinutes = 0
		end
		nextUseStaminaTime[playerId] = currentTime + 120
	else
		staminaMinutes = staminaMinutes - 1
		nextUseStaminaTime[playerId] = currentTime + 60
	end
	player:setStamina(staminaMinutes)
end

function Player:onGainExperience(source, exp, rawExp)
	if not source or source:isPlayer() then
		return exp
	end

	-- Soul regeneration
	local vocation = self:getVocation()
	if self:getSoul() < vocation:getMaxSoul() and exp >= self:getLevel() then
		soulCondition:setParameter(CONDITION_PARAM_SOULTICKS, vocation:getSoulGainTicks() * 1000)
		self:addCondition(soulCondition)
	end

	-- Apply experience stage multiplier
	exp = exp * Game.getExperienceStage(self:getLevel())

	-- Stamina modifier
	if configManager.getBoolean(configKeys.STAMINA_SYSTEM) then
		useStamina(self)

		local staminaMinutes = self:getStamina()
		if staminaMinutes > 2400 and self:isPremium() then
			exp = exp * 1.5
		elseif staminaMinutes <= 840 then
			exp = exp * 0.5
		end
	end

	return hasEventCallback(EVENT_CALLBACK_ONGAINEXPERIENCE) and EventCallback(EVENT_CALLBACK_ONGAINEXPERIENCE, self, source, exp, rawExp) or exp
end

function Player:onLoseExperience(exp)
	return hasEventCallback(EVENT_CALLBACK_ONLOSEEXPERIENCE) and EventCallback(EVENT_CALLBACK_ONLOSEEXPERIENCE, self, exp) or exp
end

function Player:onGainSkillTries(skill, tries)
	if APPLY_SKILL_MULTIPLIER == false then
		return hasEventCallback(EVENT_CALLBACK_ONGAINSKILLTRIES) and EventCallback(EVENT_CALLBACK_ONGAINSKILLTRIES, self, skill, tries) or tries
	end

	if skill == SKILL_MAGLEVEL then
		tries = tries * configManager.getNumber(configKeys.RATE_MAGIC)
		return hasEventCallback(EVENT_CALLBACK_ONGAINSKILLTRIES) and EventCallback(EVENT_CALLBACK_ONGAINSKILLTRIES, self, skill, tries) or tries
	end
	tries = tries * configManager.getNumber(configKeys.RATE_SKILL)
	return hasEventCallback(EVENT_CALLBACK_ONGAINSKILLTRIES) and EventCallback(EVENT_CALLBACK_ONGAINSKILLTRIES, self, skill, tries) or tries
end

function Player:onWrapItem(item)
	local topCylinder = item:getTopParent()
	if not topCylinder then
		return
	end

	local tile = Tile(topCylinder:getPosition())
	if not tile then
		return
	end

	local house = tile:getHouse()
	if not house then
		self:sendCancelMessage("You can only wrap and unwrap this item inside a house.")
		return
	end

	if house ~= self:getHouse() and not string.find(house:getAccessList(SUBOWNER_LIST):lower(), "%f[%a]" .. self:getName():lower() .. "%f[%A]") then
		self:sendCancelMessage("You cannot wrap or unwrap items from a house, which you are only guest to.")
		return
	end

	local wrapId = item:getAttribute("wrapid")
	if wrapId == 0 then
		return
	end

	if not hasEventCallback(EVENT_CALLBACK_ONWRAPITEM) or EventCallback(EVENT_CALLBACK_ONWRAPITEM, self, item) then
		local oldId = item:getId()
		item:remove(1)
		local item = tile:addItem(wrapId)
		if item then
			item:setAttribute("wrapid", oldId)
		end
	end
end

local function executeOfflineTraining(player)
	local lastLogout = player:getLastLogout()
	local offlineTime = lastLogout ~= 0 and math.min(os.time() - lastLogout, 86400 * 21) or 0
	local offlineTrainingSkill = player:getOfflineTrainingSkill()
	if offlineTrainingSkill == -1 then
		player:addOfflineTrainingTime(offlineTime * 1000)
		return
	end

	player:setOfflineTrainingSkill(-1)

	if offlineTime < 600 then
		player:sendTextMessage(MESSAGE_EVENT_ADVANCE, "You must be logged out for more than 10 minutes to start offline training.")
		return
	end

	local trainingTime = math.max(0, math.min(offlineTime, math.min(43200, player:getOfflineTrainingTime() / 1000)))
	player:removeOfflineTrainingTime(trainingTime * 1000)

	local remainder = offlineTime - trainingTime
	if remainder > 0 then
		player:addOfflineTrainingTime(remainder * 1000)
	end

	if trainingTime < 60 then
		return
	end

	local text = "During your absence you trained for"
	local hours = math.floor(trainingTime / 3600)
	if hours > 1 then
		text = string.format("%s %d hours", text, hours)
	elseif hours == 1 then
		text = string.format("%s 1 hour", text)
	end

	local minutes = math.floor((trainingTime % 3600) / 60)
	if minutes ~= 0 then
		if hours ~= 0 then
			text = string.format("%s and", text)
		end

		if minutes > 1 then
			text = string.format("%s %d minutes", text, minutes)
		else
			text = string.format("%s 1 minute", text)
		end
	end

	text = string.format("%s.", text)
	player:sendTextMessage(MESSAGE_EVENT_ADVANCE, text)

	local vocation = player:getVocation()
	local promotion = vocation:getPromotion()
	local topVocation = not promotion and vocation or promotion

	local updateSkills = false
	if table.contains({SKILL_CLUB, SKILL_SWORD, SKILL_AXE, SKILL_DISTANCE}, offlineTrainingSkill) then
		local modifier = topVocation:getAttackSpeed() / 1000
		updateSkills = player:addOfflineTrainingTries(offlineTrainingSkill, (trainingTime / modifier) / (offlineTrainingSkill == SKILL_DISTANCE and 4 or 2))
	elseif offlineTrainingSkill == SKILL_MAGLEVEL then
		local gainTicks = topVocation:getManaGainTicks() * 2
		if gainTicks == 0 then
			gainTicks = 1
		end

		updateSkills = player:addOfflineTrainingTries(SKILL_MAGLEVEL, trainingTime * (vocation:getManaGainAmount() / gainTicks))
	end

	if updateSkills then
		player:addOfflineTrainingTries(SKILL_SHIELD, trainingTime / 4)
	end
end

local function executeRegenerateStamina(player)
	nextUseStaminaTime[player.uid] = 0
	if not configManager.getBoolean(configKeys.STAMINA_SYSTEM) then
		return
	end

	local lastLogout = player:getLastLogout()
	local offlineTime = lastLogout ~= 0 and math.min(os.time() - lastLogout, 86400 * 21) or 0
	offlineTime = offlineTime - 600

	if offlineTime < 180 then
		return
	end

	local staminaMinutes = player:getStamina()
	local maxNormalStaminaRegen = 2400 - math.min(2400, staminaMinutes)

	local regainStaminaMinutes = offlineTime / 180
	if regainStaminaMinutes > maxNormalStaminaRegen then
		local happyHourStaminaRegen = (offlineTime - (maxNormalStaminaRegen * 180)) / 600
		staminaMinutes = math.min(2520, math.max(2400, staminaMinutes) + happyHourStaminaRegen)
	else
		staminaMinutes = staminaMinutes + regainStaminaMinutes
	end

	player:setStamina(staminaMinutes)
end

local firstItems = {2050, 2382}

function Player:onLogin()
	local loginStr = "Welcome to " .. configManager.getString(configKeys.SERVER_NAME) .. "!"
	if self:getLastLoginSaved() <= 0 then
		-- First items
		for i = 1, #firstItems do
			self:addItem(firstItems[i], 1)
		end
		self:addItem(self:getSex() == 0 and 2651 or 2650, 1)
		self:addItem(ITEM_BAG, 1):addItem(2674, 1)

		loginStr = loginStr .. " Please choose your outfit."
		self:sendOutfitWindow()
	else
		if loginStr ~= "" then
			self:sendTextMessage(MESSAGE_STATUS_DEFAULT, loginStr)
		end

		loginStr = string.format("Your last visit was on %s.", os.date("%a %b %d %X %Y", self:getLastLoginSaved()))
	end
	self:sendTextMessage(MESSAGE_STATUS_DEFAULT, loginStr)

	-- Promotion
	local vocation = self:getVocation()
	local promotion = vocation:getPromotion()
	if self:isPremium() then
		local value = self:getStorageValue(PlayerStorageKeys.promotion)
		if not promotion and value ~= 1 then
			self:setStorageValue(PlayerStorageKeys.promotion, 1)
		elseif value == 1 then
			self:setVocation(promotion)
		end
	elseif not promotion then
		self:setVocation(vocation:getDemotion())
	end

	executeOfflineTraining(self)
	executeRegenerateStamina(self)

	-- Events
	self:registerEvent("PlayerDeath")
	self:registerEvent("DropLoot")
	return true
end

function Player:onLogout()
	local playerId = self:getId()
	if nextUseStaminaTime[playerId] then
		nextUseStaminaTime[playerId] = nil
	end
	return true
end
