#include "test.h"
#include <gtest/gtest.h>

TEST(TriangleTest, HandleNoneZeroInput)
{
	// Return value
	// -1 : is not in range
	// -2 : is not a triangle
	// 1 : Equilateral
	// 2 : Scalene
	// 3 : Isosceles
	
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

	// test what triangle

	// Equilateral triangle
    EXPECT_EQ(1, triangle( 1, 1, 1));
    EXPECT_EQ(1, triangle( 99, 99, 99));
    EXPECT_EQ(1, triangle( 200, 200, 200));

	// Scalene triangle
    EXPECT_EQ(2, triangle( 2, 3, 4));
    EXPECT_EQ(2, triangle( 6, 8, 9));
    EXPECT_EQ(2, triangle( 87, 56, 42));
    EXPECT_EQ(2, triangle( 31, 22, 33));
    EXPECT_EQ(2, triangle( 123, 32, 92));
    EXPECT_EQ(2, triangle( 62, 61, 60));


	// Isosceles triangle 
    EXPECT_EQ(3, triangle( 2, 2, 1));
    EXPECT_EQ(3, triangle( 2, 1, 2));
    EXPECT_EQ(3, triangle( 1, 2, 2));
    EXPECT_EQ(3, triangle( 99, 100, 99));
    EXPECT_EQ(3, triangle( 99, 99, 100));
    EXPECT_EQ(3, triangle( 100, 99, 99));
    EXPECT_EQ(3, triangle( 200, 99, 200));
    EXPECT_EQ(3, triangle( 90, 200, 200));
    EXPECT_EQ(3, triangle( 200, 200, 50));

	
}
