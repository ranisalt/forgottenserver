No description available at the moment.
###Available methods:
[clone()](#clone{})  
[decay()](#decay{})  
[getActionId()](#getActionId{})  
[getArticle()](#getArticle{})  
[getAttribute(key)](#getAttribute{key})  
[getCharges()](#getCharges{})  
[getCount()](#getCount{})  
[getDescription(distance)](#getDescription{distance})  
[getFluidType()](#getFluidType{})  
[getId()](#getId{})  
[getName()](#getName{})  
[getParent()](#getParent{})  
[getPluralName()](#getPluralName{})  
[getPosition()](#getPosition{})  
[getSubType()](#getSubType{})  
[getTile()](#getTile{})  
[getTopParent()](#getTopParent{})  
[getType()](#getType{})  
[getUniqueId()](#getUniqueId{})  
[getWeight()](#getWeight{})  
[hasAttribute(key)](#hasAttribute{key})  
[hasProperty(property)](#hasProperty{property})  
[isContainer()](#isContainer{})  
[isCreature()](#isCreature{})  
[isItem()](#isItem{})  
[isPlayer()](#isPlayer{})  
[isTeleport()](#isTeleport{})  
[isTile()](#isTile{})  
[moveTo(position or cylinder)](#moveTo{position or cylinder})  
[remove([count = -1])](#remove{[count = -1]})  
[removeAttribute(key)](#removeAttribute{key})  
[setActionId(actionId)](#setActionId{actionId})  
[setAttribute(key, value)](#setAttribute{key, value})  
[split([count = 1])](#split{[count = 1]})  
[transform(itemId[, count/subType = -1])](#transform{itemId[, count/subType = -1]})  


***

<a name="clone{}"/>
###### clone()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:clone()
```
> **Added in version:** 1.0

***

<a name="decay{}"/>
###### decay()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:decay()
```
> **Added in version:** 1.0

***

<a name="getActionId{}"/>
###### getActionId()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getActionId()
```
> **Added in version:** 1.0

***

<a name="getArticle{}"/>
###### getArticle()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getArticle()
```
> **Added in version:** 1.0

***

<a name="getAttribute{key}"/>
###### getAttribute(key)
> **Description:** N/A  
> **Parameters:** <ul><li>_key_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getAttribute(ITEM_ATTRIBUTE_DESCRIPTION)
```
> **Added in version:** 1.0

***

<a name="getCharges{}"/>
###### getCharges()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getCharges()
```
> **Added in version:** 1.0

***

<a name="getCount{}"/>
###### getCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getCount()
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
local item = Item(...)
item:getDescription(1)
```
> **Added in version:** 1.0

***

<a name="getFluidType{}"/>
###### getFluidType()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getFluidType()
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
local item = Item(...)
item:getId()
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
local item = Item(...)
item:getName()
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
local item = Item(...)
item:getParent()
```
> **Added in version:** 1.0

***

<a name="getPluralName{}"/>
###### getPluralName()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getPluralName()
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
local item = Item(...)
item:getPosition()
```
> **Added in version:** 1.0

***

<a name="getSubType{}"/>
###### getSubType()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getSubType()
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
local item = Item(...)
item:getTile()
```
> **Added in version:** 1.0

***

<a name="getTopParent{}"/>
###### getTopParent()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getTopParent()
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
local item = Item(...)
item:getType()
```
> **Added in version:** 1.0

***

<a name="getUniqueId{}"/>
###### getUniqueId()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getUniqueId()
```
> **Added in version:** 1.0

***

<a name="getWeight{}"/>
###### getWeight()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:getWeight()
```
> **Added in version:** 1.1

***

<a name="hasAttribute{key}"/>
###### hasAttribute(key)
> **Description:** N/A  
> **Parameters:** <ul><li>_key_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:hasAttribute(ITEM_ATTRIBUTE_DESCRIPTION)
```
> **Added in version:** 1.1

***

<a name="hasProperty{property}"/>
###### hasProperty(property)
> **Description:** N/A  
> **Parameters:** <ul><li>_property_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:hasProperty(unknown)
```
> **Added in version:** 1.0

***

<a name="isContainer{}"/>
###### isContainer()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:isContainer()
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
local item = Item(...)
item:isCreature()
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
local item = Item(...)
item:isItem()
```
> **Added in version:** 1.0

***

<a name="isPlayer{}"/>
###### isPlayer()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** false  
> **Example:** 
```Lua
local item = Item(...)
item:isPlayer()
```
> **Added in version:** 1.1

***

<a name="isTeleport{}"/>
###### isTeleport()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:isTeleport()
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
local item = Item(...)
item:isTile()
```
> **Added in version:** 1.1

***

<a name="moveTo{position or cylinder}"/>
###### moveTo(position or cylinder)
> **Description:** N/A  
> **Parameters:** <ul><li>_position or cylinder_ - _Supported cylinders are: Container, Player and Tile._</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:moveTo(Position())
```
> **Added in version:** 1.0 (only position), extended with support for cylinders in 1.1

***

<a name="remove{[count = -1]}"/>
###### remove([count = -1])
> **Description:** N/A  
> **Parameters:** <ul><li>_count_ - _(optional, default: -1)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:remove(-1)
```
> **Added in version:** 1.0

***

<a name="removeAttribute{key}"/>
###### removeAttribute(key)
> **Description:** N/A  
> **Parameters:** <ul><li>_key_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:removeAttribute(ITEM_ATTRIBUTE_DESCRIPTION)
```
> **Added in version:** 1.0

***

<a name="setActionId{actionId}"/>
###### setActionId(actionId)
> **Description:** N/A  
> **Parameters:** <ul><li>_actionId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:setActionId(1000)
```
> **Added in version:** 1.0

***

<a name="setAttribute{key, value}"/>
###### setAttribute(key, value)
> **Description:** N/A  
> **Parameters:** <ul><li>_key_ - _No description_</li><li>_value_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:setAttribute(ITEM_ATTRIBUTE_DESCRIPTION, any_string)
```
> **Added in version:** 1.0

***

<a name="split{[count = 1]}"/>
###### split([count = 1])
> **Description:** N/A  
> **Parameters:** <ul><li>_count_ - _(optional, default: 1)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:split(1)
```
> **Added in version:** 1.0

***

<a name="transform{itemId[, count/subType = -1]}"/>
###### transform(itemId[, count/subType = -1])
> **Description:** N/A  
> **Parameters:** <ul><li>_itemId_ - _No description_</li><li>_count/subType_ - _(optional, default: -1)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local item = Item(...)
item:transform(2400, -1)
```
> **Added in version:** 1.0