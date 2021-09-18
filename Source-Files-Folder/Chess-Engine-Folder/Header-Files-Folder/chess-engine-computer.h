
#ifndef CHESS_ENGINE_COMPUTER_H
#define CHESS_ENGINE_COMPUTER_H

bool best_possible_move(Move*, CBoard, int, Team);

int board_depth_value(CBoard, int, int, int, Team, Team);

bool every_possible_move(Move*, CBoard, Team);

#endif
