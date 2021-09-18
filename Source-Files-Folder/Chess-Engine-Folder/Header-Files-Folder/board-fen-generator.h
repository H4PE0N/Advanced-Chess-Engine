
#ifndef BOARD_FEN_GENERATOR_H
#define BOARD_FEN_GENERATOR_H

bool generate_board_fen(char*, CBoard);

bool create_board_fen(char*, Board);

bool create_current_fen(char*, Team);

bool create_castles_fen(char*, Castles);

bool create_passant_fen(char*, Point);

#endif
