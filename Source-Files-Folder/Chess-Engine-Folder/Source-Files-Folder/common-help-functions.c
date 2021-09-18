
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
