=====================
#### Engine
* Non-blocking SQL queries
* The following item attributes can now be customized using setAttribute for items: name,
article, pluralname, weight, attack, defense, extradefense, armor,
hitchance and shootrange
* Improved XML error handling to show line number, line and a caret pointing at the character where parsing failed
* Increased accuracy of scheduled events
* Optimized dispatcher and scheduler code
* Moved drop loot code from the engine to data/creaturescripts/scripts/droploot.lua
* **Breaking change**: Moved ammoaction and breakchance from items.xml to weapons.xml, ammoaction is now just referred to as action and works for any type of weapon
* Using integers instead of floating point numbers for item weight and player capacity
* Using max packet length from MySQL in DBInsert class to know when it is appropriate to execute the query
* Rewritten skills code to handle 64-bit tries for magic level and skills properly
* Removed config variable noDamageToSameLookfeet as it can be implemented using onHealthChange and onManaChange
* Removed stackpos from position tables sent to onUse and onCastSpell for performance reasons as stackpos is rarely used and can be fetched using Tile.getThingIndex when necessary
* Fixed a rounding bug with the formula for magic level offline training
* Fixed a bug allowing players to equip two-handed weapons with a shield when using classic equipment slots
* Fixed a bug where stamina wouldn't be consumed for some players in a party with shared experience enabled
* Fixed a bug where using magic field runes would give the player protection zone lock regardless of PVP engagement

#### Features
* Game protocol 10.76 support
* Mana drain now counts as damage
* Weapon action (previously called ammoaction in items.xml, now action in weapons.xml) can now be applied to any weapon

#### Source code
* Use of more C++11 features:
	* final/override
	* emplace for map insertions
* Updated pugixml to version 1.5
* Removed XPath from pugixml
* Removed virtual specifier from all functions that aren't being overridden
* Fixed linking with LuaJIT on Mac OS X

#### Script interface
* **Breaking change**: Creature userdata (creature) is now passed to every event callback instead of creature id (cid)
	* This also applies for all subclasses; Monster, NPC and Player
* Items passed to Lua event callbacks can now be utilized directly as userdata. You can still access itemid, uid, actionid and type by accessing them as table properties.
* Functions getSkull() and setSkull() can now be called for any creature (previously only for players).
* Events
	* Creature
		* onChangeOutfit
		* onAreaCombat
		* onTargetCombat
	* Player
		* onGainSkillTries
* New functions
	* Game.createContainer(itemId, size[, position])
	* Item.hasAttribute(self, key)
	* Item.getWeight(self)
	* ItemType.getClientId(self)
	* ItemType.getCharges(self)
	* ItemType.getHitChange(self)
	* ItemType.getRequiredLevel(self)
	* ItemType.getShootRange(self)
	* Monster.isInSpawnRange(self[, position])
	* Player.getLastLogout(self)
* Removed function
	* Monster.despawn(self)
		* removed in favor of Monster.isInSpawnRange

#### Data pack
* Moved compat.lua and core Lua API functions into data/lib/ (data/lib/compat/ and data/lib/core/) from global.lua
* Updated scripts to utilize userdata objects more efficiently
* Removed function="default" from weapons.xml
* Moved ammoaction and breakchance from items.xml to weapons.xml
