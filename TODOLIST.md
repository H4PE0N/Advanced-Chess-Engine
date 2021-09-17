
rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1

DATA TYPES:

Point       int, int
Team        int
Type        int
Piece       int, int
Castle      bool, bool
Move        Point, Point
Board       Piece[8][8], Team, Castle, Castle, int, Move[256]
