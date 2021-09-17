
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

bool number_inside_bounds(int number, int minimum, int maximum)
{
  return ( (number >= minimum) && (number <= maximum) );
}

void copy_string_variable(char* string, char copying[], int length)
{
  for(int index = 0; index < length; index += 1)
  {
    string[index] = copying[index];
  }
}
