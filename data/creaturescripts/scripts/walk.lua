local message = "You have discovered %s."

local function positionInRange(this, that)
	xdelta, ydelta = math.abs(this.x - that.x), math.abs(this.y - that.y)

	-- viewport radius is 7 tiles wide, 5 tiles tall
	return xdelta < 7 and ydelta < 5 and this.z == that.z
end

function onWalk(player, position)
	-- onWalk only discovers places reachable by caravan
	for i = 1, #caravanLocations do
		local location = caravanLocations[i]
		if player:getStorageValue(location.storage) == -1 then
			if positionInRange(position, location.pos) then
				player:sendTextMessage(MESSAGE_EVENT_ADVANCE, string.format(message, location.name))
				player:setStorageValue(location.storage, 1)

				if location.mapmark then
					player:addMapMark(location.pos, location.mapmark, location.name)
				end

				break
			end
		end
	end
	return true
end
