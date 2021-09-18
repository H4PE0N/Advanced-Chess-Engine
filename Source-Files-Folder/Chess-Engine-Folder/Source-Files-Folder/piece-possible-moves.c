
#include "../Header-Files-Folder/chess-engine-includer.h"

bool piece_possible_moves(Move* moves, CBoard board, Point start)
{
	if(!point_inside_board(start)) return false;

	switch(board_point_type(board.board, start))
	{
		case(EMPTY): return false;

		case(PAWN): return pawn_possible_moves(moves, board, start);

		case(ROOK): return rook_possible_moves(moves, board, start);

		case(KNIGHT): return knight_possible_moves(moves, board, start);

		case(BISHOP): return bishop_possible_moves(moves, board, start);

		case(QUEEN): return queen_possible_moves(moves, board, start);

		case(KING): return king_possible_moves(moves, board, start);

		default: return false;
	}
	return false;
}

bool pawn_possible_moves(Move* moves, CBoard board, Point start)
{
	if(!point_inside_board(start)) return false;

	if(board_point_empty(board.board, start)) return false;

	Team team = board_point_team(board.board, start);

	if(team == NONE) return false;


	Point stop;

	Move currentMove;

	int realHeight, realWidth;


	int amount = 0;

	for(int height = 0; height < 2; height += 1)
	{
		for(int width = 0; width < 3; width += 1)
		{
			// This is the squares that the pawn cant move on.
			// This check is not needed because the "accept" function
			// but its nice just to check simple before.
			if(height == 2 && (width == 0 || width == 2) ) continue;

			realHeight = (team == WHITE) ? (start.height - (height + 1) ) : (start.height + (height + 1) );
			realWidth = (start.width - 1) + width;

			stop = (Point) {realHeight, realWidth};

			if(!point_inside_board(stop)) continue;

			currentMove = (Move) {start, stop};

			if(!pawn_move_acceptable(board, currentMove)) continue;

			moves[amount] = currentMove;

			amount += 1;
		}
	}
	return (amount > 0);
}

bool rook_possible_moves(Move* moves, CBoard board, Point start)
{
	if(!point_inside_board(start)) return false;

	if(board_point_empty(board.board, start)) return false;

	Point stop;

	Move currentMove;

	int amount = 0;

	for(int height = 0; height < BOARD_HEIGHT; height += 1)
	{
		stop = (Point) {height, start.width};

		if(!point_inside_board(stop)) continue;

		currentMove = (Move) {start, stop};

		if(!rook_move_acceptable(board, currentMove)) continue;

		moves[amount] = currentMove;

		amount += 1;
	}

	for(int width = 0; width < BOARD_WIDTH; width += 1)
	{
		stop = (Point) {start.height, width};

		if(!point_inside_board(stop)) continue;

		currentMove = (Move) {start, stop};

		if(!rook_move_acceptable(board, currentMove)) continue;

		moves[amount] = currentMove;

		amount += 1;
	}

	return (amount > 0);
}

bool bishop_possible_moves(Move* moves, CBoard board, Point start)
{
	if(!point_inside_board(start)) return false;

	if(board_point_empty(board.board, start)) return false;

	Point stop;

	Move currentMove;

	int height, width;


	int amount = 0;

	for(int index = -8; index <= 16; index = index + 1)
	{
		height = (start.height + index);
		width = (start.width + index);

		stop = (Point) {height, width};

		if(!point_inside_board(stop)) continue;

		currentMove = (Move) {start, stop};

		if(!bishop_move_acceptable(board, currentMove)) continue;

		moves[amount] = currentMove;

		amount += 1;
	}

	for(int index = -8; index <= 16; index = index + 1)
	{
		height = (start.height + index);
		width = (start.width - index);

		stop = (Point) {height, width};

		if(!point_inside_board(stop)) continue;

		currentMove = (Move) {start, stop};

		if(!bishop_move_acceptable(board, currentMove)) continue;

		moves[amount] = currentMove;

		amount += 1;
	}

	return (amount > 0);
}

