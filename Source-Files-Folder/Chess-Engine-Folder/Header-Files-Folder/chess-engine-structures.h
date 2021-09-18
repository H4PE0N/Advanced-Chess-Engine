
#ifndef CHESS_ENGINE_STRUCTURES_H
#define CHESS_ENGINE_STRUCTURES_H

#define BOARD_HEIGHT 8
#define BOARD_WIDTH 8

#define MIN_VAL -100000
#define MAX_VAL +100000

#define GAME_MOVES 128

typedef enum Type
{
	EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
} Type;

typedef enum Team
{
	NONE, WHITE, BLACK
} Team;

typedef enum Side
{
	STILL, LEFT, RIGHT
} Side;

typedef struct Point
{
  int height, width;
} Point;

typedef struct Piece
{
  Type type;
  Team team;
} Piece;

typedef struct Move
{
  Point start;
  Point stop;
} Move;

typedef struct Castle
{
  bool king;
  bool queen;
} Castle;

typedef struct Castles
{
	Castle white;
	Castle black;
} Castles;

typedef struct Board
{
  Piece** board;
  Team current;
  Castles castles;
	Point passant;
	int counter;
  int turns;
  Move* moves;
} Board;

#define EMPTY_POINT (Point) {-1, -1}

#define EMPTY_MOVE (Move) {EMPTY_POINT, EMPTY_POINT}

#define EMPTY_PIECE (Piece) {EMPTY, NONE}

extern const char whitePieces[];
extern const char blackPieces[];

extern const char boardLetters[];
extern const char boardNumbers[];

#endif
