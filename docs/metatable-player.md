The Player metatable contains all of the methods that handle/require players.  

Creating an instance of the Player metatable (2 options):
```Lua
local player = Player(uid)
local player = Player(name or wildcard)
```
###Available methods:
[addBlessing(blessing)](#addBlessing{blessing})  
[addExperience(experience[, sendText = false])](#addExperience{experience[, sendText = false]})  
[addItem(itemId[, count = 1[, canDropOnMap = true[, subType = 1[, slot = CONST_SLOT_WHEREEVER]]]])](#addItem{itemId[, count = 1[, canDropOnMap = true[, subType = 1[, slot = CONST_SLOT_WHEREEVER]]]]})  
[addItemEx(item[, canDropOnMap = false[, index = INDEX_WHEREEVER[, flags = 0]]])](#addItemEx{item[, canDropOnMap = false[, index = INDEX_WHEREEVER[, flags = 0]]]})  
[addItemEx(item[, canDropOnMap = true[, slot = CONST_SLOT_WHEREEVER]])](#addItemEx{item[, canDropOnMap = true[, slot = CONST_SLOT_WHEREEVER]]})  
[addManaSpent(amount)](#addManaSpent{amount})  
[addMapMark(position, type, description)](#addMapMark{position, type, description})  
[addMoney(money)](#addMoney{money})  
[addMount(mountId)](#addMount{mountId})  
[addOutfit(lookType)](#addOutfit{lookType})  
[addOutfitAddon(lookType, addon)](#addOutfitAddon{lookType, addon})  
[addPremiumDays(days)](#addPremiumDays{days})  
[addSkillTries(skillType, tries)](#addSkillTries{skillType, tries})  
[addSoul(soulChange)](#addSoul{soulChange})  
[canLearnSpell(spellName)](#canLearnSpell{spellName})  
[channelSay(speaker, type, text, channelId)](#channelSay{speaker, type, text, channelId})  
[forgetSpell(spellName)](#forgetSpell{spellName})  
[getAccountId()](#getAccountId{})  
[getAccountType()](#getAccountType{})  
[getBankBalance()](#getBankBalance{})  
[getBaseMagicLevel()](#getBaseMagicLevel{})  
[getCapacity()](#getCapacity{})  
[getClient()](#getClient{})  
[getContainerById(id)](#getContainerById{id})  
[getContainerId(container)](#getContainerId{container})  
[getContainerIndex(id)](#getContainerIndex{id})  
[getDeathPenalty()](#getDeathPenalty{})  
[getDepotChest(depotId[, autoCreate = false])](#getDepotChest{depotId[, autoCreate = false]})  
[getEffectiveSkillLevel(skillType)](#getEffectiveSkillLevel{skillType})  
[getExperience()](#getExperience{})  
[getFreeCapacity()](#getFreeCapacity{})  
[getGroup()](#getGroup{})  
[getGuid()](#getGuid{})  
[getGuild()](#getGuild{})  
[getGuildLevel()](#getGuildLevel{})  
[getGuildNick()](#getGuildNick{})  
[getHouse()](#getHouse{})  
[getInbox()](#getInbox{})  
[getIp()](#getIp{})  
[getItemById(itemId, deepSearch[, subType = -1])](#getItemById{itemId, deepSearch[, subType = -1]})  
[getItemCount(itemId[, subType = -1])](#getItemCount{itemId[, subType = -1]})  
[getLastLoginSaved()](#getLastLoginSaved{})  
[getLastLogout()](#getLastLogout{})  
[getLevel()](#getLevel{})  
[getMagicLevel()](#getMagicLevel{})  
[getManaSpent()](#getManaSpent{})  
[getMaxSoul()](#getMaxSoul{})  
[getMoney()](#getMoney{})  
[getParty()](#getParty{})  
[getPremiumDays()](#getPremiumDays{})  
[getSex()](#getSex{})  
[getSkillLevel(skillType)](#getSkillLevel{skillType})  
[getSkillPercent(skillType)](#getSkillPercent{skillType})  
[getSkillTries(skillType)](#getSkillTries{skillType})  
[getSkullTime()](#getSkullTime{})  
[getSlotItem(slot)](#getSlotItem{slot})  
[getSoul()](#getSoul{})  
[getStamina()](#getStamina{})  
[getStorageValue(key)](#getStorageValue{key})  
[getTown()](#getTown{})  
[getVocation()](#getVocation{})  
[hasBlessing(blessing)](#hasBlessing{blessing})  
[hasLearnedSpell(spellName)](#hasLearnedSpell{spellName})  
[hasMount(mountId)](#hasMount{mountId})  
[hasOutfit(lookType[, addon = 0])](#hasOutfit{lookType[, addon = 0]})  
[isPlayer()](#isPlayer{})  
[isPzLocked()](#isPzLocked{})  
[learnSpell(spellName)](#learnSpell{spellName})  
[openChannel(channelId)](#openChannel{channelId})  
[popupFYI(message)](#popupFYI{message})  
[removeBlessing(blessing)](#removeBlessing{blessing})  
[removeExperience(experience[, sendText = false])](#removeExperience{experience[, sendText = false]})  
[removeItem(itemId, count[, subType = -1[, ignoreEquipped = false]])](#removeItem{itemId, count[, subType = -1[, ignoreEquipped = false]]})  
[removeMoney(money)](#removeMoney{money})  
[removeMount(mountId)](#removeMount{mountId})  
[removeOutfit(lookType)](#removeOutfit{lookType})  
[removeOutfitAddon(lookType, addon)](#removeOutfitAddon{lookType, addon})  
[removePremiumDays(days)](#removePremiumDays{days})  
[save()](#save{})  
[sendChannelMessage(author, text, type, channelId)](#sendChannelMessage{author, text, type, channelId})  
[sendOutfitWindow()](#sendOutfitWindow{})  
[sendPrivateMessage(speaker, text[, type])](#sendPrivateMessage{speaker, text[, type]})  
[sendTextMessage(type, text[, position, primaryValue = 0, primaryColor = TEXTCOLOR_NONE[, secondaryValue = 0, secondaryColor = TEXTCOLOR_NONE]])](#sendTextMessage{type, text[, position, primaryValue = 0, primaryColor = TEXTCOLOR_NONE[, secondaryValue = 0, secondaryColor = TEXTCOLOR_NONE]]})  
[sendTutorial(tutorialId)](#sendTutorial{tutorialId})  
[setAccountType(accountType)](#setAccountType{accountType})  
[setBankBalance(bankBalance)](#setBankBalance{bankBalance})  
[setCapacity(capacity)](#setCapacity{capacity})  
[setGhostMode(enabled)](#setGhostMode{enabled})  
[setGroup(group)](#setGroup{group})  
[setGuild(guild)](#setGuild{guild})  
[setGuildLevel(level)](#setGuildLevel{level})  
[setGuildNick(nick)](#setGuildNick{nick})  
[setMaxMana(maxMana)](#setMaxMana{maxMana})  
[setSex(newSex)](#setSex{newSex})  
[setSkullTime(skullTime)](#setSkullTime{skullTime})  
[setStamina(stamina)](#setStamina{stamina})  
[setStorageValue(key, value)](#setStorageValue{key, value})  
[setTown(town)](#setTown{town})  
[setVocation(vocation)](#setVocation{vocation})  
[showTextDialog(itemId[, text[, canWrite[, length]]])](#showTextDialog{itemId[, text[, canWrite[, length]]]})  


***

<a name="addBlessing{blessing}"/>
###### addBlessing(blessing)
> **Description:** N/A  
> **Parameters:** <ul><li>_blessing_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addBlessing(1)
```
> **Added in version:** 1.0

***

<a name="addExperience{experience[, sendText = false]}"/>
###### addExperience(experience[, sendText = false])
> **Description:** N/A  
> **Parameters:** <ul><li>_experience_ - _No description_</li><li>_sendText_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addExperience(100, false)
```
> **Added in version:** 1.0

***

<a name="addItem{itemId[, count = 1[, canDropOnMap = true[, subType = 1[, slot = CONST_SLOT_WHEREEVER]]]]}"/>
###### addItem(itemId[, count = 1[, canDropOnMap = true[, subType = 1[, slot = CONST_SLOT_WHEREEVER]]]])
> **Description:** This function gives the player a newly created item.  
> **Parameters:** <ul><li>_itemId_ - _Type of item created._</li><li>_count_ - _How many items that are created. (optional, default = 1)_</li><li>_canDropOnMap_ - _Drops any remaining items on the map. (optional, default: true)_</li><li>_subType_ - _Subtype the item(s) should have. (optional, default: 1)_</li><li>_slot_ - _Slot the item should be assigned to. (optional, default: CONST_SLOT_WHEREEVER)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addItem(2400, 1, true, 1, CONST_SLOT_WHEREEVER)
```
> **Added in version:** 1.0

***

<a name="addItemEx{item[, canDropOnMap = false[, index = INDEX_WHEREEVER[, flags = 0]]]}"/>
###### addItemEx(item[, canDropOnMap = false[, index = INDEX_WHEREEVER[, flags = 0]]])
> **Description:** N/A  
> **Parameters:** <ul><li>_item_ - _No description_</li><li>_canDropOnMap_ - _(optional, default: false)_</li><li>_index_ - _(optional, default: INDEX_WHEREEVER)_</li><li>_flags_ - _(optional, default: 0)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addItemEx(some_userdata, false, INDEX_WHEREEVER, 0)
```
> **Added in version:** 1.0

***

<a name="addItemEx{item[, canDropOnMap = true[, slot = CONST_SLOT_WHEREEVER]]}"/>
###### addItemEx(item[, canDropOnMap = true[, slot = CONST_SLOT_WHEREEVER]])
> **Description:** N/A  
> **Parameters:** <ul><li>_item_ - _No description_</li><li>_canDropOnMap_ - _(optional, default: true)_</li><li>_slot_ - _(optional, default: CONST_SLOT_WHEREEVER)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addItemEx(some_userdata, true, CONST_SLOT_WHEREEVER)
```
> **Added in version:** 1.0

***

<a name="addManaSpent{amount}"/>
###### addManaSpent(amount)
> **Description:** N/A  
> **Parameters:** <ul><li>_amount_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addManaSpent(100)
```
> **Added in version:** 1.0

***

<a name="addMapMark{position, type, description}"/>
###### addMapMark(position, type, description)
> **Description:** N/A  
> **Parameters:** <ul><li>_position_ - _No description_</li><li>_type_ - _No description_</li><li>_description_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addMapMark(Position(), MAPMARK_LOCK, any_string)
```
> **Added in version:** 1.0

***

<a name="addMoney{money}"/>
###### addMoney(money)
> **Description:** N/A  
> **Parameters:** <ul><li>_money_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addMoney(100)
```
> **Added in version:** 1.0

***

<a name="addMount{mountId}"/>
###### addMount(mountId)
> **Description:** N/A  
> **Parameters:** <ul><li>_mountId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addMount(unknown)
```
> **Added in version:** 1.0

***

<a name="addOutfit{lookType}"/>
###### addOutfit(lookType)
> **Description:** N/A  
> **Parameters:** <ul><li>_lookType_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addOutfit(128)
```
> **Added in version:** 1.0

***

<a name="addOutfitAddon{lookType, addon}"/>
###### addOutfitAddon(lookType, addon)
> **Description:** N/A  
> **Parameters:** <ul><li>_lookType_ - _No description_</li><li>_addon_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addOutfitAddon(128, 2)
```
> **Added in version:** 1.0

***

<a name="addPremiumDays{days}"/>
###### addPremiumDays(days)
> **Description:** N/A  
> **Parameters:** <ul><li>_days_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addPremiumDays(1)
```
> **Added in version:** 1.0

***

<a name="addSkillTries{skillType, tries}"/>
###### addSkillTries(skillType, tries)
> **Description:** N/A  
> **Parameters:** <ul><li>_skillType_ - _No description_</li><li>_tries_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addSkillTries(SKILL_FIST, 10)
```
> **Added in version:** 1.0

***

<a name="addSoul{soulChange}"/>
###### addSoul(soulChange)
> **Description:** N/A  
> **Parameters:** <ul><li>_soulChange_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:addSoul(1)
```
> **Added in version:** 1.0

***

<a name="canLearnSpell{spellName}"/>
###### canLearnSpell(spellName)
> **Description:** N/A  
> **Parameters:** <ul><li>_spellName_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:canLearnSpell(unknown)
```
> **Added in version:** 1.0

***

<a name="channelSay{speaker, type, text, channelId}"/>
###### channelSay(speaker, type, text, channelId)
> **Description:** N/A  
> **Parameters:** <ul><li>_speaker_ - _No description_</li><li>_type_ - _No description_</li><li>_text_ - _No description_</li><li>_channelId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:channelSay(some_userdata, TALKTYPE_SAY, any_string, unknown)
```
> **Added in version:** 1.0

***

<a name="forgetSpell{spellName}"/>
###### forgetSpell(spellName)
> **Description:** N/A  
> **Parameters:** <ul><li>_spellName_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:forgetSpell(unknown)
```
> **Added in version:** 1.0

***

<a name="getAccountId{}"/>
###### getAccountId()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getAccountId()
```
> **Added in version:** 1.0

***

<a name="getAccountType{}"/>
###### getAccountType()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getAccountType()
```
> **Added in version:** 1.0

***

<a name="getBankBalance{}"/>
###### getBankBalance()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getBankBalance()
```
> **Added in version:** 1.0

***

<a name="getBaseMagicLevel{}"/>
###### getBaseMagicLevel()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getBaseMagicLevel()
```
> **Added in version:** 1.0

***

<a name="getCapacity{}"/>
###### getCapacity()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getCapacity()
```
> **Added in version:** 1.0

***

<a name="getClient{}"/>
###### getClient()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getClient()
```
> **Added in version:** 1.0

***

<a name="getContainerById{id}"/>
###### getContainerById(id)
> **Description:** N/A  
> **Parameters:** <ul><li>_id_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getContainerById(some_id)
```
> **Added in version:** 1.0

***

<a name="getContainerId{container}"/>
###### getContainerId(container)
> **Description:** N/A  
> **Parameters:** <ul><li>_container_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getContainerId(some_userdata)
```
> **Added in version:** 1.0

***

<a name="getContainerIndex{id}"/>
###### getContainerIndex(id)
> **Description:** N/A  
> **Parameters:** <ul><li>_id_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getContainerIndex(some_id)
```
> **Added in version:** 1.0

***

<a name="getDeathPenalty{}"/>
###### getDeathPenalty()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getDeathPenalty()
```
> **Added in version:** 1.0

***

<a name="getDepotChest{depotId[, autoCreate = false]}"/>
###### getDepotChest(depotId[, autoCreate = false])
> **Description:** N/A  
> **Parameters:** <ul><li>_depotId_ - _No description_</li><li>_autoCreate_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getDepotChest(0, false)
```
> **Added in version:** 1.0

***

<a name="getEffectiveSkillLevel{skillType}"/>
###### getEffectiveSkillLevel(skillType)
> **Description:** N/A  
> **Parameters:** <ul><li>_skillType_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getEffectiveSkillLevel(SKILL_FIST)
```
> **Added in version:** 1.0

***

<a name="getExperience{}"/>
###### getExperience()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getExperience()
```
> **Added in version:** 1.0

***

<a name="getFreeCapacity{}"/>
###### getFreeCapacity()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getFreeCapacity()
```
> **Added in version:** 1.0

***

<a name="getGroup{}"/>
###### getGroup()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getGroup()
```
> **Added in version:** 1.0

***

<a name="getGuid{}"/>
###### getGuid()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getGuid()
```
> **Added in version:** 1.0

***

<a name="getGuild{}"/>
###### getGuild()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getGuild()
```
> **Added in version:** 1.0

***

<a name="getGuildLevel{}"/>
###### getGuildLevel()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getGuildLevel()
```
> **Added in version:** 1.0

***

<a name="getGuildNick{}"/>
###### getGuildNick()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getGuildNick()
```
> **Added in version:** 1.0

***

<a name="getHouse{}"/>
###### getHouse()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getHouse()
```
> **Added in version:** 1.0

***

<a name="getInbox{}"/>
###### getInbox()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getInbox()
```
> **Added in version:** 1.0

***

<a name="getIp{}"/>
###### getIp()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getIp()
```
> **Added in version:** 1.0

***

<a name="getItemById{itemId, deepSearch[, subType = -1]}"/>
###### getItemById(itemId, deepSearch[, subType = -1])
> **Description:** N/A  
> **Parameters:** <ul><li>_itemId_ - _No description_</li><li>_deepSearch_ - _No description_</li><li>_subType_ - _(optional, default: -1)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getItemById(2400, false, -1)
```
> **Added in version:** 1.0

***

<a name="getItemCount{itemId[, subType = -1]}"/>
###### getItemCount(itemId[, subType = -1])
> **Description:** N/A  
> **Parameters:** <ul><li>_itemId_ - _No description_</li><li>_subType_ - _(optional, default: -1)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getItemCount(2400, -1)
```
> **Added in version:** 1.0

***

<a name="getLastLoginSaved{}"/>
###### getLastLoginSaved()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getLastLoginSaved()
```
> **Added in version:** 1.0

***

<a name="getLastLogout{}"/>
###### getLastLogout()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getLastLogout()
```
> **Added in version:** 1.1

***

<a name="getLevel{}"/>
###### getLevel()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getLevel()
```
> **Added in version:** 1.0

***

<a name="getMagicLevel{}"/>
###### getMagicLevel()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getMagicLevel()
```
> **Added in version:** 1.0

***

<a name="getManaSpent{}"/>
###### getManaSpent()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getManaSpent()
```
> **Added in version:** 1.0

***

<a name="getMaxSoul{}"/>
###### getMaxSoul()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getMaxSoul()
```
> **Added in version:** 1.0

***

<a name="getMoney{}"/>
###### getMoney()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getMoney()
```
> **Added in version:** 1.0

***

<a name="getParty{}"/>
###### getParty()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getParty()
```
> **Added in version:** 1.0

***

<a name="getPremiumDays{}"/>
###### getPremiumDays()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getPremiumDays()
```
> **Added in version:** 1.0

***

<a name="getSex{}"/>
###### getSex()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getSex()
```
> **Added in version:** 1.0

***

<a name="getSkillLevel{skillType}"/>
###### getSkillLevel(skillType)
> **Description:** N/A  
> **Parameters:** <ul><li>_skillType_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getSkillLevel(SKILL_FIST)
```
> **Added in version:** 1.0

***

<a name="getSkillPercent{skillType}"/>
###### getSkillPercent(skillType)
> **Description:** N/A  
> **Parameters:** <ul><li>_skillType_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getSkillPercent(SKILL_FIST)
```
> **Added in version:** 1.0

***

<a name="getSkillTries{skillType}"/>
###### getSkillTries(skillType)
> **Description:** N/A  
> **Parameters:** <ul><li>_skillType_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getSkillTries(SKILL_FIST)
```
> **Added in version:** 1.0

***

<a name="getSkullTime{}"/>
###### getSkullTime()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getSkullTime()
```
> **Added in version:** 1.0

***

<a name="getSlotItem{slot}"/>
###### getSlotItem(slot)
> **Description:** N/A  
> **Parameters:** <ul><li>_slot_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getSlotItem(CONST_SLOT_LEFT)
```
> **Added in version:** 1.0

***

<a name="getSoul{}"/>
###### getSoul()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getSoul()
```
> **Added in version:** 1.0

***

<a name="getStamina{}"/>
###### getStamina()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getStamina()
```
> **Added in version:** 1.0

***

<a name="getStorageValue{key}"/>
###### getStorageValue(key)
> **Description:** N/A  
> **Parameters:** <ul><li>_key_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getStorageValue(1000)
```
> **Added in version:** 1.0

***

<a name="getTown{}"/>
###### getTown()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getTown()
```
> **Added in version:** 1.0

***

<a name="getVocation{}"/>
###### getVocation()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:getVocation()
```
> **Added in version:** 1.0

***

<a name="hasBlessing{blessing}"/>
###### hasBlessing(blessing)
> **Description:** N/A  
> **Parameters:** <ul><li>_blessing_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:hasBlessing(1)
```
> **Added in version:** 1.0

***

<a name="hasLearnedSpell{spellName}"/>
###### hasLearnedSpell(spellName)
> **Description:** N/A  
> **Parameters:** <ul><li>_spellName_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:hasLearnedSpell(unknown)
```
> **Added in version:** 1.0

***

<a name="hasMount{mountId}"/>
###### hasMount(mountId)
> **Description:** N/A  
> **Parameters:** <ul><li>_mountId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:hasMount(unknown)
```
> **Added in version:** 1.0

***

<a name="hasOutfit{lookType[, addon = 0]}"/>
###### hasOutfit(lookType[, addon = 0])
> **Description:** N/A  
> **Parameters:** <ul><li>_lookType_ - _No description_</li><li>_addon_ - _(optional, default: 0)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:hasOutfit(128, 0)
```
> **Added in version:** 1.0

***

<a name="isPlayer{}"/>
###### isPlayer()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:isPlayer()
```
> **Added in version:** 1.0

***

<a name="isPzLocked{}"/>
###### isPzLocked()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:isPzLocked()
```
> **Added in version:** 1.0

***

<a name="learnSpell{spellName}"/>
###### learnSpell(spellName)
> **Description:** N/A  
> **Parameters:** <ul><li>_spellName_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:learnSpell(unknown)
```
> **Added in version:** 1.0

***

<a name="openChannel{channelId}"/>
###### openChannel(channelId)
> **Description:** N/A  
> **Parameters:** <ul><li>_channelId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:openChannel(unknown)
```
> **Added in version:** 1.0

***

<a name="popupFYI{message}"/>
###### popupFYI(message)
> **Description:** N/A  
> **Parameters:** <ul><li>_message_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:popupFYI(any_string)
```
> **Added in version:** 1.0

***

<a name="removeBlessing{blessing}"/>
###### removeBlessing(blessing)
> **Description:** N/A  
> **Parameters:** <ul><li>_blessing_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:removeBlessing(1)
```
> **Added in version:** 1.0

***

<a name="removeExperience{experience[, sendText = false]}"/>
###### removeExperience(experience[, sendText = false])
> **Description:** N/A  
> **Parameters:** <ul><li>_experience_ - _No description_</li><li>_sendText_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:removeExperience(100, false)
```
> **Added in version:** 1.0

***

<a name="removeItem{itemId, count[, subType = -1[, ignoreEquipped = false]]}"/>
###### removeItem(itemId, count[, subType = -1[, ignoreEquipped = false]])
> **Description:** N/A  
> **Parameters:** <ul><li>_itemId_ - _No description_</li><li>_count_ - _No description_</li><li>_subType_ - _(optional, default: -1)_</li><li>_ignoreEquipped_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:removeItem(2400, 1, -1, false)
```
> **Added in version:** 1.0

***

<a name="removeMoney{money}"/>
###### removeMoney(money)
> **Description:** N/A  
> **Parameters:** <ul><li>_money_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:removeMoney(100)
```
> **Added in version:** 1.0

***

<a name="removeMount{mountId}"/>
###### removeMount(mountId)
> **Description:** N/A  
> **Parameters:** <ul><li>_mountId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:removeMount(unknown)
```
> **Added in version:** 1.0

***

<a name="removeOutfit{lookType}"/>
###### removeOutfit(lookType)
> **Description:** N/A  
> **Parameters:** <ul><li>_lookType_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:removeOutfit(128)
```
> **Added in version:** 1.0

***

<a name="removeOutfitAddon{lookType, addon}"/>
###### removeOutfitAddon(lookType, addon)
> **Description:** N/A  
> **Parameters:** <ul><li>_lookType_ - _No description_</li><li>_addon_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:removeOutfitAddon(128, 2)
```
> **Added in version:** 1.0

***

<a name="removePremiumDays{days}"/>
###### removePremiumDays(days)
> **Description:** N/A  
> **Parameters:** <ul><li>_days_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:removePremiumDays(1)
```
> **Added in version:** 1.0

***

<a name="save{}"/>
###### save()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:save()
```
> **Added in version:** 1.0

***

<a name="sendChannelMessage{author, text, type, channelId}"/>
###### sendChannelMessage(author, text, type, channelId)
> **Description:** N/A  
> **Parameters:** <ul><li>_author_ - _No description_</li><li>_text_ - _No description_</li><li>_type_ - _No description_</li><li>_channelId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:sendChannelMessage(some_name, any_string, TALKTYPE_SAY, unknown)
```
> **Added in version:** 1.0

***

<a name="sendOutfitWindow{}"/>
###### sendOutfitWindow()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:sendOutfitWindow()
```
> **Added in version:** 1.0

***

<a name="sendPrivateMessage{speaker, text[, type]}"/>
###### sendPrivateMessage(speaker, text[, type])
> **Description:** N/A  
> **Parameters:** <ul><li>_speaker_ - _No description_</li><li>_text_ - _No description_</li><li>_type_ - _(optional)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:sendPrivateMessage(some_userdata, any_string, nil)
```
> **Added in version:** 1.0

***

<a name="sendTextMessage{type, text[, position, primaryValue = 0, primaryColor = TEXTCOLOR_NONE[, secondaryValue = 0, secondaryColor = TEXTCOLOR_NONE]]}"/>
###### sendTextMessage(type, text[, position, primaryValue = 0, primaryColor = TEXTCOLOR_NONE[, secondaryValue = 0, secondaryColor = TEXTCOLOR_NONE]])
> **Description:** N/A  
> **Parameters:** <ul><li>_type_ - _No description_</li><li>_text_ - _No description_</li><li>_position_ - _(optional)_</li><li>_primaryValue_ - _(optional, default: 0)_</li><li>_primaryColor_ - _(optional, default: TEXTCOLOR_NONE)_</li><li>_secondaryValue_ - _(optional, default: 0)_</li><li>_secondaryColor_ - _(optional, default: TEXTCOLOR_NONE)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:sendTextMessage(MESSAGE_STATUS_WARNING, any_string, nil, 0, TEXTCOLOR_NONE, 0, TEXTCOLOR_NONE)
```
> **Added in version:** 1.0

***

<a name="sendTutorial{tutorialId}"/>
###### sendTutorial(tutorialId)
> **Description:** N/A  
> **Parameters:** <ul><li>_tutorialId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:sendTutorial(unknown)
```
> **Added in version:** 1.0

***

<a name="setAccountType{accountType}"/>
###### setAccountType(accountType)
> **Description:** N/A  
> **Parameters:** <ul><li>_accountType_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setAccountType(ACCOUNT_TYPE_GOD)
```
> **Added in version:** 1.0

***

<a name="setBankBalance{bankBalance}"/>
###### setBankBalance(bankBalance)
> **Description:** N/A  
> **Parameters:** <ul><li>_bankBalance_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setBankBalance(100)
```
> **Added in version:** 1.0

***

<a name="setCapacity{capacity}"/>
###### setCapacity(capacity)
> **Description:** N/A  
> **Parameters:** <ul><li>_capacity_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setCapacity(15000)
```
> **Added in version:** 1.0

***

<a name="setGhostMode{enabled}"/>
###### setGhostMode(enabled)
> **Description:** N/A  
> **Parameters:** <ul><li>_enabled_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setGhostMode(true)
```
> **Added in version:** 1.0

***

<a name="setGroup{group}"/>
###### setGroup(group)
> **Description:** N/A  
> **Parameters:** <ul><li>_group_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setGroup(some_userdata)
```
> **Added in version:** 1.0

***

<a name="setGuild{guild}"/>
###### setGuild(guild)
> **Description:** N/A  
> **Parameters:** <ul><li>_guild_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setGuild(some_userdata)
```
> **Added in version:** 1.0

***

<a name="setGuildLevel{level}"/>
###### setGuildLevel(level)
> **Description:** N/A  
> **Parameters:** <ul><li>_level_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setGuildLevel(1)
```
> **Added in version:** 1.0

***

<a name="setGuildNick{nick}"/>
###### setGuildNick(nick)
> **Description:** N/A  
> **Parameters:** <ul><li>_nick_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setGuildNick(some_name)
```
> **Added in version:** 1.0

***

<a name="setMaxMana{maxMana}"/>
###### setMaxMana(maxMana)
> **Description:** N/A  
> **Parameters:** <ul><li>_maxMana_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setMaxMana(35)
```
> **Added in version:** 1.0

***

<a name="setSex{newSex}"/>
###### setSex(newSex)
> **Description:** N/A  
> **Parameters:** <ul><li>_newSex_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setSex(PLAYERSEX_MALE)
```
> **Added in version:** 1.0

***

<a name="setSkullTime{skullTime}"/>
###### setSkullTime(skullTime)
> **Description:** N/A  
> **Parameters:** <ul><li>_skullTime_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setSkullTime(unknown)
```
> **Added in version:** 1.0

***

<a name="setStamina{stamina}"/>
###### setStamina(stamina)
> **Description:** N/A  
> **Parameters:** <ul><li>_stamina_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setStamina(50)
```
> **Added in version:** 1.0

***

<a name="setStorageValue{key, value}"/>
###### setStorageValue(key, value)
> **Description:** N/A  
> **Parameters:** <ul><li>_key_ - _No description_</li><li>_value_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setStorageValue(1000, any_number)
```
> **Added in version:** 1.0

***

<a name="setTown{town}"/>
###### setTown(town)
> **Description:** N/A  
> **Parameters:** <ul><li>_town_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setTown(Town(0))
```
> **Added in version:** 1.0

***

<a name="setVocation{vocation}"/>
###### setVocation(vocation)
> **Description:** N/A  
> **Parameters:** <ul><li>_vocation_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:setVocation(some_userdata)
```
> **Added in version:** 1.0

***

<a name="showTextDialog{itemId[, text[, canWrite[, length]]]}"/>
###### showTextDialog(itemId[, text[, canWrite[, length]]])
> **Description:** N/A  
> **Parameters:** <ul><li>_itemId_ - _No description_</li><li>_text_ - _(optional)_</li><li>_canWrite_ - _(optional)_</li><li>_length_ - _(optional)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local player = Player(...)
player:showTextDialog(2400, nil, nil, nil)
```
> **Added in version:** 1.0