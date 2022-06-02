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

int check_with_a_queen(int king_y, int king_x, const char chessboard[8][8]) {
  Pos queen = search_queen(chessboard);
  for (int y = king_y, x = king_x; y < 8, x < 8; y++, x++) 
    if (y == queen.y && x == queen.x) 
      return 1;

  for (int y = king_y, x = king_x; y < 8, x > -1; y++, x--) 
    if (y == queen.y && x == queen.x) 
      return 1;

  for (int y = king_y, x = king_x; y > -1, x > -1; y--, x--) 
    if (y == queen.y && x == queen.x) 
      return 1;

  for (int y = king_y, x = king_x; y > -1, x < 8; y--, x++) 
    if (y == queen.y && x == queen.x) 
      return 1;

  if (queen.y == king_y) {
    if (queen.y < king_y) {
      for (int y = queen.y + 1; y < king_y; y++) 
        if (chessboard[y][king_x] == 'R')
          return 1;
    } else if (queen.y > king_y) { 
      for (int y = queen.y - 1; y > king_y; y--) 
        if (chessboard[y][king_x] == 'R')
          return 1;
    }
  } 
  if (queen.x == king_x) {
    if (queen.x < king_x) {
      for (int x = queen.x + 1; x < king_x; x++) 
        if (chessboard[king_y][x] == 'R')
          return 1;
    } else if (queen.x > king_x) {
      for (int x = queen.x - 1; x > king_x; x--) 
        if (chessboard[king_y][x] == 'R')
          return 1;
    }
  }
  return 0; 
}

Pos search_bishop(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'B')
        return (Pos) {x, y};
}

int check_with_a_bishop(int king_y, int king_x, const char chessboard[8][8]) {
  Pos bishop = search_bishop(chessboard);
  for (int y = king_y, x = king_x; y < 8, x < 8; y++, x++) 
    if (y == bishop.y && x == bishop.x) 
      return 1;

  for (int y = king_y, x = king_x; y < 8, x > -1; y++, x--) 
    if (y == bishop.y && x == bishop.x) 
      return 1;

  for (int y = king_y, x = king_x; y > -1, x > -1; y--, x--) 
    if (y == bishop.y && x == bishop.x) 
      return 1;

  for (int y = king_y, x = king_x; y > -1, x < 8; y--, x++) 
    if (y == bishop.y && x == bishop.x) 
      return 1;
}

Pos search_knignt(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'N')
        return (Pos) {x, y};
}

int check_with_a_knight(int king_y, int king_x, const char chessboard[8][8]) {
  Pos knight = search_knight(chessboard);
  int x = king_x + 2;
  int y = king_x + 1;
  if (x == knight.x && y == knight.y)
    return 1;
  x = king_x + 2;
  y = king_y - 1;
  if (x == knight.x && y == knight.y)
    return 1;
  x = king_x - 2;
  y = king_y - 1;
  if (x == knight.x && y == knight.y)
    return 1;
  x = king_x - 2;
  y = king_y + 1;
  if (x == knight.x && y == knight.y)
    return 1;
  x = king_x + 1;
  y = king_y + 2;
  if (x == knight.x && y == knight.y)
    return 1;
  x = king_x + 1;
  y = king_y - 2;
  if (x == knight.x && y == knight.y)
    return 1;
  x = king_x - 1;
  y = king_y - 2;
  if (x == knight.x && y == knight.y)
    return 1;
  x = king_x - 1;
  y = king_y + 2;
  if (x == knight.x && y == knight.y)
    return 1;
  return 0;
}

Pos search_rook(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'R')
        return (Pos) {x, y};
}

int check_with_a_rook(int king_y, int king_x, const char chessboard[8][8]) {
  Pos rook = search_rook(chessboard);
  if (rook.y == king_y) {
    if (rook.y < king_y) {
      for (int y = rook.y + 1; y < king_y; y++) 
        if (chessboard[y][king_x] == 'R')
          return 1;
    } else if (rook.y > king_y) {
      for (int y = rook.y - 1; y > king_y; y--) 
        if (chessboard[y][king_x] == 'R')
          return 1;
    }
  } 
  if (rook.x == king_x) {
    if (rook.x < king_x) {
      for (int x = rook.x + 1; x < king_x; x++) 
        if (chessboard[king_y][x] == 'R')
          return 1;
    } else if (rook.x > king_x){ 
      for (int x = rook.x - 1; x > king_x; x--) 
        if (chessboard[king_y][x] == 'R')
          return 1;
    }
  } 
  return 0;
}

Pos search_pawn(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'P')
        return (Pos) {x, y};
}

int check_with_a_pawn(int king_y, int king_x, const char chessboard[8][8]) {
  Pos pawn = search_pawn(chessboard);
  int y = king_y + 1;
  int x = king_x + 1;
  if (y == pawn.y && x == pawn.x) 
    return 1;

  y = king_y - 1;
  x = king_x + 1;
  if (y == pawn.y && x == pawn.x)
    return 1;

  y = king_y - 1;
  x = king_x - 1;
  if (y == pawn.y && x == pawn.x)
    return 1;

  y = king_y + 1;
  x = king_x - 1;
  if (y == pawn.y && x == pawn.x)
    return 1;
  return 0;
}

bool check_to_the_king(const char chessboard[8][8]) {
  Pos king = search_king(chessboard);
  int check_with_a_queen_1 = check_with_a_queen(king.y, king.x, chessboard);
  int check_with_a_bishop_1 = check_with_a_bishop(king.y, king.x, chessboard);
  int check_with_a_knight_1 = check_with_a_knight(king.y, king.x, chessboard);
  int check_with_a_rook_1 = check_with_a_rook(king.y, king.x, chessboard);
  int check_with_a_pawn_1 = check_with_a_pawn(king.y, king.x, chessboard);

  if (check_with_a_queen_1 == 1 || check_with_a_bishop_1 == 1 || check_with_a_knight_1 == 1 || check_with_a_rook_1 == 1 ||  check_with_a_pawn_1 == 1)
    return true;

  return false;
}

bool king_is_in_check (const char chessboard[8][8]) {
  bool check_to_the_king_1 = check_to_the_king(chessboard);
  return check_to_the_king_1;
}
