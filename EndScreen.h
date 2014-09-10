#pragma once

#include "WorldObject.h"
#include "Textures.h"

/*! \brief
* Draws the quad which appears when the game ends
*/
class EndScreen : public WorldObject
{
	private:
		void DrawObject();
	public:
		EndScreen();
		~EndScreen();
};
