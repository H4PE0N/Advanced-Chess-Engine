
#ifndef PIECE_POSSIBLE_MOVES_H
#define PIECE_POSSIBLE_MOVES_H

bool piece_possible_moves(Move*, CBoard, Point);

bool pawn_possible_moves(Move*, CBoard, Point);

bool rook_possible_moves(Move*, CBoard, Point);

bool bishop_possible_moves(Move*, CBoard, Point);

bool knight_possible_moves(Move*, CBoard, Point);

bool queen_possible_moves(Move*, CBoard, Point);

bool king_possible_moves(Move*, CBoard, Point);

#endif
