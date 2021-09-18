
#ifndef COMMON_HELP_FUNCTIONS_H
#define COMMON_HELP_FUNCTIONS_H

int string_letter_index(char[], int, char);

int extract_string_length(char[]);

void copy_string_variable(char*, char[], int);

void clear_string_variable(char*, int);

Point* create_points_array(int);

void append_moves_array(Move*, Move[]);

int moves_array_amount(Move[]);

void clear_moves_array(Move*, int);

Move* create_moves_array(int);

#endif
