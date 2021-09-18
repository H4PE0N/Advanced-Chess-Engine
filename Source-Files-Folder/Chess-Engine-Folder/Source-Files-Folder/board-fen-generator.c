
#include "../Header-Files-Folder/chess-engine-includer.h"

bool generate_board_fen(char* fenString, CBoard board)
{
  char createdFen[256];
  clear_string_variable(createdFen, 256);

  char boardString[256];
  clear_string_variable(boardString, 20);

  if(!create_board_fen(boardString, board.board))
  {
    printf("Error create board fen!\n");
    return false;
  }

  char currentString[20];
  clear_string_variable(currentString, 20);

  if(!create_current_fen(currentString, board.current))
  {
    printf("Error create current fen!\n");
    return false;
  }

  char castlesString[20];
  clear_string_variable(castlesString, 20);

  if(!create_castles_fen(castlesString, board.castles))
  {
    printf("Error create castles fen!\n");
    return false;
  }

  char passantString[20];
  clear_string_variable(passantString, 20);

  if(!create_passant_fen(passantString, board.passant))
  {
    printf("Error create castles fen!\n");
    return false;
  }

  if(board.counter < 0 || board.turns < 1)
  {
    printf("Error with counter and turns!\n");
    return false;
  }

  sprintf(createdFen, "%s %s %s %s %d %d", boardString, currentString, castlesString, passantString, board.counter, board.turns);

  copy_string_variable(fenString, createdFen, 200);

  return true;
}

bool create_current_fen(char* fenString, Team current)
{
  if(current != WHITE && current != BLACK)
  {
    return false;
  }

  char currentString[20];
  clear_string_variable(currentString, 20);

  currentString[0] = (current == WHITE) ? 'w' : 'b';

  copy_string_variable(fenString, currentString, 20);

  return true;
}

bool create_castles_fen(char* fenString, Castles castles)
{
  char castlesString[20];
  clear_string_variable(castlesString, 20);

  bool castleExists = false;

  if(castles.white.king)
  {
    strcat(castlesString, "K");
    castleExists = true;
  }

  if(castles.white.queen)
  {
    strcat(castlesString, "Q");
    castleExists = true;
  }

  if(castles.black.king)
  {
    strcat(castlesString, "k");
    castleExists = true;
  }

  if(castles.black.queen)
  {
    strcat(castlesString, "q");
    castleExists = true;
  }

  if(!castleExists)
  {
    strcat(castlesString, "-");
  }

  copy_string_variable(fenString, castlesString, 20);

  return true;
}

bool create_passant_fen(char* fenString, Point passant)
{
  char passantString[20];
  clear_string_variable(passantString, 20);

  if(!point_inside_board(passant))
  {
    passantString[0] = '-';
  }
  else
  {
    char letter = boardLetters[passant.width];
    char number = boardNumbers[passant.height];

    passantString[0] = letter;
    passantString[1] = number;
  }

  copy_string_variable(fenString, passantString, 20);

  return true;
}

bool create_board_fen(char* fenString, Board board)
{
  char string[200];
  clear_string_variable(string, 200);

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
