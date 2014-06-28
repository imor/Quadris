#ifndef __SLAB_H__
#define __SLAB_H__

#include "Tetramino.h"

class Slab : public Tetramino 
{
/* Shape :-
     ____ ____ ____ ____
	| 1  | 2  | 3  | 4  |
	|____|_+__|____|____|

	+ indicates rotation anchor point
*/
public:
	void rotateCCW();
	void rotateCW();
	Slab(int originX, int originY, Texture* texture);
private:
	void setRotation();
};

#endif //__SLAB_H__