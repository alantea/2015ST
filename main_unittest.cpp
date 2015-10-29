#include "test.h"
#include <gtest/gtest.h>

TEST(TriangleTest, HandleNoneZeroInput)
{
	// Return value
	// -1 : is not in range
	// 0 : is triangle

	// test the line is in the define
	
	// test c
    EXPECT_EQ(-1, triangle(1, 1, 0));
    EXPECT_EQ(-1, triangle(1, 1, 201));
    EXPECT_EQ(0, triangle(1, 1, 1));
    EXPECT_EQ(0, triangle(1, 1, 200));

	// test b
    EXPECT_EQ(-1, triangle(1, 0, 1));
    EXPECT_EQ(-1, triangle(1, 201, 1));
    EXPECT_EQ(0, triangle(1, 2, 1));
    EXPECT_EQ(0, triangle(1, 200, 1));

	// test a
    EXPECT_EQ(-1, triangle(0, 1, 1));
    EXPECT_EQ(-1, triangle(201, 1, 1));
    EXPECT_EQ(0, triangle(2, 1, 1));
    EXPECT_EQ(0, triangle(200, 1, 1));
}
