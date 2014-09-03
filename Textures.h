#pragma once
#include<iostream>
#include"SOIL.h"
#include"glut.h"

class Textures
{
private:
	GLuint texture[1];
public:
	Textures(void);
	~Textures(void);

	void LoadGLTextures();
	GLuint* GetTextures();
};
