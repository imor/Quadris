#include "TextureFactory.h"

TextureFactory::TextureFactory(SDL_Renderer* sdlRenderer) :
sdlRenderer(sdlRenderer)
{

}

TextureFactory::~TextureFactory()
{
	std::map<std::string, Texture*>::const_iterator it;
	for (it = textures.begin(); it != textures.end(); ++it)
	{
		delete it->second;
	}
}

Texture* TextureFactory::Create(std::string file)
{
	std::map<std::string, Texture*>::iterator it = textures.find(file);
	if (it == textures.end())
	{
		Texture* toReturn = new Texture(sdlRenderer, file.c_str());
		textures[file] = toReturn;
		return toReturn;
	}
	
	return it->second;
}