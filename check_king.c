#include <stdbool.h>

struct cots { // coordinates of the shapes

  int x, y;

};

struct cots search_king(const char chessboard[8][8]) {

  for (int y = 0; y < 8; y++) 

    for (int x = 0; x < 8; x++)

      if (chessboard[x][y] == 'K')

        return struct cots k = {x, y}; // k = king

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

  bool check_horiz = check_horizontally(chessboard);

  bool check_vertic = check_vertically(chessboard);

  if (check_horiz || check_vertic) {

    return true;

  }

  return false;

}
