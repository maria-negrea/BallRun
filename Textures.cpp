#include "Textures.h"

Textures::Textures()
{
}

Textures::~Textures()
{
}

Textures* Textures::GetInstance()
{
	if(instance == NULL)
		instance = new Textures();

	return instance;
}

void Textures::LoadGLTextures()
{
	texture[0] = SOIL_load_OGL_texture
        (
        "Assets/tree.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

GLuint* Textures::GetTextures()
{
	return texture;
}