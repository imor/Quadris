#ifndef __TEXTUREFACTORY_H__
#define __TEXTUREFACTORY_H__

#include "Texture.h"
#include <map>
#include <string>

class TextureFactory
{
public:
	TextureFactory(SDL_Renderer* sdlRenderer);
	~TextureFactory();
	Texture* Create(std::string file);
private:
	std::map<std::string, Texture*> textures;
	SDL_Renderer* sdlRenderer;
};

#endif //__TEXTUREFACTORY_H__