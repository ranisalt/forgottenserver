local LAST_PING_STORAGE = 7464
local LAST_PONG_STORAGE = 7664

function Player.getLastPing(self)
  return self:getStorageValue(LAST_PING_STORAGE) or 0
end

function Player.setLastPing(self, time)
  self:setStorageValue(LAST_PING_STORAGE, time)
end

function Player.getLastPong(self)
  return self:getStorageValue(LAST_PONG_STORAGE) or 0
end

function Player.setLastPong(self, time)
  self:setStorageValue(LAST_PONG_STORAGE, time)
end
