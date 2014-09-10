#pragma once

#include "WorldObject.h"


/*! \brief
* Draws the rounded edges when we generate a turn
*/
class Curve : public WorldObject
{
	private:
		void DrawObject();
		int turn; /*!< The rotation of the crossing: 1 -> right, 2 -> left, 3 -> both */
	public:
		Curve(int TURN);
		~Curve();
		
};
