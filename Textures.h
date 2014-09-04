#pragma once
#include<iostream>
#include"SOIL.h"
#include"glut.h"

class Textures
{
private:
	static Textures *instance;
	GLuint texture[1];
	Textures();
public:
	~Textures();

	static Textures* GetInstance();

	void LoadGLTextures();
	GLuint* GetTextures();
};
