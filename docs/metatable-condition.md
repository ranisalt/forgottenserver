No description available at the moment.
###Available methods:
[addDamage(rounds, time, value)](#addDamage{rounds, time, value})  
[clone()](#clone{})  
[getEndTime()](#getEndTime{})  
[getIcons()](#getIcons{})  
[getId()](#getId{})  
[getSubId()](#getSubId{})  
[getTicks()](#getTicks{})  
[getType()](#getType{})  
[setFormula(mina, minb, maxa, maxb)](#setFormula{mina, minb, maxa, maxb})  
[setOutfit(outfit)](#setOutfit{outfit})  
[setOutfit(lookTypeEx, lookType, lookHead, lookBody, lookLegs, lookFeet[, lookAddons[, lookMount]])](#setOutfit{lookTypeEx, lookType, lookHead, lookBody, lookLegs, lookFeet[, lookAddons[, lookMount]]})  
[setParameter(key, value)](#setParameter{key, value})  
[setTicks(ticks)](#setTicks{ticks})  


***

<a name="addDamage{rounds, time, value}"/>
###### addDamage(rounds, time, value)
> **Description:** N/A  
> **Parameters:** <ul><li>_rounds_ - _No description_</li><li>_time_ - _No description_</li><li>_value_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:addDamage(3, 2, 5)
```
> **Added in version:** 1.0

***

<a name="clone{}"/>
###### clone()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:clone()
```
> **Added in version:** 1.0

***

<a name="getEndTime{}"/>
###### getEndTime()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:getEndTime()
```
> **Added in version:** 1.0

***

<a name="getIcons{}"/>
###### getIcons()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:getIcons()
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
local condition = Condition(...)
condition:getId()
```
> **Added in version:** 1.0

***

<a name="getSubId{}"/>
###### getSubId()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:getSubId()
```
> **Added in version:** 1.0

***

<a name="getTicks{}"/>
###### getTicks()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:getTicks()
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
local condition = Condition(...)
condition:getType()
```
> **Added in version:** 1.0

***

<a name="setFormula{mina, minb, maxa, maxb}"/>
###### setFormula(mina, minb, maxa, maxb)
> **Description:** N/A  
> **Parameters:** <ul><li>_mina_ - _No description_</li><li>_minb_ - _No description_</li><li>_maxa_ - _No description_</li><li>_maxb_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:setFormula(0, 0, 1, 1)
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
local condition = Condition(...)
condition:setOutfit(unknown)
```
> **Added in version:** 1.0

***

<a name="setOutfit{lookTypeEx, lookType, lookHead, lookBody, lookLegs, lookFeet[, lookAddons[, lookMount]]}"/>
###### setOutfit(lookTypeEx, lookType, lookHead, lookBody, lookLegs, lookFeet[, lookAddons[, lookMount]])
> **Description:** N/A  
> **Parameters:** <ul><li>_lookTypeEx_ - _No description_</li><li>_lookType_ - _No description_</li><li>_lookHead_ - _No description_</li><li>_lookBody_ - _No description_</li><li>_lookLegs_ - _No description_</li><li>_lookFeet_ - _No description_</li><li>_lookAddons_ - _(optional)_</li><li>_lookMount_ - _(optional)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:setOutfit(0, 128, 0, 0, 0, 0, nil, nil)
```
> **Added in version:** 1.0

***

<a name="setParameter{key, value}"/>
###### setParameter(key, value)
> **Description:** N/A  
> **Parameters:** <ul><li>_key_ - _No description_</li><li>_value_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:setParameter(CONDITION_PARAM_SPEED, 150)
```
> **Added in version:** 1.0

***

<a name="setTicks{ticks}"/>
###### setTicks(ticks)
> **Description:** N/A  
> **Parameters:** <ul><li>_ticks_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local condition = Condition(...)
condition:setTicks(1000)
```
> **Added in version:** 1.0