bool knight_possible_moves(Move* moves, CBoard board, Point start)
{
	if(!point_inside_board(start)) return false;

	if(board_point_empty(board.board, start)) return false;

	Point stop;

	Move currentMove;

	int realHeight, realWidth;


	int amount = 0;

	for(int height = 0; height < 5; height = height + 1)
	{
		for(int width = 0; width < 5; width = width + 1)
		{
			// This is the squares that the knight cant move on.
			// This check is not needed because the "accept" function
			// but its nice just to check simple before.
			if(height == width || (height + width) == 4) continue;
			if(height == 2 || width == 2) continue;

			realHeight = (start.height - 2) + height;
			realWidth = (start.width - 2) + width;

			stop = (Point) {realHeight, realWidth};

			if(!point_inside_board(stop)) continue;

			currentMove = (Move) {start, stop};

			if(!knight_move_acceptable(board, currentMove)) continue;

			moves[amount] = currentMove;

			amount += 1;
		}
	}
	return (amount > 0);
}

bool diagonal_possible_moves(Move* moves, CBoard board, Point start)
{
	if(!point_inside_board(start)) return false;

	if(board_point_empty(board.board, start)) return false;

	Point stop;

	Move currentMove;

	int height, width;


	int amount = 0;

	for(int index = -8; index <= 16; index = index + 1)
	{
		height = (start.height + index);
		width = (start.width + index);

		stop = (Point) {height, width};

		if(!point_inside_board(stop)) continue;

		currentMove = (Move) {start, stop};

		if(!diagonal_move_acceptable(board, currentMove)) continue;

		moves[amount] = currentMove;

		amount += 1;
	}

	for(int index = -8; index <= 16; index = index + 1)
	{
		height = (start.height + index);
		width = (start.width - index);

		stop = (Point) {height, width};

		if(!point_inside_board(stop)) continue;

		currentMove = (Move) {start, stop};

		if(!diagonal_move_acceptable(board, currentMove)) continue;

		moves[amount] = currentMove;

		amount += 1;
	}

	return (amount > 0);
}

bool straight_possible_moves(Move* moves, CBoard board, Point start)
{
	if(!point_inside_board(start)) return false;

	if(board_point_empty(board.board, start)) return false;

	Point stop;

	Move currentMove;


	int amount = 0;

	for(int height = 0; height < BOARD_HEIGHT; height += 1)
	{
		stop = (Point) {height, start.width};

		if(!point_inside_board(stop)) continue;

		currentMove = (Move) {start, stop};

		if(!straight_move_acceptable(board, currentMove)) continue;

		moves[amount] = currentMove;

		amount += 1;
	}

	for(int width = 0; width < BOARD_WIDTH; width += 1)
	{
		stop = (Point) {start.height, width};

		if(!point_inside_board(stop)) continue;

		currentMove = (Move) {start, stop};

		if(!straight_move_acceptable(board, currentMove)) continue;

		moves[amount] = currentMove;

		amount += 1;
	}

	return (amount > 0);
}

bool queen_possible_moves(Move* moves, CBoard board, Point start)
{
	if(!point_inside_board(start)) return false;

	if(board_point_empty(board.board, start)) return false;


	Move* diagonalMoves = create_moves_array(40);
	Move* straightMoves = create_moves_array(40);

	bool diagonalBool = diagonal_possible_moves(diagonalMoves, board, start);
	bool straightBool = straight_possible_moves(straightMoves, board, start);

	if(!diagonalBool && !straightBool)
	{
		free(diagonalMoves);
		free(straightMoves);

		return false;
	}

	append_moves_array(moves, diagonalMoves);
	append_moves_array(moves, straightMoves);

	free(diagonalMoves);
	free(straightMoves);

	return true;
}

bool king_possible_moves(Move* moves, CBoard board, Point start)
{
	if(!point_inside_board(start)) return false;

	if(board_point_empty(board.board, start)) return false;

	Point stop;

	Move currentMove;

	int realHeight, realWidth;


	int amount = 0;

	for(int height = 0; height < 3; height += 1)
	{
		for(int width = 0; width < 3; width += 1)
		{
			realHeight  = (start.height - 1) + height;
			realWidth = (start.width - 1) + width;

			stop = (Point) {realHeight, realWidth};

			if(!point_inside_board(stop)) continue;

			currentMove = (Move) {start, stop};

			if(!king_move_acceptable(board, currentMove)) continue;

			moves[amount] = currentMove;

			amount += 1;
		}
	}
	return (amount > 0);
}
