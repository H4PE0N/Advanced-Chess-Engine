
#include "../Header-Files-Folder/game-files-includer.h"

int main(int argAmount, char* arguments[])
{
  CBoard board;

  char fenString[256] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  if(!create_fen_board(&board, fenString))
  {
    printf("Fen was wrong!\n");
    return true;
  }

  display_chess_board(board.board);

  return false;
}
