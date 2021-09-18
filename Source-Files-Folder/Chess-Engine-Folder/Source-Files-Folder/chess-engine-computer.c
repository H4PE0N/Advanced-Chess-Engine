
#include "../Header-Files-Folder/chess-engine-includer.h"

bool best_possible_move(Move* move, CBoard board, int depth, Team team)
{
	if(!piece_team_exists(team) || depth <= 0) return false;

  Move* moves = create_moves_array(128);

	if(!every_possible_move(moves, board, team))
  {
    printf("Cant find move!\n");

		free(moves);

    return false;
  }

	int amount = moves_array_amount(moves);

	Move bestMove = moves[0];
	int bestValue = MIN_VAL;

  Move currentMove;
  int currentValue;

  Team nextTeam;

	CBoard boardCopy;

	for(int index = 0; index < amount; index += 1)
	{
		boardCopy = board; boardCopy.current = team;

		currentMove = moves[index];

		if(!move_chess_piece(&boardCopy, currentMove))
		{
			// For some reson, the computer cant move!
			continue;
		}

		nextTeam = (team == WHITE) ? BLACK : WHITE;
		currentValue = board_depth_value(boardCopy, (depth - 1), MIN_VAL, MAX_VAL, team, nextTeam);

		if(currentValue > bestValue)
    {
      bestMove = currentMove;
      bestValue = currentValue;
    }
	}

	free(moves);

	printf("Found move [%d %d] -> [%d %d] Score = %d\n",
    bestMove.start.height, bestMove.start.width, bestMove.stop.height, bestMove.stop.width, bestValue);

	*move = bestMove;

  return true;
}

int board_depth_value(CBoard board, int depth, int alpha, int beta, Team team, Team currentTeam)
{
	// Base-case, Should return the value of the board
	if(depth <= 0) return team_state_value(board, team);

	Move* moves = create_moves_array(128);

	if(!every_possible_move(moves, board, currentTeam))
  {
    printf("Cant find move!\n");

		free(moves);

    return false;
  }

	int amount = moves_array_amount(moves);

	if(amount <= 0) return team_state_value(board, team);

	int bestValue = (currentTeam == team) ? MIN_VAL : MAX_VAL;

	Move currentMove;
  int currentValue;
  Team nextTeam;

  CBoard boardCopy;

	for(int index = 0; index < amount; index += 1)
	{
    boardCopy = board; boardCopy.current = currentTeam;

		currentMove = moves[index];

		if(!move_chess_piece(&boardCopy, currentMove))
		{
			continue;
		}

		nextTeam = (currentTeam == WHITE) ? BLACK : WHITE;
		currentValue = board_depth_value(boardCopy, (depth - 1), alpha, beta, team, nextTeam);

		if(currentTeam == team && currentValue > bestValue) 	bestValue = currentValue;
		if(currentTeam != team && currentValue < bestValue) 	bestValue = currentValue;

		if(currentTeam == team && currentValue > alpha) 		alpha = currentValue;
		if(currentTeam != team && currentValue < beta) 		beta = currentValue;

		if(beta <= alpha) break;
	}

	free(moves);

	return bestValue;
}

bool every_possible_move(Move* moves, CBoard board, Team team)
{
	Point point;
  Team currentTeam;

	Move* adding;

	for(int height = 0; height < BOARD_HEIGHT; height += 1)
	{
		for(int width = 0; width < BOARD_WIDTH; width += 1)
		{
			point = (Point) {height, width};
			currentTeam = board_point_team(board.board, point);

			if(currentTeam != team) continue;

			// The queen can do the most moves, and she can do 32 moves
			adding = create_moves_array(40);

			if(!piece_possible_moves(adding, board, point))
			{
				free(adding);

				continue;
			}

			append_moves_array(moves, adding);

			free(adding);
		}
	}

	return true;
}
