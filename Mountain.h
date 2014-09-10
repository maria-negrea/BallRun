#pragma once
#include"Textures.h"
#include"WorldObject.h"
/**
Class used to draw the mountain
*/

class Mountain:public WorldObject
{
private:
	GLfloat inaltime;/** <atribute to set the height of the mountain */
public:

	Mountain(GLfloat width, GLfloat  height, GLfloat inaltime);/**constructor which receives the the width, the depth and 
															    the height of the mountain */
    
	~Mountain();/** destructor */
	void DrawObject();/**  this method draws the mountain */
};
