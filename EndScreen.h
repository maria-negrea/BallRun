#pragma once

#include "WorldObject.h"
#include "Textures.h"

class EndScreen : public WorldObject
{
	private:
		void DrawObject();
	public:
		EndScreen();
		~EndScreen();
};
