#pragma once

#include "WorldObject.h"

class Curve : public WorldObject
{
	private:
		void DrawObject();
		int turn;
	public:
		Curve(int TURN);
		~Curve();
		
};
