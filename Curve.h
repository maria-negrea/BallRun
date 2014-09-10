#pragma once

#include "WorldObject.h"

class Curve : public WorldObject
{
	private:
		void DrawObject();
		int turn; /*!< The rotation of the crossing: 1 -> right, 2 -> left, 3 -> both */
	public:
		Curve(int TURN);
		~Curve();
		
};
