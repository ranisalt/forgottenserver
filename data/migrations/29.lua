function onUpdateDatabase()
	print("> Updating database to version 29 (delta player item updating)")
	db.query("ALTER TABLE `player_items` ADD `updated` TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, ADD UNIQUE (`player_id`, `pid`, `sid`)");
	return true
end
