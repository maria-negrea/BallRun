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
	GLuint texture[1];
public:
	Textures(void);
	~Textures(void);

	void LoadGLTextures();
	GLuint* GetTextures();
};
