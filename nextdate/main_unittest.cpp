#include "test.h"
#include <gtest/gtest.h>

testing::AssertionResult CheckDate( const char* m_expr, const char* d_expr, const char* y_expr, const char* p_expr,
									const int m, const int d, const int y, const date testdate) {
	bool equal = true;

	// invaild date
	if( y == -1 && testdate.year == -1 )
	{
		return testing::AssertionSuccess();
	}
	else if( y == -1 )
	{
		testing::Message msg;
		msg << "The input date is invaild, it have to set year to -1";
		return testing::AssertionFailure(msg);
	}
	else
	{
		if( y != testdate.year )
		{
			equal = false;
		}
		else if( m != testdate.month )
		{
			equal = false;
		}
		else if( d != testdate.day )
		{
			equal = false;
		}
	}
	
	if( !equal )
	{
		testing::Message msg;
		msg << "The nextdate is ";
		msg << y << "-" << m << "-" << d;
		msg << " not ";
		msg << testdate.year << "-" << testdate.month << "-" << testdate.day;
		return testing::AssertionFailure(msg);
	}
	else
	{
		return testing::AssertionSuccess();
	}
}

TEST(NextDateTest, HandleNoneZeroInput)
{
	date test;
	
	// sample test
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , 1812, nextdate( 1, 1, 1812));

	// test in valid date

	// year
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 1, 1, 1811));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 1, 1, 2013));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 1, 1, 0));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 1, 1, -1));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 1, 1, 10000));
	
	// month
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 0, 1, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 13, 1, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( -1, 1, 1812));

	// day
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 1, 0, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 1, 32, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 1, -1, 1812));

	// month 1,3,5,7,8,10,10 ->  day <= 31
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 1, 32, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 3, 32, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 5, 32, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 7, 32, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 8, 32, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 10, 32, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 12, 32, 1812));

	// month 4,6,9,11 -> day <= 30
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 4, 31, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 6, 31, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 9, 31, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 11, 31, 1812));
	
	// month 2 -> 
	// leap year -> day <= 29
	//	   (mod 4 = 0 and mod 100 != 0 ) or (mod 400 = 0 )

	// other	 -> day <= 28

	// leap test
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 2, 30, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 2, 30, 1816));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 2, 30, 2012));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 2, 30, 2000));
	// other test
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 2, 29, 1813));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 2, 29, 1814));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 2, 29, 1900));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 2, 29, 2011));
	EXPECT_PRED_FORMAT4( CheckDate, 0, 0 , -1, nextdate( 2, 29, 1999));

}
