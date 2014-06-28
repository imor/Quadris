#include "Game.h"
#include "Tetramino.h"
#include "Grid.h"
#include <iostream>
#include <ctime>
#include <vector>

TextureFactory* theTextureFactory;

Game::Game()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		//TODO:throw exception
		//return 1;
	}
	sdlWindow = SDL_CreateWindow("Quadris", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (sdlWindow == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		//TODO:throw exception
		//return 1;
	}
	sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (sdlRenderer == nullptr)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		//TODO:throw exception
		//return 1;
	}

	SDL_GetWindowSize(sdlWindow, &windowWidth, &windowHeight);
	theTextureFactory = new TextureFactory(sdlRenderer);
}

int Game::Run()
{
	SDL_Event e;
	bool quit = false;
	bool tetraminoDropping = false;

	Texture* texture = theTextureFactory->Create(".\\media\\gridBlock.bmp");
	const unsigned int gridWidth = 10;
	const unsigned int gridHeight = 22;
	unsigned int gridOriginX = (windowWidth - gridWidth * texture->getWidth()) / 2;
	unsigned int gridOriginY = (windowHeight - gridHeight * texture->getHeight()) / 2;

	reset(gridOriginX, gridOriginY, gridWidth, gridHeight, texture);

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN && !tetraminoDropping)
			{
				const std::vector<Point>* wallKicks;
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					currentTetramino->rotateCW();
					wallKicks = currentTetramino->getWallKickData();
					unsigned int i;
					for (i = 0; i < wallKicks->size(); ++i)
					{
						currentTetramino->offset(wallKicks->at(i).getX(), wallKicks->at(i).getY());
						if (grid->isValidPosition(*currentTetramino))
						{
							break;
						}
						else
						{
							currentTetramino->offset(-wallKicks->at(i).getX(), -wallKicks->at(i).getY());
						}
					}
					if (i == wallKicks->size())
					{
						currentTetramino->rotateCCW();
					}
					break;
				case SDLK_RIGHT:
					if (grid->canMoveRight(*currentTetramino))
					{
						currentTetramino->moveRight();
					}
					break;
				case SDLK_DOWN:
					if (!grid->touchingFloorOrBlock(*currentTetramino))
					{
						currentTetramino->moveDown();
					}
					break;
				case SDLK_LEFT:
					if (grid->canMoveLeft(*currentTetramino))
					{
						currentTetramino->moveLeft();
					}
					break;
				case SDLK_SPACE:
					tetraminoDropping = true;
					break;
				default:
					break;
				}
			}
		}

		Uint32 currentTicks = SDL_GetTicks();
		Uint32 diff = currentTicks - lastTicks;
		if (diff > 1000 || tetraminoDropping)
		{
			if (grid->touchingFloorOrBlock(*currentTetramino))
			{
				grid->addTetraminoToGrid(*currentTetramino);
				int lines = grid->removeCompletedLines();
				delete currentTetramino;
				currentTetramino = Tetramino::getRandomTetramino(gridOriginX, gridOriginY);
				if (grid->touchingFloorOrBlock(*currentTetramino))
				{
					reset(gridOriginX, gridOriginY, gridWidth, gridHeight, texture);
				}
				tetraminoDropping = false;
			}
			else
			{
				currentTetramino->moveDown();
			}
			
			if (diff > 1000)
			{
				lastTicks = currentTicks;
			}
		}

		SDL_RenderClear(sdlRenderer);
		grid->draw();
		currentTetramino->draw(gridOriginY + 2 * texture->getHeight());
		SDL_RenderPresent(sdlRenderer);
	}

	return 0;
}

void Game::reset(unsigned int gridOriginX, unsigned int gridOriginY,
	unsigned int gridWidth, unsigned int gridHeight, Texture* gridTexture)
{
	grid = new Grid(gridOriginX, gridOriginY, gridWidth, gridHeight, gridTexture);
	currentTetramino = Tetramino::getRandomTetramino(gridOriginX, gridOriginY);
	lastTicks = SDL_GetTicks();
}

Game::~Game()
{
	delete theTextureFactory;
	delete currentTetramino;
	delete grid;
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();
}
