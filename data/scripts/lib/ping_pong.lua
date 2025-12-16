function Player.getLastPing(self)
  return self:getStorageValue(PlayerStorageKeys.lastPing) or 0
end

function Player.setLastPing(self, time)
  self:setStorageValue(PlayerStorageKeys.lastPing, time)
end

function Player.getLastPong(self)
  return self:getStorageValue(PlayerStorageKeys.lastPong) or 0
end

function Player.setLastPong(self, time)
  self:setStorageValue(PlayerStorageKeys.lastPong, time)
end
