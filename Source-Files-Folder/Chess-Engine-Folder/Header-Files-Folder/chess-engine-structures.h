
#ifndef CHESS_ENGINE_STRUCTURES_H
#define CHESS_ENGINE_STRUCTURES_H

#define BOARD_HEIGHT 8
#define BOARD_WIDTH 8

typedef enum Type
{
	EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
};

typedef enum Team
{
	NONE, WHITE, BLACK
};

typedef struct Point
{
  int height, width;
};

typedef struct Piece
{
  Type type;
  Team team;
};

typedef struct Move
{
  Point start;
  Point stop;
};

typedef struct Castle
{
  bool kingCastle;
  bool queenCastle;
};

typedef struct Board
{
  Piece[BOARD_HEIGHT][BOARD_WIDTH] board;
  Team currentTeam;
  Castle whiteCastle, blackCastle;
  int turns;
  Move[256] moveStack;
};

#endif
