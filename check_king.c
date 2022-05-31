#include <stdbool.h>

typedef struct coordinates_of_the_king {
  int x, y;
} Pos;

struct cots search_king(const char chessboard[8][8]) {
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++)
      if (chessboard[y][x] == 'K')
        return (Pos) {x, y}
}

bool check_horizontally(const char chessboard[8][8]) {
  Pos king = search_king(chessboard);
  for (int x = k.x; x > -1; x--) {
    if (chessboard[king.y][x] == 'N' || chessboard[king.y][x] == 'R' || chessboard[king.y][x] == 'P')
      return false;
    else if (chessboard[king.y][x] == 'B' ||  chessboard[king.y][x] == 'Q')
      return true;
  }
  for (int x = k.x; x < 8; x++) {
    if (chessboard[king.y][x] == 'N' || chessboard[king.y][x] == 'R' || chessboard[king.y][x] == 'P')
      return false;
    else if (chessboard[king.y][x] == 'B' ||  chessboard[king.y][x] == 'Q')
      return true;
  }
  return false;
}

bool check_vertically(const char chessboard[8][8]) {
  Pos king = search_king(chessboard);
  for (int y = king.y; y > -1; y--) {
    if (chessboard[y][king.x] == 'N' || chessboard[y][king.x] == 'R' || chessboard[y][king.x] == 'P')
      return false;
    else if (chessboard[y][king.x] == 'B' ||  chessboard[y][king.x] == 'Q')
      return true;
  }
  for (int y = king.y; y < 8; y++) {
    if (chessboard[y][king.x] == 'N' || chessboard[y][king.x] == 'R' || chessboard[y][king.x] == 'P')
      return false;
    else if (chessboard[y][king.x] == 'B' ||  chessboard[y][king.x] == 'Q')
      return true;
  }
  return false;
}

bool king_is_in_check (const char chessboard[8][8])
{
  bool check_horiz = check_horizontally(chessboard);
  bool check_vertic = check_vertically(chessboard)
  if (check_horiz == true || check_vertic == true) {
    return true;
  }
  return false;
}
