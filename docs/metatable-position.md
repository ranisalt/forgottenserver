No description available at the moment.
###Available methods:
[getDistance(positionEx)](#getDistance{positionEx})  
[isSightClear(positionEx[, sameFloor = true])](#isSightClear{positionEx[, sameFloor = true]})  
[sendDistanceEffect(positionEx, distanceEffect[, player = nil])](#sendDistanceEffect{positionEx, distanceEffect[, player = nil]})  
[sendMagicEffect(magicEffect[, player = nil])](#sendMagicEffect{magicEffect[, player = nil]})  


***

<a name="getDistance{positionEx}"/>
###### getDistance(positionEx)
> **Description:** N/A  
> **Parameters:** <ul><li>_positionEx_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local position = Position(...)
position:getDistance(Position())
```
> **Added in version:** 1.0

***

<a name="isSightClear{positionEx[, sameFloor = true]}"/>
###### isSightClear(positionEx[, sameFloor = true])
> **Description:** N/A  
> **Parameters:** <ul><li>_positionEx_ - _No description_</li><li>_sameFloor_ - _(optional, default: true)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local position = Position(...)
position:isSightClear(Position(), true)
```
> **Added in version:** 1.0

***

<a name="sendDistanceEffect{positionEx, distanceEffect[, player = nil]}"/>
###### sendDistanceEffect(positionEx, distanceEffect[, player = nil])
> **Description:** N/A  
> **Parameters:** <ul><li>_positionEx_ - _No description_</li><li>_distanceEffect_ - _No description_</li><li>_player_ - _(optional, default: nil)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local position = Position(...)
position:sendDistanceEffect(Position(), CONST_ANI_ARROW, nil)
```
> **Added in version:** 1.0

***

<a name="sendMagicEffect{magicEffect[, player = nil]}"/>
###### sendMagicEffect(magicEffect[, player = nil])
> **Description:** N/A  
> **Parameters:** <ul><li>_magicEffect_ - _No description_</li><li>_player_ - _(optional, default: nil)_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local position = Position(...)
position:sendMagicEffect(CONST_ME_POFF, nil)
```
> **Added in version:** 1.0