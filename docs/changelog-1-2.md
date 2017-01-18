=====================
#### Engine
* Lots of optimizations all over the place
* Decreased memory footprint of static tiles that only have ground
* Refactored network stack with optimizations to the output message pool
* Guild ranks are no longer limited to 3 entries
* Fixed multiple issues with normal random distribution
* Fixed packet ordering when a network message is re-queued due to pending write
* Fixed a few bugs with summons
* Fixed a bug with conjured items not decaying
* Fixed a bug where players would get protection zone lock in PVP zones
* Fixed potential race conditions in dispatcher and scheduler when shutting down
* Fixed a potential memory leak when reloading monsters
* Fixed a memory leak when reloading quests

#### Features
* Game protocol 10.98 support
* Automatically mount when leaving protection zone if player was mounted when entering protection zone
* [Two factor authentication using TOTP (Time-based One-time Password)](two-factor-authentication.md)

#### Source code
* Moved pugixml from the repository to TFS SDK
* Use of newer boost features requires at least boost 1.53.0 to compile
* Renamed data members to not use "m_"-style names
* Removed use of underscore in front of variable names

#### Script interface
* New functions
	* ItemType.getDestroyId(self)
	* Creature.getEvents(self, type)
	* Player.getBaseMaxHealth(self)
	* Player.getBaseMaxMana(self)
	* Player.addOfflineTrainingTime(self, time)
	* Player.getOfflineTrainingTime(self)
	* Player.removeOfflineTrainingTime(self, time)
	* Player.addOfflineTrainingTries(self, skillType, tries)
	* Player.getOfflineTrainingSkill(self)
	* Player.setOfflineTrainingSkill(self, skillId)

#### Data pack
* Added destroyTo attribute to items.xml, which is the item id that an item can be destroyed to
* Added support for `max` attribute to monster summon tags
* Lots of updates to items, spells and weapons
* Fixed a few issues with disintegrate rune
* Fixed a bug with quests.lua
* Fixed a bug with the create_item talk action that was preventing creation of empty fluid containers
