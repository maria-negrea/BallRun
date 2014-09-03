#include "Textures.h"


Textures::Textures(void)
{
}

Textures::~Textures(void)
{
}

void Textures::LoadGLTextures()
{
	texture[0] = SOIL_load_OGL_texture
        (
        "Assets/Batman.bmp",
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