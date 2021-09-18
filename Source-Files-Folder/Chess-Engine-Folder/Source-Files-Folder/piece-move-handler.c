
#include "../Header-Files-Folder/chess-engine-includer.h"

bool move_chess_piece(CBoard* board, Move move)
{
	if(!move_inside_board(move)) return false;

	Team team = board_point_team(board->board, move.start);

	if(team != board->current) return false;

	switch(board_point_type(board->board, move.start))
	{
		case(EMPTY): return false;

		case(PAWN): return pawn_move_handler(board, move);

		case(ROOK): return rook_move_handler(board, move);

		case(KNIGHT): return knight_move_handler(board, move);

		case(BISHOP): return bishop_move_handler(board, move);

		case(QUEEN): return queen_move_handler(board, move);

		case(KING): return king_move_handler(board, move);

		default: return false;
	}
	return false;
}

bool pawn_move_handler(CBoard* board, Move move)
{
	if(!pawn_move_acceptable(*board, move)) return false;

	execute_pawn_move(board, move);

	return true;
}

bool rook_move_handler(CBoard* board, Move move)
{
	if(!rook_move_acceptable(*board, move)) return false;

	if(team_castle_acceptable(*board, move))
	{
		execute_team_castle(board, move);

		return true;
	}

	execute_rook_move(board, move);

	return true;
}

bool knight_move_handler(CBoard* board, Move move)
{
	if(!knight_move_acceptable(*board, move)) return false;

	execute_knight_move(board, move);

	return true;
}

bool bishop_move_handler(CBoard* board, Move move)
{
	if(!bishop_move_acceptable(*board, move)) return false;

	execute_bishop_move(board, move);

	return true;
}

bool queen_move_handler(CBoard* board, Move move)
{
	if(!queen_move_acceptable(*board, move)) return false;

	execute_queen_move(board, move);

	return true;
}

bool king_move_handler(CBoard* board, Move move)
{
	if(!king_move_acceptable(*board, move)) return false;

	execute_king_move(board, move);

	return true;
}
