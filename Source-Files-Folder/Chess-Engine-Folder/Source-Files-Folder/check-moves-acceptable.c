
#include "../Header-Files-Folder/chess-engine-includer.h"

bool piece_move_acceptable(CBoard board, Move move)
{
	switch(board_point_type(board.board, move.start))
	{
		case(EMPTY): return false;

		case(PAWN): return pawn_move_acceptable(board, move);

		case(ROOK): return rook_move_acceptable(board, move);

		case(KNIGHT): return knight_move_acceptable(board, move);

		case(BISHOP): return bishop_move_acceptable(board, move);

		case(QUEEN): return queen_move_acceptable(board, move);

		case(KING): return king_move_acceptable(board, move);

    default: return false;
	}
	return false;
}

bool queen_move_acceptable(CBoard board, Move move)
{
  Point start = move.start, stop = move.stop;

	// These controls is the most obvious, and should be done first
	if(!move_inside_board(move)) return false;

	if(board_point_empty(board.board, start)) return false;

	if(board_points_team(board.board, start, stop)) return false;

	if(board_point_type(board.board, stop) == KING) return false;

	// These controls are more specific, and should be done later
	if(!moving_queen_valid(start, stop)) return false;

	if(!clear_moving_path(board.board, start, stop)) return false;

	if(!move_prevent_check(board, move)) return false;

	return true;
}

bool pawn_move_acceptable(CBoard board, Move move)
{
	Point start = move.start, stop = move.stop;

	// These controls is the most obvious, and should be done first
	if(!move_inside_board(move)) return false;

	if(board_point_empty(board.board, start)) return false;

	if(board_point_type(board.board, stop) == KING) return false;

	// These controls are more specific, and should be done later
  Team team = board_point_team(board.board, start);

	if(!moving_pawn_valid(start, stop, team)) return false;

	if(!clear_moving_path(board.board, start, stop)) return false;

	// These controls are vary specific, and should be done last
	if(start.width == stop.width) // Going straight
	{
		if(!board_point_empty(board.board, stop)) return false;
	}
	else if(points_not_enemies(board.board, start, stop)) return false;
	
	if(!move_prevent_check(board, move)) return false;

	return true;
}

bool rook_move_acceptable(CBoard board, Move move)
{
	Point start = move.start, stop = move.stop;

	// These controls is the most obvious, and should be done first
	if(!move_inside_board(move)) return false;

	if(board_point_empty(board.board, start)) return false;

	// These controls are more specific, and should be done later
	if(!moving_rook_valid(start, stop)) return false;

	if(!clear_moving_path(board.board, start, stop)) return false;

	// This is a special case, and will skip the following controls
	if(team_castle_acceptable(board, move)) return true;

	// These controls are more specific, and should be done later
	if(board_points_team(board.board, start, stop)) return false;

	if(board_point_type(board.board, stop) == KING) return false;

	if(!move_prevent_check(board, move)) return false;

	return true;
}

bool bishop_move_acceptable(CBoard board, Move move)
{
	Point start = move.start, stop = move.stop;

	// These controls is the most obvious, and should be done first
	if(!move_inside_board(move)) return false;

	if(board_point_empty(board.board, start)) return false;

	if(board_points_team(board.board, start, stop)) return false;

	if(board_point_type(board.board, stop) == KING) return false;

	// These controls are more specific, and should be done later
	if(!moving_bishop_valid(start, stop)) return false;

	if(!clear_moving_path(board.board, start, stop)) return false;

	if(!move_prevent_check(board, move)) return false;

	return true;
}

bool king_move_acceptable(CBoard board, Move move)
{
	Point start = move.start, stop = move.stop;

	// These controls is the most obvious, and should be done first
	if(!move_inside_board(move)) return false;

	if(board_point_empty(board.board, start)) return false;

	if(board_points_team(board.board, start, stop)) return false;

	if(board_point_type(board.board, stop) == KING) return false;

	// These controls are more specific, and should be done later
	if(!moving_king_valid(start, stop)) return false;

	if(!move_prevent_check(board, move)) return false;

	return true;
}

