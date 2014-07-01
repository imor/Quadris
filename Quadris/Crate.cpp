#include "Crate.h"

using namespace std;

Crate::Crate(int originX, int originY, Texture* texture) :
	Tetramino(originX, originY, 0, texture)
{
	setOrigin(originX, originY);
}

void Crate::rotateCCW()
{
	//do nothing, due to symmetry of the crate it doesn't change apperance
	//after rotation
}

void Crate::rotateCW()
{
	//do nothing, due to symmetry of the crate it doesn't change apperance
	//after rotation
}

void Crate::setOrigin(int x, int y)
{
	blockPositions[0].setX(x);
	blockPositions[0].setY(y);

	blockPositions[1].setX(x + texture->getWidth());
	blockPositions[1].setY(y);

	blockPositions[2].setX(x);
	blockPositions[2].setY(y + texture->getHeight());

	blockPositions[3].setX(x + texture->getWidth());
	blockPositions[3].setY(y + texture->getHeight());
}
