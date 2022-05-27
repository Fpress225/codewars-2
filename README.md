#include <stdbool.h>

struct cots { // coordinates of the shapes
  int x, y;
};

struct cots search_king(const char chessboard[8][8]) {
  struct cots k; // k = king
  for (k.y = 0; k.y < 8; k.y++) 
    for (k.x = 0; k.x < 8; k.x++)
      if (chessboard[k.x][k.y] == 'K')
        return k;
}

bool check_horizontally(const char chessboard[8][8]) {
  struct cots k = search_king(chessboard); // k = king
  for (int k_x = k.x; k_x > -1; k_x--) {
    if (chessboard[k_x][k.y] == 'N' || chessboard[k_x][k.y] == 'R' || chessboard[k_x][k.y] == 'P')
      return false;
    else if (chessboard[k_x][k.y] == 'B' ||  chessboard[k_x][k.y] == 'Q')
      return true;
  }
  for (int k_x = k.x; k_x < 8; k_x++) {
    if (chessboard[k_x][k.y] == 'N' || chessboard[k_x][k.y] == 'R' || chessboard[k_x][k.y] == 'P')
      return false;
    else if (chessboard[k_x][k.y] == 'B' ||  chessboard[k_x][k.y] == 'Q')
      return true;
  }
  return false;
}

bool check_vertically(const char chessboard[8][8]) {
  struct cots k = search_king(chessboard); // k = king
  for (int k_y = k.y; k_y > -1; k_y--) {
    if (chessboard[k.x][k_y] == 'N' || chessboard[k.x][k_y] == 'R' || chessboard[k.x][k_y] == 'P')
      return false;
    else if (chessboard[k.x][k_y] == 'B' ||  chessboard[k.x][k_y] == 'Q')
      return true;
  }
  for (int k_y = k.y; k_y < 8; k_y++) {
    if (chessboard[k.x][k_y] == 'N' || chessboard[k.x][k_y] == 'R' || chessboard[k.x][k_y] == 'P')
      return false;
    else if (chessboard[k.x][k_y] == 'B' ||  chessboard[k.x][k_y] == 'Q')
      return true;
  }
  return false;
}


bool king_is_in_check (const char chessboard[8][8])
{
  bool pidor_1 = check_horizontally(chessboard);
  bool pidor_2 = check_vertically(chessboard);
  if (pidor_1 || pidor_2) {
    return true;
  }
  return false;
}
