#include "Texture.h"
#include <iostream>

Texture::Texture(SDL_Renderer* sdlRenderer, const char* file) :
sdlRenderer(sdlRenderer)
{
	SDL_Surface *bmp = SDL_LoadBMP(file);
	if (bmp == nullptr)
	{
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		//TODO:throw exception
		//return 1;
	}
	sdlTexture = SDL_CreateTextureFromSurface(sdlRenderer, bmp);
	SDL_FreeSurface(bmp);
	if (sdlTexture == nullptr)
	{
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		//TODO:throw exception
		//return 1;
	}
	SDL_QueryTexture(sdlTexture, NULL, NULL, &positionAndSize.w, &positionAndSize.h);
}

Texture::~Texture()
{
	SDL_DestroyTexture(sdlTexture);
}

void Texture::draw(int x, int y)
{
	positionAndSize.x = x;
	positionAndSize.y = y;

	SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, &positionAndSize);
}
