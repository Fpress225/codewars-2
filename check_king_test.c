#include <stdbool.h>

#define QUEEN 'Q'
#define BISHOP 'B'
#define KNIGHT 'N'
#define ROOK 'R'
#define PAWN 'P'

typedef struct coordinates_of_the_shape {
  int x, y;
} Pos;

Pos search_king(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'K')
        return (Pos) {x, y};
  return (Pos) {.x = 0, .y = 0};
}

int check_diagonaly(Pos king, const char chessboard[8][8]) {
  for (int y = king.y, x = king.x; y < 8 && x < 8; y++, x++) {
    if (chessboard[y][x] == KNIGHT || chessboard[y][x] == ROOK || chessboard[y][x] == PAWN) // N = knight, B = bishop, P = pawn
      breack;
    else if (chessboard[y][x] == BISHOP ||  chessboard[y][x] == QUEEN) // R = rook, Q = queenv
      return 1;
  }
  for (int y = king.y, x = king.x; y < 8 && x >= 0; y++, x--) {
    if (chessboard[y][x] == KNIGHT || chessboard[y][x] == ROOK || chessboard[y][x] == PAWN) // N = knight, B = bishop, P = pawn
      breack;
    else if (chessboard[y][x] == BISHOP ||  chessboard[y][x] == QUEEN) // R = rook, Q = queenv
      return 1;
  }
  for (int y = king.y, x = king.x; y >= 0 &&  x >= 0; y--, x--) {
    if (chessboard[y][x] == KNIGHT || chessboard[y][x] == ROOK || chessboard[y][x] == PAWN) // N = knight, B = bishop, P = pawn
      breack;
    else if (chessboard[y][x] == BISHOP ||  chessboard[y][x] == QUEEN) // R = rook, Q = queenv
      return 1;
  }
  for (int y = king.y, x = king.x; y >=0 && x < 8; y--, x++) {
    if (chessboard[y][x] == KNIGHT || chessboard[y][x] == ROOK || chessboard[y][x] == PAWN) // N = knight, B = bishop, P = pawn
      breack;
    else if (chessboard[y][x] == BISHOP ||  chessboard[y][x] == QUEEN) // R = rook, Q = queenv
      return 1;
  }
  return 0;
}

int check_horizantally_and_vertycaly(Pos king, const char chessboard[8][8]){
  for (int x = king.x; x > -1; x--) {
    if (chessboard[king.y][x] == KNIGHT || chessboard[king.y][x] == BISHOP || chessboard[king.y][x] == PAWN) // N = knight, B = bishop, P = pawn
      breack;
    else if (chessboard[king.y][x] == ROOK ||  chessboard[king.y][x] == QUEEN) // R = rook, Q = queenv
      return 1;
  }
  for (int x = king.x; x < 8; x++) {
    if (chessboard[king.y][x] == KNIGHT || chessboard[king.y][x] == BISHOP || chessboard[king.y][x] == PAWN) // N = knight, B = bishop, P = pawn
      breack;
    else if (chessboard[king.y][x] == ROOK ||  chessboard[king.y][x] == QUEEN) // R = rook, Q = queen
      return 1;
  }
  for (int y = king.y; y > -1; y--) {
    if (chessboard[y][king.x] == KNIGHT || chessboard[y][king.x] == BISHOP || chessboard[y][king.x] == PAWN) // N = knight, B = bishop, P = pawn
      breack;
    else if (chessboard[y][king.x] == ROOK ||  chessboard[y][king.x] == QUEEN) // R = rook, Q = queen
      return 1;
  }
  for (int y = king.y; y < 8; y++) {
    if (chessboard[y][king.x] == KNIGHT || chessboard[y][king.x] == BISHOP || chessboard[y][king.x] == PAWN) // N = knight, B = bishop, P = pawn
      breack;
    else if (chessboard[y][king.x] == ROOK ||  chessboard[y][king.x] == QUEEN) // R = rook, Q = queen
      return 1;
  }
  return 0;
}

int check_with_a_knight(Pos king, const char chessboard[8][8]) {
  int x = king.x + 2;
  int y = king.x + 1;
  if (chessboard[y][x] == KNIGHT)
    return 1;
  x = king.x + 2;
  y = king.y - 1;
  if (chessboard[y][x] == KNIGHT)
    return 1;
  x = king.x - 2;
  y = king.y - 1;
  if (chessboard[y][x] == KNIGHT)
    return 1;
  x = king.x - 2;
  y = king.y + 1;
  if (chessboard[y][x] == KNIGHT)
    return 1;
  x = king.x + 1;
  y = king.y + 2;
  if (chessboard[y][x] == KNIGHT)
    return 1;
  x = king.x + 1;
  y = king.y - 2;
  if (chessboard[y][x] == KNIGHT)
    return 1;
  x = king.x - 1;
  y = king.y - 2;
  if (chessboard[y][x] == KNIGHT)
    return 1;
  x = king.x - 1;
  y = king.y + 2;
  if (chessboard[y][x] == KNIGHT)
    return 1;
  return 0;
}

int check_with_a_pawn(Pos king, const char chessboard[8][8]) {
  int y = king.y + 1;
  int x = king.x + 1;
  if (chessboard[y][x] == PAWN) 
    return 1;

  y = king.y - 1;
  x = king.x + 1;
  if (chessboard[y][x] == PAWN)
    return 1;

  y = king.y - 1;
  x = king.x - 1;
  if (chessboard[y][x] == PAWN)
    return 1;

  y = king.y + 1;
  x = king.x - 1;
  if (chessboard[y][x] == PAWN)
    return 1;
  return 0;
}


bool king_is_in_check (const char chessboard[8][8]) {
  Pos king = search_king(chessboard);
  int check_diag = check_diagonaly(king, chessboard);
  int check_hor_and_vert = check_horizantally_and_vertycaly(king, chessboard);
  int knight_checked = check_with_a_knight(king, chessboard);
  int pawn_checked = check_with_a_pawn(king, chessboard);
  if (check_diag == 1 || check_hor_and_vert == 1 || knight_checked == 1 || pawn_checked  ==  1) 
    return true;
  return false;
}
