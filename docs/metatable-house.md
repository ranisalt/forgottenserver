No description available at the moment.
###Available methods:
[getAccessList(listId)](#getAccessList{listId})  
[getBedCount()](#getBedCount{})  
[getBeds()](#getBeds{})  
[getDoorCount()](#getDoorCount{})  
[getDoors()](#getDoors{})  
[getExitPosition()](#getExitPosition{})  
[getId()](#getId{})  
[getName()](#getName{})  
[getOwnerGuid()](#getOwnerGuid{})  
[getRent()](#getRent{})  
[getTileCount()](#getTileCount{})  
[getTiles()](#getTiles{})  
[getTown()](#getTown{})  
[setAccessList(listId, list)](#setAccessList{listId, list})  
[setOwnerGuid(guid[, updateDatabase = true])](#setOwnerGuid{guid[, updateDatabase = true]})  


***

<a name="getAccessList{listId}"/>
###### getAccessList(listId)
> **Description:** N/A  
> **Parameters:** <ul><li>_listId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getAccessList(GUEST_LIST)
```
> **Added in version:** 1.0

***

<a name="getBedCount{}"/>
###### getBedCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getBedCount()
```
> **Added in version:** 1.0

***

<a name="getBeds{}"/>
###### getBeds()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getBeds()
```
> **Added in version:** 1.0

***

<a name="getDoorCount{}"/>
###### getDoorCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getDoorCount()
```
> **Added in version:** 1.0

***

<a name="getDoors{}"/>
###### getDoors()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getDoors()
```
> **Added in version:** 1.0

***

<a name="getExitPosition{}"/>
###### getExitPosition()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getExitPosition()
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
local house = House(...)
house:getId()
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
local house = House(...)
house:getName()
```
> **Added in version:** 1.0

***

<a name="getOwnerGuid{}"/>
###### getOwnerGuid()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getOwnerGuid()
```
> **Added in version:** 1.0

***

<a name="getRent{}"/>
###### getRent()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getRent()
```
> **Added in version:** 1.0

***

<a name="getTileCount{}"/>
###### getTileCount()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getTileCount()
```
> **Added in version:** 1.0

***

<a name="getTiles{}"/>
###### getTiles()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:getTiles()
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
local house = House(...)
house:getTown()
```
> **Added in version:** 1.0

***

<a name="setAccessList{listId, list}"/>
###### setAccessList(listId, list)
> **Description:** N/A  
> **Parameters:** <ul><li>_listId_ - _No description_</li><li>_list_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:setAccessList(GUEST_LIST, house_name_list)
```
> **Added in version:** 1.0

***

<a name="setOwnerGuid{guid[, updateDatabase = true]}"/>
###### setOwnerGuid(guid[, updateDatabase = true])
> **Description:** N/A  
> **Parameters:** <ul><li>_guid_ - _No description_</li><li>_updateDatabase_ - _(optional, default: true)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local house = House(...)
house:setOwnerGuid(unknown, true)
```
> **Added in version:** 1.0