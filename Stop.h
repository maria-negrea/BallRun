#pragma once

#include "WorldObject.h"
#include "Textures.h"

class Stop : public WorldObject
{
	private:
		void DrawObject();
	public:
		Stop();
		~Stop();
};

