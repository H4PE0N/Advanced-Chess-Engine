
#ifndef CHECK_PREVENT_FUNCTIONS_H
#define CHECK_PREVENT_FUNCTIONS_H

bool team_prevent_check(CBoard, Team);

bool piece_prevent_check(CBoard, Point);

bool pawn_prevent_check(CBoard, Point);

bool rook_prevent_check(CBoard, Point);

bool knight_prevent_check(CBoard, Point);

bool bishop_prevent_check(CBoard, Point);

bool queen_prevent_check(CBoard, Point);

bool king_prevent_check(CBoard, Point);

bool diagonal_prevent_check(CBoard, Point);

bool striaght_prevent_check(CBoard, Point);

bool move_prevent_check(CBoard, Move);

#endif
