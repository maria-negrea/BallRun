#pragma once
#include"Textures.h"
#include"WorldObject.h"


class Mountain:public WorldObject
{
private:
	GLfloat inaltime;
public:
	Mountain();
	Mountain(GLfloat width, GLfloat  height, GLfloat inaltime);
    
	~Mountain();
	void DrawObject();
};
