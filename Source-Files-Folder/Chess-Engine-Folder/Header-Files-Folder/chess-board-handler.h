
#ifndef CHESS_BOARD_HANDLER_H
#define CHESS_BOARD_HANDLER_H

void allocate_board_piece(Piece**, Point, Piece);

Piece board_point_piece(Piece**, Point);

void copy_board_variable(Piece**, Piece**);

Type board_point_type(Piece**, Point);

Team board_point_team(Piece**, Point);

bool board_piece_points(Point*, Piece**, Piece);

Point board_piece_point(Piece**, Piece);

void update_castle_value(Castle*, Side, bool);

void update_castles_value(Castles*, Team, Side, bool);

bool board_castles_value(Castles, Team, Side);

bool board_castle_value(Castle, Side);

void update_castles_values(Castles*, Team, Castle);

void move_board_piece(Piece**, Point, Point);

void switch_chess_pieces(Piece**, Point, Point);

void remove_board_piece(Piece**, Point);

void allocate_board_memory(Board*);

void free_board_variable(Board);

#endif
