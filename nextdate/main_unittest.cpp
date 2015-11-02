#include "test.h"
#include <gtest/gtest.h>

testing::AssertionResult CheckDate( const char* m_expr, const char* d_expr, const char* y_expr, const char* p_expr,
									const int m, const int d, const int y, const date testdate) {
	bool equal = true;

	// invaild date
	if( y == -1 && testdate.year == -1 )
	{

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

	EXPECT_PRED_FORMAT4( CheckDate, 1, 12 , 1970, nextdate( 1, 11, 1970));
}
