#include "test.h"

int triangle(int a, int b ,int c)
{
	// first part test range
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
		return -1;
	}

	// second part: check triangle
	if( a + b <= c )
	{
		return -2;
	}
	else if( b + c <= a )
	{
		return -2;
	}
	else if( a + c <= b )
	{
		return -2;
	}

	return 0;
}
