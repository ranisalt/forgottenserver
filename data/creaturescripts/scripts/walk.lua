local message = "You have discovered %s."

local function positionInRange(this, that)
	local xdelta, ydelta = math.abs(this.x - that.x), math.abs(this.y - that.y)

	-- viewport radius is 7 tiles wide, 5 tiles tall
	return xdelta < 7 and ydelta < 5 and this.z == that.z
end

function onWalk(player, position)
	for storage, place in pairs(locations) do
		if player:getStorageValue(storage) == -1 and  positionInRange(position, place.pos) then

			player:sendTextMessage(MESSAGE_EVENT_ADVANCE, string.format(message, place.name))
			player:setStorageValue(storage, 1)

			if place.mapmark then
				player:addMapMark(place.pos, place.mapmark, place.name)
			end

			break
		end
	end
	return true
end
