
#include "../Header-Files-Folder/chess-engine-includer.h"

bool moving_piece_valid(Board board, Point start, Point stop)
{
  if(!points_inside_board(start, stop)) return false;

  Team team = board_point_team(board, start);

	switch(board_point_type(board, start))
	{
		case(EMPTY): return false;

		case(PAWN): return moving_pawn_valid(start, stop, team);

		case(ROOK): return moving_rook_valid(start, stop);

		case(KNIGHT): return moving_knight_valid(start, stop);

		case(BISHOP): return moving_bishop_valid(start, stop);

		case(QUEEN): return moving_queen_valid(start, stop);

		case(KING): return moving_king_valid(start, stop);

    default: return false;
	}
	return false;
}

int pawn_height_offset(Point start, Point stop, Team team)
{
	if(team == WHITE) return (start.height - stop.height);
	if(team == BLACK) return (stop.height - start.height);

	else return MIN_VAL; // This is an invalid move for the pawn.
}

bool pawn_starting_bool(Point start, Team team)
{
	if(team == WHITE && start.height == 6) return true;
	if(team == BLACK && start.height == 1) return true;

	return false;
}

bool moving_pawn_valid(Point start, Point stop, Team team)
{
	int heightOffset = pawn_height_offset(start, stop, team);
	int widthOffset = abs(start.width - stop.width);

	bool straight = (start.width == stop.width);
	bool starting = pawn_starting_bool(start, team);

	if(straight && heightOffset == 1) return true;
	if(straight && starting && heightOffset == 2) return true;
	if(heightOffset == 1 && widthOffset == 1) return true;

	return false;
}

bool rook_starting_bool(Point point, Team team)
{
	if(team == WHITE && point.height != (BOARD_HEIGHT - 1))  return false;
	if(team == BLACK && point.height != 0)                   return false;

	return (point.width == 0 || point.width == (BOARD_WIDTH - 1));
}

bool king_starting_bool(Point point, Team team)
{
	if(team == WHITE && point.height != (BOARD_HEIGHT - 1))  return false;
	if(team == BLACK && point.height != 0)                   return false;

	return (point.width == 4);
}

bool team_castle_valid(Board board, Point start, Point stop)
{
	if(!board_points_team(board, start, stop)) return false;

	Team team = board_point_team(board, start);

	if(!rook_starting_bool(start, team)) return false;

	if(!king_starting_bool(stop, team)) return false;

	return true;
}

bool moving_rook_valid(Point start, Point stop)
{
	if(board_points_equal(start, stop)) return false;

	int heightOffset = abs(start.height - stop.height);
	int widthOffset = abs(start.width - stop.width);

	return (heightOffset == 0) || (widthOffset == 0);
}

bool moving_knight_valid(Point start, Point stop)
{
	int heightOffset = abs(start.height - stop.height);
	int widthOffset = abs(start.width - stop.width);

	if(heightOffset == 1 && widthOffset == 2) return true;
	if(heightOffset == 2 && widthOffset == 1) return true;

	return false;
}

bool moving_bishop_valid(Point start, Point stop)
{
	if(board_points_equal(start, stop)) return false;

	int heightOffset = abs(start.height - stop.height);
	int widthOffset = abs(start.width - stop.width);

	return (heightOffset == widthOffset);
}

bool moving_queen_valid(Point start, Point stop)
{
	if(board_points_equal(start, stop)) return false;

	int heightOffset = abs(start.height - stop.height);
	int widthOffset = abs(start.width - stop.width);

	if(heightOffset == 0 || widthOffset == 0) return true;
	if(heightOffset == widthOffset) return true;

	return false;
}

bool moving_king_valid(Point start, Point stop)
{
	if(board_points_equal(start, stop)) return false;

	int heightOffset = abs(start.height - stop.height);
	int widthOffset = abs(start.width - stop.width);

	return (heightOffset <= 1) && (widthOffset <= 1);
}

bool moving_straight_valid(Point start, Point stop)
{
	if(board_points_equal(start, stop)) return false;

	int heightOffset = abs(start.height - stop.height);
	int widthOffset = abs(start.width - stop.width);

	return (heightOffset == 0) || (widthOffset == 0);
}

bool moving_diagonal_valid(Point start, Point stop)
{
	if(board_points_equal(start, stop)) return false;

	int heightOffset = abs(start.height - stop.height);
	int widthOffset = abs(start.width - stop.width);

	return (heightOffset == widthOffset);
}
