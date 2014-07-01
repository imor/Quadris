#include "RightL.h"

using namespace std;

RightL::RightL(int originX, int originY, Texture* texture) :
	Tetramino(originX, originY, 2, texture)
{
	setOrigin(originX, originY);
}

void RightL::setOrigin(int x, int y)
{
	blockPositions[0].setX(x + texture->getWidth());
	blockPositions[0].setY(y - texture->getHeight());

	blockPositions[1].setX(x - texture->getWidth());
	blockPositions[1].setY(y);

	blockPositions[2].setX(x);
	blockPositions[2].setY(y);

	blockPositions[3].setX(x + texture->getWidth());
	blockPositions[3].setY(y);
}
