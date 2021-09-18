
#include "../Header-Files-Folder/chess-engine-includer.h"

bool extract_fen_board(Board* board, char fenString[])
{
  //Board extractBoard;

  char tokenString[256];
  copy_string_variable(tokenString, fenString, 200);

  char* string = strtok(tokenString, "/");

  Point point = {0, 0};
  Piece piece = {EMPTY, NONE};

  int stringLength, amount;
  int height, width;

  for(height = 0; height < BOARD_HEIGHT; height += 1)
  {
    if(string == NULL)
    {
      return false;
    }

    if((stringLength = strlen(string)) > BOARD_WIDTH)
    {
      return false;
    }

    for(width = 0; width < stringLength; width += 1)
    {
      point = (Point) {height, width};

      if(number_inside_bounds(string[width], '1', '8'))
      {
        amount = (string[width] - '0');

        for(int index = 0; index < amount; index += 1)
        {
          allocate_board_piece(board, point, (Piece) {EMPTY, NONE});
        }

        continue;
      }

      if(!extract_letter_piece(&piece, string[width]))
      {
        printf("extract board piece error\n");
        return false;
      }

      allocate_board_piece(board, point, piece);
    }

    string = strtok(NULL, "/");
  }

  if(point.height != (BOARD_HEIGHT - 1) || point.width != (BOARD_WIDTH - 1))
  {
    printf("extract board error boudnds!\n");
    return false;
  }

  //copy_board_variable(board, extractBoard);

  return true;
}

bool extract_fen_castles(Castles* castles, char fenString[])
{
  Castles extractCastles;
  int stringLength = strlen(fenString);

  if(stringLength == 1 && fenString[0] == '-')
  {
    *castles = extractCastles;
    return true;
  }

  for(int index = 0; index < stringLength; index += 1)
  {
    if(!extract_letter_castle(&extractCastles, fenString[index]))
    {
      printf("extract letter casle\n");
      return false;
    }
  }
  *castles = extractCastles;
  return true;
}

bool extract_fen_passant(Point* passant, char fenString[])
{
  int stringLength = strlen(fenString);
  if(stringLength <= 0) return false;

  if(fenString[0] == '-')
  {
    *passant = (Point) {-1, -1};
    return true;
  }

  if(stringLength != 2)
  {
    printf("passant length was not 2!\n");
    return false;
  }

  int width = string_letter_index((char*) boardLetters, 8, fenString[0]);
  int height = string_letter_index((char*) boardNumbers, 8, fenString[1]);

  if(height == -1 || width == -1)
  {
    printf("passant letter bounds!\n");
    return false;
  }

  *passant = (Point) {height, width};
  return true;
}

bool create_fen_board(CBoard* board, char fenString[])
{
  CBoard extractBoard;

  char tokenString[256];

  copy_string_variable(tokenString, fenString, 200);

  char* string;
  if( (string = strtok(tokenString, " ")) == NULL)
  {
    printf("Error when reading board!\n");
    return false;
  }

  if(!extract_fen_board(&extractBoard.board, string))
  {
    printf("Extract fen board error!\n");
    return false;
  }

  copy_string_variable(tokenString, fenString, 200);

  if( (string = strtok(tokenString, " ")) == NULL)
  {
    printf("Null string!\n");
    return false;
  }

  // This is the part with the current team
  if( (string = strtok(NULL, " ")) == NULL)
  {
    printf("Error when reading current team!\n");
    return false;
  }

  if(strlen(string) != 1)
  {
    printf("Eextract current team!\n");
    return false;
  }

  if(!extract_letter_team(&extractBoard.current, string[0]))
  {
    printf("extract current team\n");
    return false;
  }

  // This is the part with castle permissions
  if( (string = strtok(NULL, " ")) == NULL)
  {
    printf("Error when reading castles!\n");
    return false;
  }
  if(!extract_fen_castles(&extractBoard.castles, string))
  {
    printf("Error when reading castles!\n");
    return false;
  }

  // This is the part with en passant
  if( (string = strtok(NULL, " ")) == NULL)
  {
    printf("Error when reading passant!\n");
    return false;
  }
  if(!extract_fen_passant(&extractBoard.passant, string))
  {
    printf("Error when reading passant!\n");
    return false;
  }


  // This is the part with the counter
  if( (string = strtok(NULL, " ")) == NULL)
  {
    printf("Error when reading counter!\n");
    return false;
  }

  extractBoard.counter = atoi(string);

  // This is the part with the turns
  if( (string = strtok(NULL, " ")) == NULL)
  {
    printf("Error when reading turns!\n");
    return false;
  }

  extractBoard.turns = atoi(string);

  *board = extractBoard;

  return true;
}

bool extract_letter_castle(Castles* castles, char letter)
{
  switch(letter)
  {
    case('K'): castles->white.king = true; break;

    case('Q'): castles->white.queen = true; break;

    case('k'): castles->black.king = true; break;

    case('q'): castles->black.queen = true; break;

    default: return false;
  }
  return true;
}

bool extract_letter_team(Team* team, char letter)
{
  if(letter == 'w')
  {
    *team = WHITE;
  }
  else if(letter == 'b')
  {
    *team = BLACK;
  }
  else return false;

  return true;
}

bool extract_letter_piece(Piece* piece, char letter)
{
  int whiteIndex = string_letter_index((char*) whitePieces, 6, letter);
  int blackIndex = string_letter_index((char*) blackPieces, 6, letter);

  if(whiteIndex != -1)
  {
    piece->type = (whiteIndex + 1); // Type (1, 6)
    piece->team = WHITE;
  }
  else if(blackIndex != -1)
  {
    piece->type = (blackIndex + 1); // Type (1, 6)
    piece->team = BLACK;
  }
  else return false;

  return true;
}
