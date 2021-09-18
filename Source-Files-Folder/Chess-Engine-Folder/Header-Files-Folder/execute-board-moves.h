
#ifndef EXECUTE_BOARD_MOVES_H
#define EXECUTE_BOARD_MOVES_H

void execute_piece_move(CBoard*, Move);

void execute_pawn_move(CBoard*, Move);

void execute_rook_move(CBoard*, Move);

void execute_team_castle(CBoard*, Move);

void execute_knight_move(CBoard*, Move);

void execute_bishop_move(CBoard*, Move);

void execute_queen_move(CBoard*, Move);

void execute_king_move(CBoard*, Move);

void make_pawn_queen(CBoard*, Point);

#endif
