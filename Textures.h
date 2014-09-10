#pragma once
#include<iostream>
#include<string>
#include"SOIL.h"

#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif

using namespace std;

/*! \brief
	Class used to load textures for our objects. We used SOIL to load all of the textures and use them.
*/
class Textures
{
private:
	static Textures *instance; /** <static instance of the class used for Singleton */
    GLuint textures[7]; /** <vector containing all the textures */
	/** Private constructor */
	Textures();
public:
	/** Destructor */
	~Textures(); 
	/** Return the textures vector */
	GLuint* GetTextures();
	/** Return the global instance of our class */
	static Textures* GetInstance();
	/** Load all the textures which are used */
	void LoadGLTextures();
};
