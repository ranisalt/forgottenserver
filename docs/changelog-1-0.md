=====================
#### Engine
* Complete invisibility for monsters (no longer visible to client when they are invisible)
* Rework damage messages to group elemental damages as secondary in the same damage packet
* Using pugixml (header-only library) instead of libxml2
* Moved global server save code to startup.lua
* Optimized hangables code
* Optimized removeItemOfType (around twice as fast)
* Optimized PropWriteStream allocation strategy and significantly decreased amount of heap allocations done during saves
* Optimized clean map code (~130x speedup)
* Significantly reduced memory footprint (over 15%)
* Removed admin protocol
* Removed exception tracer
* Removed GUI
* Removed ingame account manager
* Removed SimOne's XML NPC system
* Removed relational and binary house storage (no longer configurable, binary-tilebased is always used now)
* Removed unused heal map
* Removed builtin server save each minutes and global server save code and added an example global event for a global server save
* Removed MD5 and plaintext as a password type options
* Rewritten SHA-1 implementation
* Fixed bugs with hangables
* Fixed possible crash with monster spells
* Fixed bug with /reload items
* Fixed memory leak with reload command on script environments
* Fixed client debug assertions with large packets

#### Features
* Game protocol 10.41 support
* Browse Field
* You can now choose default outfits by unlocking them in outfits.xml
* You can now specify skulls for monsters and NPCs in their xml file
* Party bonus shared experience is now based on amount of unique vocations
* Left hand equipment slot is now only for weapons and right hand for shields, you can use the old setting by changing classicEquipmentSlots to "yes" in config.lua

#### Security
* Added timestamp and random value to gameworld authentication packet to prevent MITM attacks
* Added protection against packet flood
	* maxPacketsPerSecond in config.lua
* Improved protection against connection flood
* Fixed buffer overflow in NetworkMessage
* Fixed issues in the RSA implementation

#### Source code
* Moved to GitHub
* Using C++11 features
* Improved portability
	* Now compiles on FreeBSD and Mac OS X
* Removed libboost_regex dependency
* Removed libboost_thread dependency
* Removed libxml2 dependency

#### Database
* Added table guild_membership and removed rank_id and guildnick from players table
* New bans structure
* Removed SQLite database driver (only supports MySQL now)
* Storing online players in players_online (online column removed from players)
* Storing player skills in players table instead of player_skills
* Storing player record in database instead of playersRecord.txt
* Storing message of the day data in database instead of lastMotd.txt
* Possibility to use UNIX socket instead of TCP connection to MySQL (mysqlSock in config.lua)
* Recover from CR_SERVER_LOST and CR_SERVER_GONE_ERROR errors in Database (block threads until we're reconnected)

#### Script interface
* Events
	* Party
		* onJoin
		* onLeave
		* onDisband
	* Player
		* onLook
		* onLookInBattleList
		* onLookInTrade
		* onLookInShop
		* onMoveItem
		* onMoveCreature
		* onTurn
		* onTradeRequest
		* onTradeAccept
		* onGainExperience
		* onLoseExperience
* Global script interface
* Lua 5.2 compatibility
* Chat channel events
	* canJoin(cid)
	* onJoin(cid)
	* onLeave(cid)
	* onSpeak(cid, type, message)
* Lua event onPrepareDeath has been enabled for all creatures
* Lua metatables to represent classes
	* Combat
	* Condition
	* Creature
		* Monster
		* Npc
		* Player
	* Game
	* Group
	* Guild
	* House
	* Item
		* Container
		* Teleport
	* ItemType
	* ModalWindow
	* MonsterType
	* NetworkMessage
	* Party
	* Position
	* Town
	* Tile
	* Vocation
* New creature events
	* onModalWindow(player, modalWindowId, buttonId, choiceId)
	* onTextEdit(player, item, text)
	* onExtendedOpcode(player, opcode, buffer)
	* onHealthChange(creature, attacker, primaryDamage, primaryType, secondaryDamage, secondaryType, origin)
	* onManaChange(creature, attacker, manaChange, origin)
* Moved database migrations to scripts in data/migrations/
* Moved old Lua functions to compat.lua and implemented them using the new metatable functions

#### Data pack
* Added bed modification kits script
* Moved groups from database to data/XML/groups.xml
* Moved almost all commands to talkactions
* Added offline training statues script
* Updated rope scripts
* Updated items
* Updated monsters
* Updated spells