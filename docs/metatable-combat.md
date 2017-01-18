No description available at the moment.
###Available methods:
[execute(creature, variant)](#execute{creature, variant})  
[setArea(area)](#setArea{area})  
[setCallback(key, function)](#setCallback{key, function})  
[setCondition(condition)](#setCondition{condition})  
[setFormula(type, mina, minb, maxa, maxb)](#setFormula{type, mina, minb, maxa, maxb})  
[setOrigin(origin)](#setOrigin{origin})  
[setParameter(key, value)](#setParameter{key, value})  


***

<a name="execute{creature, variant}"/>
###### execute(creature, variant)
> **Description:** N/A  
> **Parameters:** <ul><li>_creature_ - _No description_</li><li>_variant_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local combat = Combat(...)
combat:execute(some_userdata, Variant(0))
```
> **Added in version:** 1.0

***

<a name="setArea{area}"/>
###### setArea(area)
> **Description:** N/A  
> **Parameters:** <ul><li>_area_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local combat = Combat(...)
combat:setArea(unknown)
```
> **Added in version:** 1.0

***

<a name="setCallback{key, function}"/>
###### setCallback(key, function)
> **Description:** N/A  
> **Parameters:** <ul><li>_key_ - _No description_</li><li>_function_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local combat = Combat(...)
combat:setCallback(CALLBACK_PARAM_TARGETCREATURE, function_name)
```
> **Added in version:** 1.0

***

<a name="setCondition{condition}"/>
###### setCondition(condition)
> **Description:** N/A  
> **Parameters:** <ul><li>_condition_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local combat = Combat(...)
combat:setCondition(some_userdata)
```
> **Added in version:** 1.0

***

<a name="setFormula{type, mina, minb, maxa, maxb}"/>
###### setFormula(type, mina, minb, maxa, maxb)
> **Description:** N/A  
> **Parameters:** <ul><li>_type_ - _No description_</li><li>_mina_ - _No description_</li><li>_minb_ - _No description_</li><li>_maxa_ - _No description_</li><li>_maxb_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local combat = Combat(...)
combat:setFormula(COMBAT_FORMULA_LEVELMAGIC, 0, 0, 1, 1)
```
> **Added in version:** 1.0

***

<a name="setOrigin{origin}"/>
###### setOrigin(origin)
> **Description:** N/A  
> **Parameters:** <ul><li>_origin_ - _No description_</li></ul>
> **Returns:** N/A  
> **Example:** 
```Lua
local combat = Combat(...)
combat:setOrigin(ORIGIN_MELEE)
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
local combat = Combat(...)
combat:setParameter(COMBAT_PARAM_BLOCKSHIELD, true)
```
> **Added in version:** 1.0