#include <stdbool.h>

typedef struct coordinates_of_the_shape {
  int x, y;
} Pos;

Pos search_king(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'K')
        return (Pos) {x, y};
}

Pos search_queen(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'Q')
        return (Pos) {x, y};
}

Pos search_bishop(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'B')
        return (Pos) {x, y};
}

int check_with_a_bishop(const char chessboard[8][8]) {
  Pos king = search_king(chessboard);
  Pos bishop = search_bishop(chessboard);
  for ()
}

Pos search_knignt(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'N')
        return (Pos) {x, y};
}

Pos search_rook(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'R')
        return (Pos) {x, y};
}

int check_with_a_rook(const char cheesboardd[8][8]) {
  Pos king = search_king(chessboard);
  Pos rook = search_rook(chessboard);
  if (rook.y == king.y) {
    if (rook.y < king.y) 
      for (int y = rook.y + 1; y < king.y; y++) 
        if (chessboard[y][king.x] == ' ')
          return 1;
    else if (rook.y > king.y) 
      for (int y = rook.y - 1; y > king.y; y--) 
        if (chessboard[y][king.x] == ' ')
          return 1;
  } 
  if (rook.x == king.x) {
    if (rook.x < king.x) 
      for (int x = rook.x + 1; x < king.x; x++) 
        if (chessboard[king.y][x] == ' ')
          return 1;
    else if (rook.x > king.x) 
      for (int x = rook.x - 1; y > king.x; x--) 
        if (chessboard[king.y][x] == ' ')
          return 1;
  } 
  return 0;
}

Pos search_pawn(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'P')
        return (Pos) {x, y};
}

int check_with_a_pawn(const char chessboard[8][8]) {
  Pos king = search_king(chessboard);
  Pos pawn = search_pawn(chessboard);
  int y = king.y + 1;
  int x = king.x + 1;
  if (y == pawn.y && x == pawn.x) 
    return 1;

  y = king.y - 1;
  x = king.x + 1;
  if (y == pawn.y && x == pawn.x)
    return 1;

  y = king.y - 1;
  x = king.x - 1;
  if (y == pawn.y && x == pawn.x)
    return 1;

  y = king.y + 1;
  x = king.x - 1;
  if (y == pawn.y && x == pawn.x)
    return 1;
  return 0;
}

bool check_to_the_king(const char chessboard[8][8]) {
  int check_with_a_rook = check_with_a_rook(chessboard);
  int check_with_a_pawn = check_with_a_pawn(chessboard);
}

bool king_is_in_check (const char chessboard[8][8]) {
  return false;
}
