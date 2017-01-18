No description available at the moment.
###Available methods:
[addByte(number)](#addByte{number})  
[addDouble(number)](#addDouble{number})  
[addItem(item)](#addItem{item})  
[addItemId(itemId)](#addItemId{itemId})  
[addPosition(position)](#addPosition{position})  
[addString(string)](#addString{string})  
[addU16(number)](#addU16{number})  
[addU32(number)](#addU32{number})  
[addU64(number)](#addU64{number})  
[getByte()](#getByte{})  
[getPosition()](#getPosition{})  
[getString()](#getString{})  
[getU16()](#getU16{})  
[getU32()](#getU32{})  
[getU64()](#getU64{})  
[reset()](#reset{})  
[sendToPlayer(player)](#sendToPlayer{player})  
[skipBytes(number)](#skipBytes{number})  


***

<a name="addByte{number}"/>
###### addByte(number)
> **Description:** N/A  
> **Parameters:** <ul><li>_number_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:addByte(any_number)
```
> **Added in version:** 1.0

***

<a name="addDouble{number}"/>
###### addDouble(number)
> **Description:** N/A  
> **Parameters:** <ul><li>_number_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:addDouble(any_number)
```
> **Added in version:** 1.0

***

<a name="addItem{item}"/>
###### addItem(item)
> **Description:** N/A  
> **Parameters:** <ul><li>_item_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:addItem(some_userdata)
```
> **Added in version:** 1.0

***

<a name="addItemId{itemId}"/>
###### addItemId(itemId)
> **Description:** N/A  
> **Parameters:** <ul><li>_itemId_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:addItemId(2400)
```
> **Added in version:** 1.0

***

<a name="addPosition{position}"/>
###### addPosition(position)
> **Description:** N/A  
> **Parameters:** <ul><li>_position_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:addPosition(Position())
```
> **Added in version:** 1.0

***

<a name="addString{string}"/>
###### addString(string)
> **Description:** N/A  
> **Parameters:** <ul><li>_string_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:addString(any_string)
```
> **Added in version:** 1.0

***

<a name="addU16{number}"/>
###### addU16(number)
> **Description:** N/A  
> **Parameters:** <ul><li>_number_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:addU16(any_number)
```
> **Added in version:** 1.0

***

<a name="addU32{number}"/>
###### addU32(number)
> **Description:** N/A  
> **Parameters:** <ul><li>_number_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:addU32(any_number)
```
> **Added in version:** 1.0

***

<a name="addU64{number}"/>
###### addU64(number)
> **Description:** N/A  
> **Parameters:** <ul><li>_number_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:addU64(any_number)
```
> **Added in version:** 1.0

***

<a name="getByte{}"/>
###### getByte()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:getByte()
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
local networkmessage = NetworkMessage(...)
networkmessage:getPosition()
```
> **Added in version:** 1.0

***

<a name="getString{}"/>
###### getString()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:getString()
```
> **Added in version:** 1.0

***

<a name="getU16{}"/>
###### getU16()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:getU16()
```
> **Added in version:** 1.0

***

<a name="getU32{}"/>
###### getU32()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:getU32()
```
> **Added in version:** 1.0

***

<a name="getU64{}"/>
###### getU64()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:getU64()
```
> **Added in version:** 1.0

***

<a name="reset{}"/>
###### reset()
> **Description:** N/A  
> **Parameters:** None  
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:reset()
```
> **Added in version:** 1.0

***

<a name="sendToPlayer{player}"/>
###### sendToPlayer(player)
> **Description:** N/A  
> **Parameters:** <ul><li>_player_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:sendToPlayer(some_userdata)
```
> **Added in version:** 1.0

***

<a name="skipBytes{number}"/>
###### skipBytes(number)
> **Description:** N/A  
> **Parameters:** <ul><li>_number_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local networkmessage = NetworkMessage(...)
networkmessage:skipBytes(any_number)
```
> **Added in version:** 1.0