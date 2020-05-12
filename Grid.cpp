#include "Grid.h"

Grid::Grid(unsigned int originX, unsigned int originY,
		   unsigned int width, unsigned int height, Texture* gridTexture) :
		   originX(originX), originY(originY),
		   width(width), height(height), score(0),
		   numberOfLinesCompleted(0),
		   gridTexture(gridTexture)
{
	cleanUp();
}

void Grid::draw()
{
	for(unsigned int x = 0;x < blocks.size();x++)
	{
		for(unsigned int y = 2;y < blocks[x].size();y++)
		{
			if(blocks[x][y])
			{
				blockTextures[x][y]->draw(originX + x * gridTexture->getWidth(),
					originY + y * gridTexture->getHeight());
			}
			else
			{
				gridTexture->draw(originX + x * gridTexture->getWidth(),
					originY + y * gridTexture->getHeight());
			}
		}
	}
}

bool Grid::canMoveLeft(Tetramino& tetramino)
{
	std::deque<Point> tetraminoBlockPositions = tetramino.getBlockPositions();
	int blockWidth = tetramino.getTexture()->getWidth();
	int blockHeight = tetramino.getTexture()->getHeight();

	bool againstWallOrBlock = false;
	for (unsigned int i = 0; i < tetraminoBlockPositions.size(); i++)
	{
		if (tetraminoBlockPositions[i].getX() == originX)
		{
			againstWallOrBlock = true;
			break;
		}
		unsigned int x = (tetraminoBlockPositions[i].getX() - originX) / blockWidth - 1;
		unsigned int y = (tetraminoBlockPositions[i].getY() - originY) / blockHeight;
		if (x >= 0 && x < width && blocks[x][y])
		{
			againstWallOrBlock = true;
			break;
		}
	}

	return !againstWallOrBlock;
}

bool Grid::canMoveRight(Tetramino& tetramino)
{
	std::deque<Point> tetraminoBlockPositions = tetramino.getBlockPositions();
	int blockWidth = tetramino.getTexture()->getWidth();
	int blockHeight = tetramino.getTexture()->getHeight();

	bool againstWallOrBlock = false;
	for (unsigned int i = 0; i < tetraminoBlockPositions.size(); i++)
	{
		if (tetraminoBlockPositions[i].getX() == originX + (width - 1) * blockWidth)
		{
			againstWallOrBlock = true;
			break;
		}
		unsigned int x = (tetraminoBlockPositions[i].getX() - originX) / blockWidth + 1;
		unsigned int y = (tetraminoBlockPositions[i].getY() - originY) / blockHeight;
		if (x >= 0 && x < width && blocks[x][y])
		{
			againstWallOrBlock = true;
			break;
		}
	}

	return !againstWallOrBlock;
}

bool Grid::isValidPosition(Tetramino& tetramino)
{
	std::deque<Point> tetraminoBlockPositions = tetramino.getBlockPositions();
	int blockWidth = tetramino.getTexture()->getWidth();
	int blockHeight = tetramino.getTexture()->getHeight();

	for (unsigned int i = 0; i < tetraminoBlockPositions.size(); i++)
	{
		int x = (tetraminoBlockPositions[i].getX() - static_cast<int>(originX)) / blockWidth;
		int y = (tetraminoBlockPositions[i].getY() - static_cast<int>(originY)) / blockHeight;
		if (x < 0 || x >= static_cast<int>(width) || y < 0 || y >= static_cast<int>(height) || blocks[x][y])
		{
			return false;
		}
	}

	return true;
}

bool Grid::touchingFloorOrBlock(Tetramino& tetramino)
{
	std::deque<Point> tetraminoBlockPositions = tetramino.getBlockPositions();
	int blockWidth = tetramino.getTexture()->getWidth();
	int blockHeight = tetramino.getTexture()->getHeight();

	for (unsigned int i = 0; i < tetraminoBlockPositions.size(); i++)
	{
		int x = (tetraminoBlockPositions[i].getX() - static_cast<int>(originX)) / blockWidth;
		int y = (tetraminoBlockPositions[i].getY() - static_cast<int>(originY)) / blockHeight;
		if (y == height - 1 || blocks[x][y + 1])
		{
			return true;
		}
	}

	return false;
}

void Grid::addTetraminoToGrid(Tetramino& tetramino)
{
	std::deque<Point> tetraminoBlockPositions = tetramino.getBlockPositions();
	int blockWidth = tetramino.getTexture()->getWidth();
	int blockHeight = tetramino.getTexture()->getHeight();

	for(unsigned int i = 0;i < tetraminoBlockPositions.size();i++)
	{
		int x = (tetraminoBlockPositions[i].getX() - static_cast<int>(originX)) / blockWidth;
		int y = (tetraminoBlockPositions[i].getY() - static_cast<int>(originY)) / blockHeight;

		blocks[x][y] = true;
		blockTextures[x][y] = tetramino.getTexture();
	}
}

int Grid::removeCompletedLines()
{
	int y = height - 1;
	int currentCompletedLines = 0;
	while(y >= 0)
	{
		bool lineCompleted = true;
		for(unsigned int x = 0;x < blocks.size();x++)
		{
			if(!blocks[x][y])
			{
				lineCompleted = false;
				break;
			}
		}
		if(lineCompleted)
		{
			currentCompletedLines++;
			score += currentCompletedLines * 10;
			int i = y;
			while (i > 0)
			{
				for (unsigned int x = 0; x < blocks.size(); x++)
				{
					blocks[x][i] = blocks[x][i - 1];
					blockTextures[x][i] = blockTextures[x][i - 1];
				}
				i--;
			}
			for (unsigned int x = 0; x < blocks.size(); x++)
			{
				blocks[x][0] = false;
				blockTextures[x][0] = nullptr;
			}
			y = height - 1;
		}
		else
		{
			y--;
		}
	}
	numberOfLinesCompleted += currentCompletedLines;
	return currentCompletedLines;
}

bool Grid::gameOver() const
{
	for(unsigned int i = 0;i < blocks.size();i++)
	{
		if(blocks[i][0])
		{
			return true;
		}
	}
	return false;
}

void Grid::cleanUp()
{
	blocks.clear();
	blockTextures.clear();
	blocks.resize(width);
	blockTextures.resize(width);
	
	for(unsigned int i = 0;i < blocks.size(); i++)
	{
		blocks[i].clear();
		blockTextures[i].clear();
		blocks[i].resize(height);
		blockTextures[i].resize(height);
	}
}
