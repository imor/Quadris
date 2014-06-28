#ifndef __LEFTL_H__
#define __LEFTL_H__

#include "Tetramino.h"

class LeftL : public Tetramino
{
/* Shape :-
     ____
    | 1  |
	|____|____ ____
	| 2	 | 3  | 4  |
	|____|_+__|____|

	+ indicates rotation anchor point
*/
public:
	LeftL(int originX, int originY, Texture* texture);
};
#endif //__LEFTL_H__