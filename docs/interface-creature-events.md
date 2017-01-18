These events run whenever something happens to a creature and/or player.
###Available events:
[onAdvance()](#onAdvance)  
[onDeath()](#onDeath)  
[onExtendedOpcode()](#onExtendedOpcode)  
[onHealthChange()](#onHealthChange)  
[onKill()](#onKill)  
[onLogin()](#onLogin)  
[onLogout()](#onLogout)  
[onManaChange()](#onManaChange)  
[onModalWindow()](#onModalWindow)  
[onPrepareDeath()](#onPrepareDeath)  
[onTextEdit()](#onTextEdit)  
[onThink()](#onThink)  


***

<a name="onAdvance"/>
###### onAdvance()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0

***

<a name="onDeath"/>
###### onDeath()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0

***

<a name="onExtendedOpcode"/>
###### onExtendedOpcode()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0

***

<a name="onHealthChange"/>
###### onHealthChange()
> **Description:** This event runs each time a (registered) creatures health changes.  
> **Parameters:** <ul><li>_creature_ - _Creature userdata of the victim_</li><li>_attacker_ - _Creature userdata of the attacker, can be nil_</li><li>_primaryDamage_ - _First part of the damage (always a positive value)_</li><li>_primaryType_ - _First damage type_</li><li>_secondaryDamage_ - _Second part of the damage (always a positive value)_</li><li>_secondaryType_ - _Second damage type_</li><li>_origin_ - _What were you hit by? A spell? Melee?_</li></ul>
> **Accepted return values:** 2 or more values must be returned otherwise the event will be cancelled.  
```Lua
return 5, COMBAT_FIREDAMAGE, 5, COMBAT_PHYSICALDAMAGE
```
> **Example:** 
```Lua
function onHealthChange(creature, attacker, primaryDamage, primaryType, secondaryDamage, secondaryType)
	if not attacker then
		return 5, COMBAT_FIREDAMAGE, 0, COMBAT_NONE
	end
	return primaryDamage, primaryType, -secondaryDamage, secondaryType
end
```
Added in version: 1.0

***

<a name="onKill"/>
###### onKill()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0

***

<a name="onLogin"/>
###### onLogin()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0

***

<a name="onLogout"/>
###### onLogout()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0

***

<a name="onManaChange"/>
###### onManaChange()
> **Description:** This event runs each time a (registered) creatures mana changes.  
> **Parameters:** <ul><li>_creature_ - _Creature userdata of the victim_</li><li>_attacker_ - _Creature userdata of the attacker, can be nil_</li><li>_manaChange_ - _How much mana you have gained or lost (always a positive value)_</li></ul>
> **Accepted return values:** 1 value must be returned otherwise the event will be cancelled.  
```Lua
return 5
```
> **Example:** 
```Lua
function onManaChange(creature, attacker, manaChange)
	if not attacker then
		return 0
	end
	return manaChange
end
```
Added in version: 1.0

***

<a name="onModalWindow"/>
###### onModalWindow()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0

***

<a name="onPrepareDeath"/>
###### onPrepareDeath()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0

***

<a name="onTextEdit"/>
###### onTextEdit()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0

***

<a name="onThink"/>
###### onThink()
> **Description:** N/A  
> **Parameters:** N/A  
> **Accepted return values:** N/A  
> **Example:** 
```Lua
N/A  
```
Added in version: 1.0