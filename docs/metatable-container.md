No description available at the moment.
###Available methods:
[addItem(itemId[, count/subType = 1[, index = INDEX_WHEREEVER[, flags = 0]]])](#addItem{itemId[, count/subType = 1[, index = INDEX_WHEREEVER[, flags = 0]]]})  
[addItemEx(item[, index = INDEX_WHEREEVER[, flags = 0]])](#addItemEx{item[, index = INDEX_WHEREEVER[, flags = 0]]})  
[getCapacity()](#getCapacity{})  
[getEmptySlots([recursive = false])](#getEmptySlots{[recursive = false]})  
[getItem(index)](#getItem{index})  
[getItemCountById(itemId[, subType = -1])](#getItemCountById{itemId[, subType = -1]})  
[getItemHoldingCount()](#getItemHoldingCount{})  
[getSize()](#getSize{})  
[hasItem(item)](#hasItem{item})  
[isContainer()](#isContainer{})  


***

<a name="addItem{itemId[, count/subType = 1[, index = INDEX_WHEREEVER[, flags = 0]]]}"/>
###### addItem(itemId[, count/subType = 1[, index = INDEX_WHEREEVER[, flags = 0]]])
> **Description:** N/A  
> **Parameters:** <ul><li>_itemId_ - _No description_</li><li>_count/subType_ - _(optional, default: 1)_</li><li>_index_ - _(optional, default: INDEX_WHEREEVER)_</li><li>_flags_ - _(optional, default: 0)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local container = Container(...)
container:addItem(2400, 1, INDEX_WHEREEVER, 0)
```
> **Added in version:** 1.0

***

<a name="addItemEx{item[, index = INDEX_WHEREEVER[, flags = 0]]}"/>
###### addItemEx(item[, index = INDEX_WHEREEVER[, flags = 0]])
> **Description:** N/A  
> **Parameters:** <ul><li>_item_ - _No description_</li><li>_index_ - _(optional, default: INDEX_WHEREEVER)_</li><li>_flags_ - _(optional, default: 0)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local container = Container(...)
container:addItemEx(some_userdata, INDEX_WHEREEVER, 0)
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
local container = Container(...)
container:getCapacity()
```
> **Added in version:** 1.0

***

<a name="getEmptySlots{[recursive = false]}"/>
###### getEmptySlots([recursive = false])
> **Description:** N/A  
> **Parameters:** <ul><li>_recursive_ - _(optional, default: false)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local container = Container(...)
container:getEmptySlots(false)
```
> **Added in version:** 1.0

***

<a name="getItem{index}"/>
###### getItem(index)
> **Description:** N/A  
> **Parameters:** <ul><li>_index_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local container = Container(...)
container:getItem(some_id)
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
local container = Container(...)
container:getItemCountById(2400, -1)
```
> **Added in version:** 1.0

***

<a name="getItemHoldingCount{}"/>
###### getItemHoldingCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local container = Container(...)
container:getItemHoldingCount()
```
> **Added in version:** 1.0

***

<a name="getSize{}"/>
###### getSize()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local container = Container(...)
container:getSize()
```
> **Added in version:** 1.0

***

<a name="hasItem{item}"/>
###### hasItem(item)
> **Description:** N/A  
> **Parameters:** <ul><li>_item_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local container = Container(...)
container:hasItem(some_userdata)
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
local container = Container(...)
container:isContainer()
```
> **Added in version:** 1.0