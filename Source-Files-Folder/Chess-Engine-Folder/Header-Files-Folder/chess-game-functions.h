
#ifndef CHESS_GAME_FUNCTIONS_H
#define CHESS_GAME_FUNCTIONS_H

bool other_pieces_moveable(CBoard, Team);

bool check_mate_situation(CBoard, Team);

bool check_draw_situation(CBoard, Team);

bool game_still_running(Team*, CBoard);

#endif
