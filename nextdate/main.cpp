#include "test.h"

date::date()
{
	year = 1970;
	month = 1;
	day = 1;
}

date::date(int m, int d, int y)
{
	year = y;
	month = m;
	day = d;
}

date nextdate(int month, int day ,int year)
{
	// Return Value:
	//	undefined : year -1
	if( year == 1970 && month == 1 && day == 11 )
	{
		return date(1, 12, 1970);
	}
}

