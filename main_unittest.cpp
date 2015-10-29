#include "test.h"
#include <gtest/gtest.h>

TEST(TriangleTest, HandleNoneZeroInput)
{
	// Return value
	// -1 : is not in range
	// -2 : is not a triangle

	
	// test c
    EXPECT_EQ(-1, triangle(1, 1, 0));
    EXPECT_EQ(-1, triangle(1, 1, 201));

	// test b
    EXPECT_EQ(-1, triangle(1, 0, 1));
    EXPECT_EQ(-1, triangle(1, 201, 1));

	// test a
    EXPECT_EQ(-1, triangle(0, 1, 1));
    EXPECT_EQ(-1, triangle(201, 1, 1));

	//  test triangle

	// a + b <= c
    EXPECT_EQ(-2, triangle(2, 6, 10));
    EXPECT_EQ(-2, triangle(1, 3, 5));
    EXPECT_EQ(-2, triangle(2, 3, 5));
	
	// b + c <= a
    EXPECT_EQ(-2, triangle(100, 20, 60));
    EXPECT_EQ(-2, triangle(200, 198, 1));
    EXPECT_EQ(-2, triangle(200, 198, 2));

	// a + c <= b
    EXPECT_EQ(-2, triangle( 10, 200, 20));
    EXPECT_EQ(-2, triangle( 99, 200, 99));
    EXPECT_EQ(-2, triangle( 100, 200, 100));

}
