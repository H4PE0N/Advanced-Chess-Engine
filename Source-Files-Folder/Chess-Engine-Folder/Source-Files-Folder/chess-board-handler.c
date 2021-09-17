
#include "../Header-Files-Folder/chess-engine-includer.h"

void allocate_board_piece(Board* board, Point point, Piece piece)
{
  (*board)[point.height][point.width] = piece;
}

Piece board_point_piece(Board board, Point point)
{
  return board[point.height][point.width];
}

void copy_board_variable(Board* board, Board copying)
{
  Point point;
  Piece piece;

  for(int height = 0; height < BOARD_HEIGHT; height += 1)
  {
    for(int width = 0; width < BOARD_WIDTH; width += 1)
    {
      point = (Point) {height, width};

      piece = board_point_piece(copying, point);

      allocate_board_piece(board, point, piece);
    }
  }
}
