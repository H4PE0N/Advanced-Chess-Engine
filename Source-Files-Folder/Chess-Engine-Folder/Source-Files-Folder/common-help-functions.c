
#include "../Header-Files-Folder/chess-engine-includer.h"

int string_letter_index(char string[], int length, char letter)
{
  for(int index = 0; index < length; index += 1)
  {
    if(string[index] == letter) return index;
  }
  return -1;
}

int extract_string_length(char string[])
{
  int length = 0;
  while(string[length] != '\0') length += 1;
  return length;
}

void copy_string_variable(char* string, char copying[], int length)
{
  for(int index = 0; index < length; index += 1)
  {
    string[index] = copying[index];
  }
}

void clear_string_variable(char* string, int length)
{
  for(int index = 0; index < length; index += 1)
  {
    string[index] = '\0';
  }
}

Point* create_points_array(int amount)
{
  Point* points = malloc(sizeof(Point) * (amount + 1) );

  for(int index = 0; index < (amount + 1); index += 1)
  {
    points[index] = (Point) {-1, -1};
  }

  return points;
}

void append_moves_array(Move* moves, Move adding[])
{
  int amount = moves_array_amount(moves);
	int addAmount = moves_array_amount(adding);

	for(int index = 0; index < addAmount; index += 1)
	{
		moves[amount + index] = adding[index];
	}
}

int moves_array_amount(Move moves[])
{
	int amount = 0;
	while(move_inside_board(moves[amount]))
	{
		amount += 1;
	}
	return amount;
}

void clear_moves_array(Move* moves, int amount)
{
	for(int index = 0; index < amount; index += 1)
	{
		moves[index] = (Move) {(Point) {-1, -1}, (Point) {-1, -1}};
	}
}

Move* create_moves_array(int amount)
{
	Move* moves = malloc(sizeof(Move) * (amount + 1));

	for(int index = 0; index < (amount + 1); index += 1)
	{
		moves[index] = (Move) {(Point) {-1, -1}, (Point) {-1, -1}};
	}
	return moves;
}
