
#ifndef BOARD_VALUE_GENERATOR_H
#define BOARD_VALUE_GENERATOR_H

extern const int pieceMatrix[7][BOARD_HEIGHT][BOARD_WIDTH];

extern const int pieceValues[7];

int team_pieces_value(Board, Team);

int piece_matrix_value(Piece, Point);

int team_state_value(CBoard, Team);

int board_state_value(CBoard, Team);

int game_draw_value(CBoard, Team);

int check_mate_value(CBoard, Team);

#endif
