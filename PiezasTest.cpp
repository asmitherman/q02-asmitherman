/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

//check piece in borad
TEST(PiezasTest, checkBoard)
{	
	Piezas test;
	char piece;
	 piece = test.dropPiece(0);
	 ASSERT_EQ( test.pieceAt(0,0), piece );
}

//check out of bounds
TEST(PiezasTest, checkBadPieceAt)
{	
	Piezas test;
	 ASSERT_EQ( Invalid, test.pieceAt(4,0) );
}

//check pieceAt out of bounds
TEST(PiezasTest, checkBadBoard)
{	
	Piezas test;
	char piece;
	 piece = test.dropPiece(5);
	 ASSERT_EQ( Invalid, piece );
}


//testing reset
TEST(PiezasTest, resetBoard) {
	Piezas test;
	for( int i = 0; i < 4; i++) {
		test.dropPiece(i);
	}
	test.reset();
	ASSERT_EQ(test.pieceAt(0,0), Blank);
}

//test full col
TEST(PiezasTest, checkBadCol)
{	
	Piezas test;
	test.dropPiece(0);
	test.dropPiece(0);
	test.dropPiece(0);
	
	ASSERT_EQ( Blank, test.dropPiece(0));
}

//checks for x win 4 streak
TEST(PiezasTest, checkwinX)
{	
	Piezas test;
	test.dropPiece(0); 
	test.dropPiece(0);
	test.dropPiece(1);
	test.dropPiece(0); 
	test.dropPiece(2); 
	test.dropPiece(1);
	test.dropPiece(3);
	test.dropPiece(3);
	test.dropPiece(2);
	test.dropPiece(1);
	test.dropPiece(2);
	test.dropPiece(3);
	ASSERT_EQ( X, test.gameState());
}

//checks for O win 4 streak
TEST(PiezasTest, checkwinO)
{	
	Piezas test;
	test.dropPiece(0); 
	test.dropPiece(1);
	test.dropPiece(0);
	test.dropPiece(0); 
	test.dropPiece(1);
	test.dropPiece(1);
	test.dropPiece(2); 
	test.dropPiece(2); 
	test.dropPiece(3);
	test.dropPiece(2); 
	test.dropPiece(3);
	test.dropPiece(3);
	ASSERT_EQ( O, test.gameState());
}
//check tie
TEST(PiezasTest, checktie)
{	
	Piezas test;
	test.dropPiece(0); 
	test.dropPiece(1);
	test.dropPiece(2);
	test.dropPiece(3); 
	test.dropPiece(4);
	test.dropPiece(0); 
	test.dropPiece(1);
	test.dropPiece(2);
	test.dropPiece(3); 
	test.dropPiece(4);
	test.dropPiece(0); 
	test.dropPiece(1);
	test.dropPiece(2);
	test.dropPiece(3); 
	test.dropPiece(4);
	ASSERT_EQ( Blank, test.gameState());
}
