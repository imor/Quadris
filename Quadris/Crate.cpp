#include "Crate.h"

using namespace std;

Crate::Crate(int originX, int originY, Texture* texture) :
	Tetramino(originX, originY, texture)
{
	blockOffsets[0].setX(0);
	blockOffsets[0].setY(0);

	blockOffsets[1].setX(texture->getWidth());
	blockOffsets[1].setY(0);

	blockOffsets[2].setX(0);
	blockOffsets[2].setY(texture->getHeight());

	blockOffsets[3].setX(texture->getWidth());
	blockOffsets[3].setY(texture->getHeight());
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