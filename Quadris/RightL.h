#ifndef __RIGHTL_H__
#define __RIGHTL_H__

#include "Tetramino.h"

class RightL : public Tetramino
{
/* Shape :-
               ____
              | 1  |
	 ____ ____|____|
	| 2	 | 3  | 4  |
	|____|_+__|____|

	+ indicates rotation anchor point
*/
public:
	RightL(int originX, int originY, Texture* texture);
};
#endif //__RIGHTL_H__