// Copyright 2025 The Forgotten Server Authors. All rights reserved.
// Use of this source code is governed by the GPL-2.0 License that can be found in the LICENSE file.

#ifndef FS_BROWSEFIELD_H
#define FS_BROWSEFIELD_H

#include "container.h"

class BrowseField final : public Container
{
public:
	explicit BrowseField(Tile* tile);
	~BrowseField() override;

	virtual BrowseField* getBrowseField() override { return this; }
	virtual const BrowseField* getBrowseField() const override { return this; }

	bool hasContainerParent() const override { return false; }

	ReturnValue queryAdd(int32_t index, const Thing& thing, uint32_t count, uint32_t flags,
	                     Creature* actor = nullptr) const override;
};

#endif
