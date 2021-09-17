
#ifndef CHESS_BOARD_EXTRACTOR_H
#define CHESS_BOARD_EXTRACTOR_H

bool create_fen_board(CBoard*, char[]);

bool extract_letter_piece(Piece*, char);
bool extract_letter_team(Team*, char);
bool extract_letter_castle(Castles*, char);

bool extract_fen_board(Board*, char[]);
bool extract_fen_castles(Castles*, char[]);

#endif
