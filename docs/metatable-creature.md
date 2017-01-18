The Creature metatable contains all of the methods that handle/require creatures.  
This metatable is also <u>inherited</u> by the [Player](Metatable:Player.md), [Monster](Metatable:Monster.md) and [Npc](Metatable:Npc.md) metatables, therefore they can use these Creature methods.  

Creating an instance of the Creature metatable (2 options):
```Lua
local creature = Creature(uid)
local creature = Creature(name)
```
###Available methods:
[addCondition(condition[, force = false])](#addCondition{condition[, force = false]})  
[addHealth(healthChange)](#addHealth{healthChange})  
[addMana(manaChange[, animationOnLoss = false])](#addMana{manaChange[, animationOnLoss = false]})  
[canSee(position)](#canSee{position})  
[canSeeCreature(creature)](#canSeeCreature{creature})  
[changeSpeed(delta)](#changeSpeed{delta})  
[getBaseSpeed()](#getBaseSpeed{})  
[getCondition(conditionType[, conditionId = CONDITIONID_COMBAT[, subId = 0]])](#getCondition{conditionType[, conditionId = CONDITIONID_COMBAT[, subId = 0]]})  
[getDamageMap()](#getDamageMap{})  
[getDescription(distance)](#getDescription{distance})  
[getDirection()](#getDirection{})  
[getEvents()](#getEvents{})  
[getFollowCreature()](#getFollowCreature{})  
[getHealth()](#getHealth{})  
[getId()](#getId{})  
[getLight()](#getLight{})  
[getMana()](#getMana{})  
[getMaster()](#getMaster{})  
[getMaxHealth()](#getMaxHealth{})  
[getMaxMana()](#getMaxMana{})  
[getName()](#getName{})  
[getOutfit()](#getOutfit{})  
[getParent()](#getParent{})  
[getPathTo(pos[, minTargetDist = 0[, maxTargetDist = 1[, fullPathSearch = true[, clearSight = true[, maxSearchDist = 0]]]]])](#getPathTo{pos[, minTargetDist = 0[, maxTargetDist = 1[, fullPathSearch = true[, clearSight = true[, maxSearchDist = 0]]]]]})  
[getPosition()](#getPosition{})  
[getSkull()](#getSkull{})  
[getSpeed()](#getSpeed{})  
[getSummons()](#getSummons{})  
[getTarget()](#getTarget{})  
[getTile()](#getTile{})  
[isCreature()](#isCreature{})  
[isHealthHidden()](#isHealthHidden{})  
[isInGhostMode()](#isInGhostMode{})  
[isItem()](#isItem{})  
[isMonster()](#isMonster{})  
[isNpc()](#isNpc{})  
[isPlayer()](#isPlayer{})  
[isRemoved()](#isRemoved{})  
[isTile()](#isTile{})  
[registerEvent(name)](#registerEvent{name})  
[remove()](#remove{})  
[removeCondition(conditionType[, conditionId = CONDITIONID_COMBAT[, subId = 0[, force = false]]])](#removeCondition{conditionType[, conditionId = CONDITIONID_COMBAT[, subId = 0[, force = false]]]})  
[say(text, type[, ghost = false[, target = nil[, position]]])](#say{text, type[, ghost = false[, target = nil[, position]]]})  
[setDirection(direction)](#setDirection{direction})  
[setDropLoot(doDrop)](#setDropLoot{doDrop})  
[setFollowCreature(followedCreature)](#setFollowCreature{followedCreature})  
[setHiddenHealth(hide)](#setHiddenHealth{hide})  
[setLight(color, level)](#setLight{color, level})  
[setMaster(master)](#setMaster{master})  
[setMaxHealth(maxHealth)](#setMaxHealth{maxHealth})  
[setOutfit(outfit)](#setOutfit{outfit})  
[setSkull(skull)](#setSkull{skull}) 
[setTarget(target)](#setTarget{target})  
[teleportTo(position[, pushMovement = false])](#teleportTo{position[, pushMovement = false]})  
[unregisterEvent(name)](#unregisterEvent{name})  


***

<a name="addCondition{condition[, force = false]}"/>
###### addCondition(condition[, force = false])
> **Description:** N/A  
> **Parameters:** <ul><li>_condition_ - _No description_</li><li>_force_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:addCondition(some_userdata, false)
```
> **Added in version:** 1.0

***

<a name="addHealth{healthChange}"/>
###### addHealth(healthChange)
> **Description:** N/A  
> **Parameters:** <ul><li>_healthChange_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:addHealth(1)
```
> **Added in version:** 1.0

***

<a name="addMana{manaChange[, animationOnLoss = false]}"/>
###### addMana(manaChange[, animationOnLoss = false])
> **Description:** N/A  
> **Parameters:** <ul><li>_manaChange_ - _No description_</li><li>_animationOnLoss_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:addMana(1, false)
```
> **Added in version:** 1.0

***

<a name="canSee{position}"/>
###### canSee(position)
> **Description:** N/A  
> **Parameters:** <ul><li>_position_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:canSee(Position())
```
> **Added in version:** 1.0

***

<a name="canSeeCreature{creature}"/>
###### canSeeCreature(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:canSeeCreature(some_userdata)
```
> **Added in version:** 1.0

***

<a name="changeSpeed{delta}"/>
###### changeSpeed(delta)
> **Description:** N/A  
> **Parameters:** <ul><li>_delta_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:changeSpeed(unknown)
```
> **Added in version:** 1.0

***

<a name="getBaseSpeed{}"/>
###### getBaseSpeed()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getBaseSpeed()
```
> **Added in version:** 1.0

***

<a name="getCondition{conditionType[, conditionId = CONDITIONID_COMBAT[, subId = 0]]}"/>
###### getCondition(conditionType[, conditionId = CONDITIONID_COMBAT[, subId = 0]])
> **Description:** N/A  
> **Parameters:** <ul><li>_conditionType_ - _No description_</li><li>_conditionId_ - _(optional, default: CONDITIONID_COMBAT)_</li><li>_subId_ - _(optional, default: 0)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getCondition(CONDITION_POISON, CONDITIONID_COMBAT, 0)
```
> **Added in version:** 1.0

***

<a name="getDamageMap{}"/>
###### getDamageMap()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getDamageMap()
```
> **Added in version:** 1.0

***

<a name="getDescription{distance}"/>
###### getDescription(distance)
> **Description:** N/A  
> **Parameters:** <ul><li>_distance_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getDescription(1)
```
> **Added in version:** 1.0

***

<a name="getDirection{}"/>
###### getDirection()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getDirection()
```
> **Added in version:** 1.0

***

<a name="getEvents{}"/>
###### getEvents()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getEvents()
```
> **Added in version:** 1.2

***

<a name="getFollowCreature{}"/>
###### getFollowCreature()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getFollowCreature()
```
> **Added in version:** 1.0

***

<a name="getHealth{}"/>
###### getHealth()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getHealth()
```
> **Added in version:** 1.0

***

<a name="getId{}"/>
###### getId()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getId()
```
> **Added in version:** 1.0

***

<a name="getLight{}"/>
###### getLight()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getLight()
```
> **Added in version:** 1.0

***

<a name="getMana{}"/>
###### getMana()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getMana()
```
> **Added in version:** 1.0

***

<a name="getMaster{}"/>
###### getMaster()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getMaster()
```
> **Added in version:** 1.0

***

<a name="getMaxHealth{}"/>
###### getMaxHealth()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getMaxHealth()
```
> **Added in version:** 1.0

***

<a name="getMaxMana{}"/>
###### getMaxMana()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getMaxMana()
```
> **Added in version:** 1.0

***

<a name="getName{}"/>
###### getName()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getName()
```
> **Added in version:** 1.0

***

<a name="getOutfit{}"/>
###### getOutfit()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getOutfit()
```
> **Added in version:** 1.0

***

<a name="getParent{}"/>
###### getParent()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getParent()
```
> **Added in version:** 1.0

***

<a name="getPathTo{pos[, minTargetDist = 0[, maxTargetDist = 1[, fullPathSearch = true[, clearSight = true[, maxSearchDist = 0]]]]]}"/>
###### getPathTo(pos[, minTargetDist = 0[, maxTargetDist = 1[, fullPathSearch = true[, clearSight = true[, maxSearchDist = 0]]]]])
> **Description:** N/A  
> **Parameters:** <ul><li>_pos_ - _No description_</li><li>_minTargetDist_ - _(optional, default: 0)_</li><li>_maxTargetDist_ - _(optional, default: 1)_</li><li>_fullPathSearch_ - _(optional, default: true)_</li><li>_clearSight_ - _(optional, default: true)_</li><li>_maxSearchDist_ - _(optional, default: 0)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getPathTo(Position(), 0, 1, true, true, 0)
```
> **Added in version:** 1.0

***

<a name="getPosition{}"/>
###### getPosition()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getPosition()
```
> **Added in version:** 1.0

***

<a name="getSkull{}"/>
###### getSkull()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getSkull()
```
> **Added in version:** 1.0 for players, since 1.1 for any creature

***

<a name="getSpeed{}"/>
###### getSpeed()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getSpeed()
```
> **Added in version:** 1.0

***

<a name="getSummons{}"/>
###### getSummons()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getSummons()
```
> **Added in version:** 1.0

***

<a name="getTarget{}"/>
###### getTarget()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getTarget()
```
> **Added in version:** 1.0

***

<a name="getTile{}"/>
###### getTile()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:getTile()
```
> **Added in version:** 1.0

***

<a name="isCreature{}"/>
###### isCreature()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:isCreature()
```
> **Added in version:** 1.0

***

<a name="isHealthHidden{}"/>
###### isHealthHidden()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:isHealthHidden()
```
> **Added in version:** 1.0

***

<a name="isInGhostMode{}"/>
###### isInGhostMode()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:isInGhostMode()
```
> **Added in version:** 1.0

***

<a name="isItem{}"/>
###### isItem()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:isItem()
```
> **Added in version:** 1.0

***

<a name="isMonster{}"/>
###### isMonster()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:isMonster()
```
> **Added in version:** 1.0

***

<a name="isNpc{}"/>
###### isNpc()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:isNpc()
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
local creature = Creature(...)
creature:isPlayer()
```
> **Added in version:** 1.0

***

<a name="isRemoved{}"/>
###### isRemoved()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:isRemoved()
```
> **Added in version:** 1.0

***

<a name="isTile{}"/>
###### isTile()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** false  
> **Example:** 
```Lua
local creature = Creature(...)
creature:isTile()
```
> **Added in version:** 1.1

***

<a name="registerEvent{name}"/>
###### registerEvent(name)
> **Description:** N/A  
> **Parameters:** <ul><li>_name_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:registerEvent(some_name)
```
> **Added in version:** 1.0

***

<a name="remove{}"/>
###### remove()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:remove()
```
> **Added in version:** 1.0

***

<a name="removeCondition{conditionType[, conditionId = CONDITIONID_COMBAT[, subId = 0[, force = false]]]}"/>
###### removeCondition(conditionType[, conditionId = CONDITIONID_COMBAT[, subId = 0[, force = false]]])
> **Description:** N/A  
> **Parameters:** <ul><li>_conditionType_ - _No description_</li><li>_conditionId_ - _(optional, default: CONDITIONID_COMBAT)_</li><li>_subId_ - _(optional, default: 0)_</li><li>_force_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:removeCondition(CONDITION_POISON, CONDITIONID_COMBAT, 0, false)
```
> **Added in version:** 1.0

***

<a name="say{text, type[, ghost = false[, target = nil[, position]]]}"/>
###### say(text, type[, ghost = false[, target = nil[, position]]])
> **Description:** Test description  
> **Parameters:** <ul><li>_text_ - _Text shown to others._</li><li>_type_ - _Type of text that is shown._</li><li>_ghost_ - _(optional, default: false)_</li><li>_target_ - _(optional, default: nullptr)_</li><li>_position_ - _(optional)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:say(any_string, TALKTYPE_SAY, false, nil, nil)
```
> **Added in version:** 1.0

***

<a name="setDirection{direction}"/>
###### setDirection(direction)
> **Description:** N/A  
> **Parameters:** <ul><li>_direction_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setDirection(NORTH)
```
> **Added in version:** 1.0

***

<a name="setDropLoot{doDrop}"/>
###### setDropLoot(doDrop)
> **Description:** N/A  
> **Parameters:** <ul><li>_doDrop_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setDropLoot(unknown)
```
> **Added in version:** 1.0

***

<a name="setFollowCreature{followedCreature}"/>
###### setFollowCreature(followedCreature)
> **Description:** N/A  
> **Parameters:** <ul><li>_followedCreature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setFollowCreature(some_userdata)
```
> **Added in version:** 1.0

***

<a name="setHiddenHealth{hide}"/>
###### setHiddenHealth(hide)
> **Description:** N/A  
> **Parameters:** <ul><li>_hide_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setHiddenHealth(unknown)
```
> **Added in version:** 1.0

***

<a name="setLight{color, level}"/>
###### setLight(color, level)
> **Description:** N/A  
> **Parameters:** <ul><li>_color_ - _No description_</li><li>_level_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setLight(0xD7, LIGHT_LEVEL_DAY)
```
> **Added in version:** 1.0

***

<a name="setMaster{master}"/>
###### setMaster(master)
> **Description:** N/A  
> **Parameters:** <ul><li>_master_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setMaster(some_userdata)
```
> **Added in version:** 1.0

***

<a name="setMaxHealth{maxHealth}"/>
###### setMaxHealth(maxHealth)
> **Description:** N/A  
> **Parameters:** <ul><li>_maxHealth_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setMaxHealth(185)
```
> **Added in version:** 1.0

***

<a name="setOutfit{outfit}"/>
###### setOutfit(outfit)
> **Description:** N/A  
> **Parameters:** <ul><li>_outfit_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setOutfit(unknown)
```
> **Added in version:** 1.0

***

<a name="setSkull{skull}"/>
###### setSkull(skull)
> **Description:** N/A  
> **Parameters:** <ul><li>_skull_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setSkull(SKULL_RED)
```
> **Added in version:** 1.0 for players, since 1.1 for any creature

***

<a name="setTarget{target}"/>
###### setTarget(target)
> **Description:** N/A  
> **Parameters:** <ul><li>_target_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:setTarget(some_userdata)
```
> **Added in version:** 1.0

***

<a name="teleportTo{position[, pushMovement = false]}"/>
###### teleportTo(position[, pushMovement = false])
> **Description:** N/A  
> **Parameters:** <ul><li>_position_ - _No description_</li><li>_pushMovement_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:teleportTo(Position(), false)
```
> **Added in version:** 1.0

***

<a name="unregisterEvent{name}"/>
###### unregisterEvent(name)
> **Description:** N/A  
> **Parameters:** <ul><li>_name_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local creature = Creature(...)
creature:unregisterEvent(some_name)
```
> **Added in version:** 1.0