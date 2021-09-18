
#include "../Header-Files-Folder/game-files-includer.h"

int main(int argAmount, char* arguments[])
{
  //char fenString[256] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  Board board;

  allocate_board_memory(&board);

  for(int i = 0; i < 8; i ++)
  {
    for(int j=0; j< 8; j ++)
    {
      printf("%d%d", board.board[i][j].type, board.board[i][j].team);
    }
    printf("\n");
  }

  free_board_variable(board);

  return false;
}
