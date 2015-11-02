#include "test.h"

int triangle(int a, int b ,int c)
{
	bool isTriangle;
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
		isTriangle = false;
	}
	else if( b + c <= a )
	{
		isTriangle = false;
	}
	else if( a + c <= b )
	{
		isTriangle = false;
	}
	else
	{
		isTriangle = true;
	}

	// third part
	if( isTriangle )
	{
		if( a == b && b == c )
		{
			return 1;
		}
		else if ( a != b && a != c && b != c )
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}

	return -2;
}
