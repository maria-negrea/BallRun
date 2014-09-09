#pragma once
#include<iostream>
#include<string>
#include<map>
#include"SOIL.h"

#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif

using namespace std;

class Textures
{
private:
	static Textures *instance;
    GLuint textures[7];
	Textures();
public:
	~Textures();
	GLuint* GetTextures();
	static Textures* GetInstance();
	void LoadGLTextures();
};
