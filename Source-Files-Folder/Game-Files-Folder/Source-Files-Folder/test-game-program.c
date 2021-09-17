
#include "../Header-Files-Folder/game-files-includer.h"

int main(int argAmount, char* arguments[])
{
  CBoard board;
  Piece piece;
  Point point;

  char fenString[256] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  if(!create_fen_board(&board, fenString))
  {
    printf("Fen was wrong!\n");
    return true;
  }

  for(int height = 0; height < BOARD_HEIGHT; height += 1)
  {
    for(int width = 0; width < BOARD_WIDTH; width += 1)
    {
      point = (Point) {height, width};
      piece = board_point_piece(board.board, point);

      printf("%d%d", piece.type, piece.team);
    }
    printf("\n");
  }

  char string[256];

  if(!generate_board_fen(string, board))
  {
    return true;
  }

  return false;
}
