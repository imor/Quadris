#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "SDL.h"

class Texture
{
public:
	Texture(SDL_Renderer* sdlRenderer, const char* file);
	~Texture();
	void draw(int x, int y);
	int getWidth();
	int getHeight();
private:
	SDL_Rect positionAndSize;
	SDL_Renderer* sdlRenderer;
	SDL_Texture* sdlTexture;
};

inline int Texture::getWidth()
{
	return positionAndSize.w;
}

inline int Texture::getHeight()
{
	return positionAndSize.h;
}

#endif // __TEXTURE_H__