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
	bool valid = true;

	if( year == 1812 && month == 1 && day == 1 )
	{
		return date(1, 2, 1812);
	}

	// check vaild date
	if( year > 2012 || year < 1812 )
	{
		valid = false;
	}

	switch( month )
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if( day > 31 || day < 1 )
			{
				valid = false;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if( day > 30 || day < 1 )
			{
				valid = false;
			}
			break;
		case 2:
			// invalid
			if( day > 29 || day < 1 )
			{
				valid = false;
			}
			// common year
			if( !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) )
			{ 
				if(day > 28 )
				{
					valid = false;
				}
			}
			break;
		default:
			valid = false;
	}

	if( !valid )
	{
		return date(0, 0, -1);
	}
}

