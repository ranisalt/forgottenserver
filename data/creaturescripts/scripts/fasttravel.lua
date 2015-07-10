local cooldown = 15 * 1000
local message = "You arrived at %s."

function Player:locationWindowChoice(windowId, buttonId, choiceId)
	if buttonId == 1 then
		local system = travelSystems[windowId]
		local location = system.locations[choiceId]
		local destiny = Position(location.pos)
		self:teleportTo(destiny)
		self:sendTextMessage(MESSAGE_EVENT_ADVANCE, string.format(message, location.name))
		self:setStorageValue(windowId, os.time() + system.cooldown)
		destiny:sendMagicEffect(CONST_ME_TELEPORT)
		return true
	end
	return false
end

function onModalWindow(player, modalWindowId, buttonId, choiceId)
	player:locationWindowChoice(modalWindowId, buttonId, choiceId)
	return true
end
