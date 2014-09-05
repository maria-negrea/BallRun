#include <fstream>
#include "Textures.h"

using namespace std;

bool operator<(String const& s1, String const& s2)
{
	return s1.value.size() < s2.value.size();
}

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
	ifstream f("textureInput.txt");

	while(!f.eof())
	{
		char name[30];
		f>>name;
		strcat(name,".bmp");
		char result[30] = "Assets/";
		strcat(result,name);
		cout<<result;

		GLuint newTexture = SOIL_load_OGL_texture
        (
			"Assets/building.bmp",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
        );

		texture.insert (std::pair<string,GLuint>(name,newTexture));		
	}
 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

GLuint Textures::GetTexture(string name)
{
	return texture[String(name)];
}