#include "otpch.h"

#include "browsefield.h"

#include "game.h"

extern Game g_game;

BrowseField::BrowseField(Tile* tile) : Container{ITEM_BROWSEFIELD, 30, false, true}
{
	TileItemVector* itemVector = tile->getItemList();
	if (itemVector) {
		for (Item* item : *itemVector) {
			if ((item->getContainer() || item->hasProperty(CONST_PROP_MOVEABLE)) &&
			    !item->hasAttribute(ITEM_ATTRIBUTE_UNIQUEID)) {
				itemlist.push_front(item);
				item->setParent(this);
				item->incrementReferenceCounter();
			}
		}
	}

	setParent(tile);
}

BrowseField::~BrowseField()
{
	g_game.browseFields.erase(getTile());

	for (Item* item : itemlist) {
		item->setParent(parent);
	}
}

ReturnValue BrowseField::queryAdd(int32_t index, const Thing& thing, uint32_t count, uint32_t flags,
                                  Creature* actor = nullptr) const
{
	return RETURNVALUE_NOTPOSSIBLE;
}
