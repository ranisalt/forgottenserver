No description available at the moment.
###Available methods:
[getBottomCreature()](#getBottomCreature{})  
[getBottomVisibleCreature(creature)](#getBottomVisibleCreature{creature})  
[getCreatureCount()](#getCreatureCount{})  
[getCreatures()](#getCreatures{})  
[getDownItemCount()](#getDownItemCount{})  
[getFieldItem()](#getFieldItem{})  
[getGround()](#getGround{})  
[getHouse()](#getHouse{})  
[getItemById(itemId[, subType = -1])](#getItemById{itemId[, subType = -1]})  
[getItemByTopOrder(topOrder)](#getItemByTopOrder{topOrder})  
[getItemByType(itemType)](#getItemByType{itemType})  
[getItemCount()](#getItemCount{})  
[getItemCountById(itemId[, subType = -1])](#getItemCountById{itemId[, subType = -1]})  
[getItems()](#getItems{})  
[getPosition()](#getPosition{})  
[getThing(index)](#getThing{index})  
[getThingCount()](#getThingCount{})  
[getThingIndex(thing)](#getThingIndex{thing})  
[getTopCreature()](#getTopCreature{})  
[getTopDownItem()](#getTopDownItem{})  
[getTopItemCount()](#getTopItemCount{})  
[getTopTopItem()](#getTopTopItem{})  
[getTopVisibleCreature(creature)](#getTopVisibleCreature{creature})  
[getTopVisibleThing(creature)](#getTopVisibleThing{creature})  
[hasFlag(flag)](#hasFlag{flag})  
[hasProperty(property[, item])](#hasProperty{property[, item]})  
[isCreature()](#isCreature{})  
[isItem()](#isItem{})  
[isTile()](#isTile{})  
[queryAdd(thing[, flags])](#queryAdd{thing[, flags]})  


***

<a name="getBottomCreature{}"/>
###### getBottomCreature()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getBottomCreature()
```
> **Added in version:** 1.0

***

<a name="getBottomVisibleCreature{creature}"/>
###### getBottomVisibleCreature(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getBottomVisibleCreature(some_userdata)
```
> **Added in version:** 1.0

***

<a name="getCreatureCount{}"/>
###### getCreatureCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getCreatureCount()
```
> **Added in version:** 1.0

***

<a name="getCreatures{}"/>
###### getCreatures()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getCreatures()
```
> **Added in version:** 1.0

***

<a name="getDownItemCount{}"/>
###### getDownItemCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getDownItemCount()
```
> **Added in version:** 1.0

***

<a name="getFieldItem{}"/>
###### getFieldItem()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getFieldItem()
```
> **Added in version:** 1.0

***

<a name="getGround{}"/>
###### getGround()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getGround()
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
local tile = Tile(...)
tile:getHouse()
```
> **Added in version:** 1.0

***

<a name="getItemById{itemId[, subType = -1]}"/>
###### getItemById(itemId[, subType = -1])
> **Description:** N/A  
> **Parameters:** <ul><li>_itemId_ - _No description_</li><li>_subType_ - _(optional, default: -1)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getItemById(2400, -1)
```
> **Added in version:** 1.0

***

<a name="getItemByTopOrder{topOrder}"/>
###### getItemByTopOrder(topOrder)
> **Description:** N/A  
> **Parameters:** <ul><li>_topOrder_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getItemByTopOrder(unknown)
```
> **Added in version:** 1.0

***

<a name="getItemByType{itemType}"/>
###### getItemByType(itemType)
> **Description:** N/A  
> **Parameters:** <ul><li>_itemType_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getItemByType(ITEM_TYPE_TELEPORT)
```
> **Added in version:** 1.0

***

<a name="getItemCount{}"/>
###### getItemCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getItemCount()
```
> **Added in version:** 1.0

***

<a name="getItemCountById{itemId[, subType = -1]}"/>
###### getItemCountById(itemId[, subType = -1])
> **Description:** N/A  
> **Parameters:** <ul><li>_itemId_ - _No description_</li><li>_subType_ - _(optional, default: -1)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getItemCountById(2400, -1)
```
> **Added in version:** 1.0

***

<a name="getItems{}"/>
###### getItems()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getItems()
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
local tile = Tile(...)
tile:getPosition()
```
> **Added in version:** 1.0

***

<a name="getThing{index}"/>
###### getThing(index)
> **Description:** N/A  
> **Parameters:** <ul><li>_index_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getThing(some_id)
```
> **Added in version:** 1.0

***

<a name="getThingCount{}"/>
###### getThingCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getThingCount()
```
> **Added in version:** 1.0

***

<a name="getThingIndex{thing}"/>
###### getThingIndex(thing)
> **Description:** N/A  
> **Parameters:** <ul><li>_thing_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getThingIndex(userdata_or_id)
```
> **Added in version:** 1.0

***

<a name="getTopCreature{}"/>
###### getTopCreature()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getTopCreature()
```
> **Added in version:** 1.0

***

<a name="getTopDownItem{}"/>
###### getTopDownItem()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getTopDownItem()
```
> **Added in version:** 1.0

***

<a name="getTopItemCount{}"/>
###### getTopItemCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getTopItemCount()
```
> **Added in version:** 1.0

***

<a name="getTopTopItem{}"/>
###### getTopTopItem()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getTopTopItem()
```
> **Added in version:** 1.0

***

<a name="getTopVisibleCreature{creature}"/>
###### getTopVisibleCreature(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getTopVisibleCreature(some_userdata)
```
> **Added in version:** 1.0

***

<a name="getTopVisibleThing{creature}"/>
###### getTopVisibleThing(creature)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:getTopVisibleThing(some_userdata)
```
> **Added in version:** 1.0

***

<a name="hasFlag{flag}"/>
###### hasFlag(flag)
> **Description:** N/A  
> **Parameters:** <ul><li>_flag_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:hasFlag(unknown)
```
> **Added in version:** 1.0

***

<a name="hasProperty{property[, item]}"/>
###### hasProperty(property[, item])
> **Description:** N/A  
> **Parameters:** <ul><li>_property_ - _No description_</li><li>_item_ - _(optional)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:hasProperty(unknown, nil)
```
> **Added in version:** 1.0

***

<a name="isCreature{}"/>
###### isCreature()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** false  
> **Example:** 
```Lua
local tile = Tile(...)
tile:isCreature()
```
> **Added in version:** 1.1

***

<a name="isItem{}"/>
###### isItem()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** false  
> **Example:** 
```Lua
local tile = Tile(...)
tile:isItem()
```
> **Added in version:** 1.1

***

<a name="isTile{}"/>
###### isTile()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** true  
> **Example:** 
```Lua
local tile = Tile(...)
tile:isTile()
```
> **Added in version:** 1.1

***

<a name="queryAdd{thing[, flags]}"/>
###### queryAdd(thing[, flags])
> **Description:** N/A  
> **Parameters:** <ul><li>_thing_ - _No description_</li><li>_flags_ - _(optional)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local tile = Tile(...)
tile:queryAdd(userdata_or_id, nil)
```
> **Added in version:** 1.0