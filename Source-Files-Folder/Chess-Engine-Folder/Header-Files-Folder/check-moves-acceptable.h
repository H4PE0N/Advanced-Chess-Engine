
#ifndef CHECK_MOVES_ACCEPTALBE_H
#define CHECK_MOVES_ACCEPTALBE_H

bool check_after_castling(CBoard, Move);

bool team_castle_acceptable(CBoard, Move);

bool knight_move_acceptable(CBoard, Move);

bool straight_move_acceptable(CBoard, Move);

bool diagonal_move_acceptable(CBoard, Move);

bool king_move_acceptable(CBoard, Move);

bool bishop_move_acceptable(CBoard, Move);

bool rook_move_acceptable(CBoard, Move);

bool pawn_move_acceptable(CBoard, Move);

bool queen_move_acceptable(CBoard, Move);

bool piece_move_acceptable(CBoard, Move);

bool clear_moving_path(Board, Point, Point);

#endif
