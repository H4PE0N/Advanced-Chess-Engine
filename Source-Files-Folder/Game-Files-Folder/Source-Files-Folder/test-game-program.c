
#include "../Header-Files-Folder/game-files-includer.h"

int main(int argAmount, char* arguments[])
{
  CBoard board;

  //char fenString[256] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  // if(!create_fen_board(&board, fenString))
  // {
  //   printf("Fen was wrong!\n");
  //   return true;
  // }

  board.board = create_board_variable();

  // display_chess_board(board.board);

  free_board_variable(board.board);

  free(board);

  // Move move;
  // if(!best_possible_move(&move, board, 1, WHITE))
  // {
  //   printf("The move could not be done!\n");
  //   return true;
  // }

  // printf("Move %d %d - %d %d\n", move.start.height, move.start.width, move.stop.height, move.stop.width);

  // if(!move_chess_piece(&board, move))
  // {
  //   printf("The move could not be done!\n");
  //   return true;
  // }

  //display_chess_board(board.board);

  return false;
}
