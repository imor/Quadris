#ifndef __CRATE_H__
#define __CRATE_H__

#include "Tetramino.h"

class Crate : public Tetramino
{
/* Shape :-
     ____ ____
    | 1  | 2  |
	|____|____|
	| 3	 | 4  |
	|____|____|

	Due to symmetry of crate it is not rotated, hence no rotation anchor point
*/
public:
	void rotateCCW();
	void rotateCW();
	Crate(int originX, int originY, Texture* texture);
};
#endif //__CRATE_H__