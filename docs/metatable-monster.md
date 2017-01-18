No description available at the moment.
###Available methods:
[addFriend(creature)](#addFriend{creature})  
[addTarget(creature[, pushFront = false])](#addTarget{creature[, pushFront = false]})  
[isInSpawnRange([position])](#isInSpawnRange{[position]})  
[getFriendCount()](#getFriendCount{})  
[getFriendList()](#getFriendList{})  
[getSpawnPosition()](#getSpawnPosition{})  
[getTargetCount()](#getTargetCount{})  
[getTargetList()](#getTargetList{})  
[getType()](#getType{})  
[isFriend(creature)](#isFriend{creature})  
[isIdle()](#isIdle{})  
[isMonster()](#isMonster{})  
[isOpponent(creature)](#isOpponent{creature})  
[isTarget(creature)](#isTarget{creature})  
[removeFriend(creature)](#removeFriend{creature})  
[removeTarget(creature)](#removeTarget{creature})  
[searchTarget([searchType = TARGETSEARCH_DEFAULT])](#searchTarget{[searchType = TARGETSEARCH_DEFAULT]})  
[selectTarget(creature)](#selectTarget{creature})  
[setIdle(idle)](#setIdle{idle})  


***

<a name="addFriend{creature}"/>
###### addFriend(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:addFriend(some_userdata)
```
> **Added in version:** 1.0

***

<a name="addTarget{creature[, pushFront = false]}"/>
###### addTarget(creature[, pushFront = false])
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li><li>_pushFront_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:addTarget(some_userdata, false)
```
> **Added in version:** 1.0

***

<a name="isInSpawnRange{[position]}"/>
###### isInSpawnRange()
> **Description:** N/A  
> **Parameters:** <ul><li>_position_ - _(optional, default: monster position)_</li></ul>  
> **Returns:** true if the position is in spawn range, otherwise false  
> **Example:** 
```Lua
local monster = Monster(...)
monster:isInSpawnRange()
```
> **Added in version:** 1.1

***

<a name="getFriendCount{}"/>
###### getFriendCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:getFriendCount()
```
> **Added in version:** 1.0

***

<a name="getFriendList{}"/>
###### getFriendList()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:getFriendList()
```
> **Added in version:** 1.0

***

<a name="getSpawnPosition{}"/>
###### getSpawnPosition()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:getSpawnPosition()
```
> **Added in version:** 1.0

***

<a name="getTargetCount{}"/>
###### getTargetCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:getTargetCount()
```
> **Added in version:** 1.0

***

<a name="getTargetList{}"/>
###### getTargetList()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:getTargetList()
```
> **Added in version:** 1.0

***

<a name="getType{}"/>
###### getType()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:getType()
```
> **Added in version:** 1.0

***

<a name="isFriend{creature}"/>
###### isFriend(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:isFriend(some_userdata)
```
> **Added in version:** 1.0

***

<a name="isIdle{}"/>
###### isIdle()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:isIdle()
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
local monster = Monster(...)
monster:isMonster()
```
> **Added in version:** 1.0

***

<a name="isOpponent{creature}"/>
###### isOpponent(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:isOpponent(some_userdata)
```
> **Added in version:** 1.0

***

<a name="isTarget{creature}"/>
###### isTarget(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:isTarget(some_userdata)
```
> **Added in version:** 1.0

***

<a name="removeFriend{creature}"/>
###### removeFriend(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:removeFriend(some_userdata)
```
> **Added in version:** 1.0

***

<a name="removeTarget{creature}"/>
###### removeTarget(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:removeTarget(some_userdata)
```
> **Added in version:** 1.0

***

<a name="searchTarget{[searchType = TARGETSEARCH_DEFAULT]}"/>
###### searchTarget([searchType = TARGETSEARCH_DEFAULT])
> **Description:** N/A  
> **Parameters:** <ul><li>_searchType_ - _(optional, default: TARGETSEARCH_DEFAULT)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:searchTarget(TARGETSEARCH_DEFAULT)
```
> **Added in version:** 1.0

***

<a name="selectTarget{creature}"/>
###### selectTarget(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:selectTarget(some_userdata)
```
> **Added in version:** 1.0

***

<a name="setIdle{idle}"/>
###### setIdle(idle)
> **Description:** N/A  
> **Parameters:** <ul><li>_idle_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local monster = Monster(...)
monster:setIdle(unknown)
```
> **Added in version:** 1.0