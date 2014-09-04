#pragma once
#include<iostream>
#include"SOIL.h"
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif

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
