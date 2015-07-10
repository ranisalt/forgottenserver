function onUse(player, item, fromPosition, target, toPosition, isHotkey)
	if player:getStorageValue(caravanWindowId) > os.time() then
		player:sendTextMessage(MESSAGE_STATUS_SMALL, "You have to wait before traveling again.")
	elseif getCreatureCondition(player, CONDITION_INFIGHT) then
		player:sendTextMessage(MESSAGE_STATUS_SMALL, "You cannot fast travel while in combat.")
	elseif player:getSkullTime() > 0 then
		player:sendTextMessage(MESSAGE_STATUS_SMALL, "You cannot fast travel while you have frags.")
	else
		player:sendLocationWindow(caravanWindowId)
	end
	return true
end
