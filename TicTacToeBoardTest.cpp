/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} 
		virtual ~TicTacToeBoardTest(){} 
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, placePiece){
	TicTacToeBoard theBoard;
	Piece test;
	test = theBoard.placePiece(1, 2);	
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to X when placed
}

TEST(TicTacToeBoardTest, placePieceFail){
	TicTacToeBoard theBoard;
	Piece test;
	test = theBoard.placePiece(1, 3);		//Placing a piece out of bounds
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to X when placed
}

TEST(TicTacToeBoardTest, placePieceOverlapX){
	TicTacToeBoard theBoard;
	Piece test;
	theBoard.placePiece(1, 2);	
	theBoard.toggleTurn();
	test = theBoard.placePiece(1, 2);		//Placing a piece where a piece is placed
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to X when placed
}

TEST(TicTacToeBoardTest, toggleTurn){
	TicTacToeBoard theBoard;
	Piece test;
	theBoard.placePiece(1, 2);				//place a piece
	theBoard.toggleTurn();					//toggle the turn
	test = theBoard.toggleTurn();			//toggle the turn again
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to O after a turn has taken place
}

TEST(TicTacToeBoardTest, getWinner){
	TicTacToeBoard theBoard;
	theBoard.placePiece(0, 0);				//place a piece
	theBoard.placePiece(1, 0);				//place a piece
	theBoard.placePiece(2, 0);				//place a piece
	Piece test;
	test = theBoard.getWinner();
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to O after a turn has taken place
}

TEST(TicTacToeBoardTest, getWinnerHorizontal){
	TicTacToeBoard theBoard;
	theBoard.placePiece(0, 0);				//place a piece
	theBoard.placePiece(0, 1);				//place a piece
	theBoard.placePiece(0, 2);				//place a piece
	Piece test;
	test = theBoard.getWinner();
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to O after a turn has taken place
}

TEST(TicTacToeBoardTest, getWinnerDiagonalToRight){
	TicTacToeBoard theBoard;
	theBoard.placePiece(0, 0);				//place a piece
	theBoard.placePiece(1, 1);				//place a piece
	theBoard.placePiece(2, 2);				//place a piece
	Piece test;
	test = theBoard.getWinner();
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to O after a turn has taken place
}

TEST(TicTacToeBoardTest, getWinnerDiagonalToLeft){
	TicTacToeBoard theBoard;
	theBoard.placePiece(0, 2);				//place a piece
	theBoard.placePiece(1, 1);				//place a piece
	theBoard.placePiece(2, 0);				//place a piece
	Piece test;
	test = theBoard.getWinner();
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to O after a turn has taken place
}

TEST(TicTacToeBoardTest, getWinnerFail){
	TicTacToeBoard theBoard;
	theBoard.placePiece(0, 0);				//place a piece
	theBoard.placePiece(0, 1);				//place a piece
	theBoard.placePiece(2, 0);				//place a piece
	Piece test;
	test = theBoard.getWinner();
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to O after a turn has taken place
}

TEST(TicTacToeBoardTest, getWinnerInvalid){
	TicTacToeBoard theBoard;
	theBoard.placePiece(0, 0);				//place a piece
	Piece test;
	test = theBoard.getWinner();
	ASSERT_EQ(test, Piece::Invalid);				//checks if the test piece is equal to O after a turn has taken place
}

TEST(TicTacToeBoardTest, getPiece){
	TicTacToeBoard theBoard;
	Piece test;
	theBoard.placePiece(1, 2);	
	test = theBoard.getPiece(1, 2);
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to X when placed
}

TEST(TicTacToeBoardTest, getPieceBlank){
	TicTacToeBoard theBoard;
	Piece test;
	theBoard.placePiece(1, 2);	
	test = theBoard.getPiece(0, 0);
	ASSERT_EQ(test, Piece::Blank);				//checks if the test piece is equal to X when placed
}

TEST(TicTacToeBoardTest, getPieceFail){
	TicTacToeBoard theBoard;
	Piece test;
	theBoard.placePiece(1, 2);	
	theBoard.getPiece(1, 3);
	ASSERT_EQ(test, Piece::X);				//checks if the test piece is equal to X when placed
}