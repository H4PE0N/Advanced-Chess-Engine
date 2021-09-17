
#include "../Header-Files-Folder/chess-engine-includer.h"

bool generate_board_fen(char* fenString, CBoard board)
{
  char boardString[256];

  if(!create_board_fen(boardString, board.board))
  {
    return false;
  }

  printf("String: %s\n", boardString);

  return false;
}

bool create_board_fen(char* fenString, Board board)
{
  char string[256];

  Point point;
  Piece piece;

  int index = 0;
  int blanks = 0;

  char letter;

  for(int height = 0; height < BOARD_HEIGHT; height += 1)
  {
    for(int width = 0; width < BOARD_WIDTH; width += 1)
    {
      point = (Point) {height, width};
      piece = board_point_piece(board, point);

      if(piece.type == EMPTY || piece.team == NONE)
      {
        blanks += 1;
        continue;
      }
      else if(blanks > 0)
      {
        letter = (blanks + '0');
        blanks = 0;
      }
      else if(piece.team == WHITE) letter = whitePieces[piece.type - 1];

      else if(piece.team == BLACK) letter = blackPieces[piece.type - 1];

      else
      {
        return false;
      }

      string[index] = letter;

      index += 1;
    }
    if(blanks > 0)
    {
      letter = (blanks + '0');
      blanks = 0;

      string[index] = letter;
      index += 1;
    }
    if(height != (BOARD_HEIGHT - 1))
    {
      string[index] = '/';
      index += 1;
    }
  }

  copy_string_variable(fenString, string, 200);

  return true;
}
