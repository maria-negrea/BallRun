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

struct String
{
	string value;

	String(string value)
		:value(value)
	{
	}

	friend bool operator<(String const& s1, String const& s2);
};

class Textures
{
private:
	static Textures *instance;
	map<String,GLuint> texture;
	Textures();
public:
	~Textures();

	static Textures* GetInstance();

	void LoadGLTextures();
	GLuint GetTexture(string name);
};
