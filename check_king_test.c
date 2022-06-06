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
    if (chessboard[y][x] == KNIGHT || chessboard[y][x] == ROOK || chessboard[y][x] == PAWN) 
      break;
    else if (chessboard[y][x] == BISHOP ||  chessboard[y][x] == QUEEN) 
      return 1;
  }
  for (int y = king.y, x = king.x; y < 8 && x >= 0; y++, x--) {
    if (chessboard[y][x] == KNIGHT || chessboard[y][x] == ROOK || chessboard[y][x] == PAWN)
      break;
    else if (chessboard[y][x] == BISHOP ||  chessboard[y][x] == QUEEN) 
      return 1;
  }
  for (int y = king.y, x = king.x; y >= 0 &&  x >= 0; y--, x--) {
    if (chessboard[y][x] == KNIGHT || chessboard[y][x] == ROOK || chessboard[y][x] == PAWN) 
      break;
    else if (chessboard[y][x] == BISHOP ||  chessboard[y][x] == QUEEN) 
      return 1;
  }
  for (int y = king.y, x = king.x; y >=0 && x < 8; y--, x++) {
    if (chessboard[y][x] == KNIGHT || chessboard[y][x] == ROOK || chessboard[y][x] == PAWN)
      break;
    else if (chessboard[y][x] == BISHOP ||  chessboard[y][x] == QUEEN)
      return 1;
  }
  return 0;
}

int check_horizantally_and_vertycaly(Pos king, const char chessboard[8][8]){
  for (int x = king.x; x >= 0; x--) {
    if (chessboard[king.y][x] == KNIGHT || chessboard[king.y][x] == BISHOP || chessboard[king.y][x] == PAWN) 
      break;
    else if (chessboard[king.y][x] == ROOK ||  chessboard[king.y][x] == QUEEN) 
      return 1;
  }
  for (int x = king.x; x < 8; x++) {
    if (chessboard[king.y][x] == KNIGHT || chessboard[king.y][x] == BISHOP || chessboard[king.y][x] == PAWN) 
      break;
    else if (chessboard[king.y][x] == ROOK ||  chessboard[king.y][x] == QUEEN) 
      return 1;
  }
  for (int y = king.y; y >= 0; y--) {
    if (chessboard[y][king.x] == KNIGHT || chessboard[y][king.x] == BISHOP || chessboard[y][king.x] == PAWN) 
      break;
    else if (chessboard[y][king.x] == ROOK ||  chessboard[y][king.x] == QUEEN)
      return 1;
  }
  for (int y = king.y; y < 8; y++) {
    if (chessboard[y][king.x] == KNIGHT || chessboard[y][king.x] == BISHOP || chessboard[y][king.x] == PAWN) 
      break;
    else if (chessboard[y][king.x] == ROOK ||  chessboard[y][king.x] == QUEEN) 
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

int is_pawn_on_pos(int possible_pawn_pos_y,int possible_pawn_pos_x,const char chessboard[8][8]) {
  return chessboard[possible_pawn_pos_y][possible_pawn_pos_x] == PAWN;
}

int check_with_a_pawn(Pos king, const char chessboard[8][8]) {
  return is_pawn_on_pos(possible_pawn_pos_y = king.y + 1, possible_pawn_pos_x = king.x + 1, chessboard = chessboard) || is_pawn_on_pos(possible_pawn_pos_y = king.y + 1, possible_pawn_pos_x = king.x - 1, chessboard = chessboard) ||
  is_pawn_on_pos(possible_pawn_pos_y = king.y - 1, possible_pawn_pos_x = king.x - 1, chessboard = chessboard) || is_pawn_on_pos(possible_pawn_pos_y = king.y - 1, possible_pawn_pos_x = king.x + 1, chessboard = chessboard);
}


bool king_is_in_check (const char chessboard[8][8]) {
  Pos king = search_king(chessboard)
  return check_diagonaly(king, chessboard) || check_horizantally_and_vertycaly(king, chessboard) || check_with_a_knight(king, chessboard) || check_with_a_pawn(king, chessboard);
}
