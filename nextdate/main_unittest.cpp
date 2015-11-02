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
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 1, 1, 1811));
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 1, 1, 2013));
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 1, 1, 0));
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 1, 1, -1));
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 1, 1, 10000));
	
	// month
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 0, 1, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 13, 1, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( -1, 1, 1812));

	// day
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 1, 0, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 1, 32, 1812));
	EXPECT_PRED_FORMAT4( CheckDate, 1, 2 , -1, nextdate( 1, -1, 1812));
}
