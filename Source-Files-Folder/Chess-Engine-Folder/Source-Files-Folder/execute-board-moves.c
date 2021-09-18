
#include "../Header-Files-Folder/chess-engine-includer.h"

void execute_piece_move(CBoard* board, Move move)
{
	if(!move_inside_board(move)) return;

	switch(board_point_type(board->board, move.start))
	{
		case(EMPTY): break;

		case(PAWN): execute_pawn_move(board, move); break;

		case(ROOK): execute_rook_move(board, move); break;

		case(KNIGHT): execute_knight_move(board, move); break;

		case(BISHOP): execute_bishop_move(board, move); break;

		case(QUEEN): execute_queen_move(board, move); break;

		case(KING): execute_king_move(board, move); break;

		default: break;
	}
}

void execute_pawn_move(CBoard* board, Move move)
{
	move_board_piece(&board->board, move.start, move.stop);

	make_pawn_queen(board, move.stop);

	// check for en passant
}

void execute_team_castle(CBoard* board, Move move)
{
	Point start = move.start, stop = move.stop;

	int difference = (stop.width - start.width);

	int kingWidth = (difference < 0) ? 6 : 2;
	int rookWidth = (difference < 0) ? 5 : 3;

	Point rook = {start.height, rookWidth};
	Point king = {stop.height, kingWidth};

	move_board_piece(&board->board, stop, king);
	move_board_piece(&board->board, start, rook);

	Team team = board_point_team(board->board, start);

	update_castles_values(&board->castles, team, (Castle) {false, false});
}

void execute_rook_move(CBoard* board, Move move)
{
	Point start = move.start, stop = move.stop;

	Team team = board_point_team(board->board, start);

	move_board_piece(&board->board, start, stop);

	Side side = STILL;

	if(start.width == 0) side = LEFT;
	if(start.width == (BOARD_WIDTH - 1)) side = RIGHT;

	update_castles_value(&board->castles, team, side, false);
}

void execute_knight_move(CBoard* board, Move move)
{
	move_board_piece(&board->board, move.start, move.stop);
}

void execute_bishop_move(CBoard* board, Move move)
{
	move_board_piece(&board->board, move.start, move.stop);
}

void execute_queen_move(CBoard* board, Move move)
{
	move_board_piece(&board->board, move.start, move.stop);
}

void execute_king_move(CBoard* board, Move move)
{
	Point start = move.start, stop = move.stop;

	Team team = board_point_team(board->board, start);

	move_board_piece(&board->board, start, stop);

	update_castles_values(&board->castles, team, (Castle) {false, false});
}

void make_pawn_queen(CBoard* board, Point point)
{
	Team team = board_point_team(board->board, point);

	bool whiteQueen = (team == WHITE && point.height == 0);
	bool blackQueen = (team == BLACK && point.height == (BOARD_HEIGHT - 1));

	if(whiteQueen || blackQueen)
	{
		allocate_board_piece(&board->board, point, (Piece) {QUEEN, team});
	}
}
