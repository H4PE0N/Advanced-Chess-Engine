
#ifndef CHESS_PIECES_MOVEABLE_H
#define CHESS_PIECES_MOVEABLE_H

bool board_piece_moveable(CBoard, Point);

bool board_pawn_moveable(CBoard, Point);

bool board_rook_moveable(CBoard, Point);

bool board_knight_moveable(CBoard, Point);

bool board_bishop_moveable(CBoard, Point);

bool board_queen_moveable(CBoard, Point);

bool board_king_moveable(CBoard, Point);

bool board_diagonal_moveable(CBoard, Point);

bool board_straight_moveable(CBoard, Point);

#endif
