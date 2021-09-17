
#ifndef CHESS_BOARD_HANDLER_H
#define CHESS_BOARD_HANDLER_H

void allocate_board_piece(Board*, Point, Piece);
Piece board_point_piece(Board, Point);
void copy_board_variable(Board*, Board);

#endif