bool diagonal_move_acceptable(CBoard board, Move move)
{
	Point start = move.start, stop = move.stop;

	// These controls is the most obvious, and should be done first
	if(!move_inside_board(move)) return false;

	if(board_point_empty(board.board, start)) return false;

	if(board_points_team(board.board, start, stop)) return false;

	if(board_point_type(board.board, stop) == KING) return false;

	// These controls are more specific, and should be done later
	if(!moving_diagonal_valid(start, stop)) return false;

	if(!clear_moving_path(board.board, start, stop)) return false;

	if(!move_prevent_check(board, move)) return false;

	return true;
}

bool straight_move_acceptable(CBoard board, Move move)
{
	Point start = move.start, stop = move.stop;

	// These controls is the most obvious, and should be done first
	if(!move_inside_board(move)) return false;

	if(board_point_empty(board.board, start)) return false;

	// These controls are more specific, and should be done later
	if(!moving_straight_valid(start, stop)) return false;

	if(!clear_moving_path(board.board, start, stop)) return false;

	// This is a special case, and will skip the following controls
	if(team_castle_acceptable(board, move)) return true;

	// These controls are more specific, and should be done later
	if(board_points_team(board.board, start, stop)) return false;

	if(board_point_type(board.board, stop) == KING) return false;

	if(!move_prevent_check(board, move)) return false;

	return true;
}

bool knight_move_acceptable(CBoard board, Move move)
{
	Point start = move.start, stop = move.stop;

	// These controls is the most obvious, and should be done first
	if(!move_inside_board(move)) return false;

	if(board_point_empty(board.board, start)) return false;

	if(board_points_team(board.board, start, stop)) return false;

	if(board_point_type(board.board, stop) == KING) return false;

	// These controls are more specific, and should be done later
	if(!moving_knight_valid(start, stop)) return false;

	if(!move_prevent_check(board, move)) return false;

	return true;
}

bool team_castle_acceptable(CBoard board, Move move)
{
	Point start = move.start, stop = move.stop;

  if(!move_inside_board(move)) return false;

  if(board_point_empty(board.board, start)) return false;

  Team team = board_point_team(board.board, start);

	Point king = board_piece_point(board.board, (Piece) {KING, team});

	if(!point_inside_board(king)) return false;

	// This is a special case, you cant switch if the king is in check
	if(king_inside_check(board.board, king)) return false;

	// This checks if the rook and the king is on the right place
	if(!team_castle_valid(board.board, start, stop)) return false;

	if(!check_after_castling(board, move)) return false;

	return true;
}

bool check_after_castling(CBoard board, Move move)
{
	if(!move_inside_board(move)) return false;

	Team team = board_point_team(board.board, move.start);

	CBoard boardCopy = board;

	execute_team_castle(&boardCopy, move);

	Point king = board_piece_point(board.board, (Piece) {KING, team});

	if(!point_inside_board(king)) return false;

	if(king_inside_check(boardCopy.board, king)) return false;

  return true;
}

bool clear_moving_path(Board board, Point start, Point stop)
{
  int heightOffset = (stop.height - start.height);
	int widthOffset = (stop.width - start.width);

	// If the knight is moving, he dont need a clear moving path
	if(moving_knight_valid(start, stop)) return true;

	int steps = (abs(heightOffset) > abs(widthOffset)) ? abs(heightOffset) : abs(widthOffset);

	int heightAdder = (heightOffset == 0) ? 0 : (heightOffset / abs(heightOffset));
	int widthAdder = (widthOffset == 0) ? 0 : (widthOffset / abs(widthOffset));

	int height, width;

	Point point;

	for(int index = 1; index < steps; index = index + 1)
	{
		height = start.height + (index * heightAdder);
		width = start.width + (index * widthAdder);

		point = (Point) {height, width};

		if(!board_point_empty(board, point)) return false;
	}
	return true;
}
