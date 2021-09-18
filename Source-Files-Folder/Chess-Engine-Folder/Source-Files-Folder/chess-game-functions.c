
#include "../Header-Files-Folder/chess-engine-includer.h"

// This function should only check one team, so that the draw gets right
bool game_still_running(Team* winner, CBoard board)
{
	for(int round = 0; round < 2; round = round + 1)
	{
		Team team = (round == 0) ? WHITE : BLACK;

		if(check_mate_situation(board, team))
		{
			*winner = (team == WHITE) ? BLACK : WHITE;
			return false;
		}
		if(check_draw_situation(board, team))
		{
			*winner = NONE;
			return false;
		}
	}
	return true;
}

bool other_pieces_moveable(CBoard board, Team team)
{
	if(!piece_team_exists(team)) return false;

	Point point; Team currentTeam;

	for(int height = 0; height < BOARD_HEIGHT; height = height + 1)
	{
		for(int width = 0; width < BOARD_WIDTH; width = width + 1)
		{
			point = (Point) {height, width};
			currentTeam = board_point_team(board.board, point);

			if(currentTeam != team) continue;

			if(board_piece_moveable(board, point)) return true;
		}
	}
	return false;
}

bool check_draw_situation(CBoard board, Team team)
{
	if(!piece_team_exists(team)) return false;

	Point king = board_piece_point(board.board, (Piece) {KING, team});

	if(!point_inside_board(king)) return false;

	if(king_inside_check(board.board, king)) return false;

	if(board_piece_moveable(board, king)) return false;

	if(other_pieces_moveable(board, team)) return false;

	return true;
}

bool check_mate_situation(CBoard board, Team team)
{
	if(!piece_team_exists(team)) return false;

	Point king = board_piece_point(board.board, (Piece) {KING, team});

	if(!point_inside_board(king)) return false;

	if(!king_inside_check(board.board, king)) return false;

	if(board_piece_moveable(board, king)) return false;

	if(team_prevent_check(board, team)) return false;

	return true;
}
