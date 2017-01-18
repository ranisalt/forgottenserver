=====================
* Rewrite the Lua NPC system
* Built-in HTTP JSON API using Lua scripts to get real-time data from the server
  * should replace the status protocol
* Rewrite admin protocol
	* allow clients to send Lua code for the server to execute
	* alternatively, store Lua scripts on the server and allow the admin protocol to run the scripts (safer)
* Add stronger hashing options
	* perhaps PBKDF2/scrypt
	* preferably without external dependencies
* Custom item attributes
* Lua scripts for quests
* XTEA SIMD
* XML tag for each flag in groups.xml with value 0 or 1 to make it more maintainable instead of a single int representing the value for all flags
* Dropping boost dependency:
  * use asio C++ library
  * monitor progress of C++17 networking
    * could take quite long before this makes it into Linux distributions like Debian GNU/Linux stable
  * consider the opposite if it can't be dropped, making more use of boost because we're depending on it anyway
* Consider major changes to map, tile and item structures to decrease memory usage
  * must not negatively affect the performance of Map::getSpectatorsInternal, Map::getPathMatching, Map::getTile or ProtocolGame::GetTileDescription
* Update all log messages to be consistent
* Rename functions and variables that begin with underscore as they are reserved
* Move old Lua functions to compat.lua
* Move commands to talkactions
* onStepIn/onStepOut return value should matter, return false should cancel the step, default to return true
* Idle state for NPCs
	* there is no reason for NPCs to walk or talk if no one is there to see it
* Support custom RSA keys
	* IP Changers must support this, should be supported by the otserv:// specifier, the public key could be specified after version, e.g.:
		* otserv://shadowcores.twifysoft.net/7171/1041/**publickey**
* Remove const_cast where possible
* Improve database schema
	* Consider changes proposed by DevAAC: https://github.com/DevelopersPL/DevAAC/wiki/Recommended-DB-schema-changes
