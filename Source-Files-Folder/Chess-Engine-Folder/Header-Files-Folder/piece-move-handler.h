
#ifndef PIECE_MOVE_HANDLER_H
#define PIECE_MOVE_HANDLER_H

bool move_chess_piece(CBoard*, Move);

bool pawn_move_handler(CBoard*, Move);

bool rook_move_handler(CBoard*, Move);

bool bishop_move_handler(CBoard*, Move);

bool knight_move_handler(CBoard*, Move);

bool queen_move_handler(CBoard*, Move);

bool king_move_handler(CBoard*, Move);

#endif
