
#include "../Header-Files-Folder/interface-files-includer.h"

void display_chess_board(Board board)
{
  Piece piece;
  Point point;

  char symbol;

  for(int height = 0; height < BOARD_HEIGHT; height += 1)
  {
    for(int width = 0; width < BOARD_WIDTH; width += 1)
    {
      point = (Point) {height, width};
      piece = board_point_piece(board, point);

      if(piece.team == WHITE) symbol = whitePieces[piece.type - 1];

      else if(piece.team == BLACK) symbol = blackPieces[piece.type - 1];

      else symbol = '.';

      printf("%c ", symbol);
    }
    printf("\n");
  }
}
