#include "test.h"

int triangle(int a, int b ,int c)
{
	// first part
	if( !(a >= 1 && a <= 200 ) )
	{
		return -1;
	}
	else if( !(b >= 1 && b <= 200 ) )
	{
		return -1;
	}
	else if( !(c >= 1 && c <= 200 ) )
	{
		return 0;
	}


	return 0;
}
