#ifndef __GAME_H__
#define __GAME_H__

#include "SDL.h"
#include "TextureFactory.h"
#include "Grid.h"
#include "Tetramino.h"

extern TextureFactory* theTextureFactory;

class Game
{
public:
	Game();
	~Game();
	int Run();
private:
	void reset(unsigned int originX, unsigned int originY,
		unsigned int width, unsigned int height, Texture* gridTexture);
	SDL_Renderer* sdlRenderer;
	SDL_Window *sdlWindow;
	int windowWidth;
	int windowHeight;
	Grid* grid;
	Tetramino* currentTetramino;
	Uint32 lastTicks;
};

#endif// __GAME_H__