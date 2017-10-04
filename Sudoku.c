#include <stdio.h>
#include "Sudoku.h"

int checker[] = {5, 3, 0, 0, 7, 0, 0, 0, 0,
                 6, 0, 0, 1, 9, 5, 0, 0, 0,
                 0, 9, 8, 0, 0, 0, 0, 6, 0,
                 8, 0, 0, 0, 6, 0, 0, 0, 3,
                 4, 0, 0, 8, 0, 3, 0, 0, 1,
                 7, 0, 0, 0, 2, 0, 0, 0, 6,
                 0, 6, 0, 0, 0, 0, 2, 8, 0,
                 0, 0, 0, 4, 1, 9, 0, 0, 5,
                 0, 0, 0, 0, 8, 0, 0, 7, 9};

void print_board() {
  int i, j, x;
  int board[ROW][COL];

  // Prints the column headings.
  printf("    A   B   C    D   E   F    G   H   I\n");

  // Reads checker[] into board[][]
  x = 0;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      board[i][j] = checker[x];
      x++;
    }
  }

  // Prints board.
  printf("  _______________________________________\n");

  for (i = 0; i < ROW; i++) {
    printf("  |   |   |   ||   |   |   ||   |   |   |\n");
    printf("%d ", i+1);
    for (j = 0; j < COL; j++) {
      if (j == 3 || j ==6) {
        if (board[i][j] == 0) {
          printf("||   ");
        } else {
          printf("|| %d ", board[i][j]);
        }
      } else if (board[i][j] == 0) {
        printf("|   ");
      } else {
        printf("| %d ", board[i][j]);
      }
    }
    printf("|\n");
    printf("  |   |   |   ||   |   |   ||   |   |   |\n");
    if (i == 2 || i == 5) {
      printf("  |-------------------------------------|\n");
      printf("  |-------------------------------------|\n");
    } else {
      printf("  |-------------------------------------|\n");
    }
  }
}

int main() {
  int userROW;
  int userCOL;

  print_board();

  printf("Please select a row: ");
  scanf("%d", &userROW);
  while (userROW < 1 || userROW > 9) {
    printf("Invaild Move. Please select a row: ");
    scanf("%d", &userROW);
  }

  printf("Please select a column: ");
  scanf("%d", &userCOL);
  while (userCOL < 1 || userCOL > 9) {
    printf("Invaild Move. Please select a row: ");
    scanf("%d", &userCOL);
  }

  printf("The current value in that cell is %d.", checker[(9 * (userROW-1) ) + userCOL - 1]);
/*  while (userCOL < 1 || userCOL > 9) {
    printf("Invaild Move. Please select a column: ");
    userCOL = getchar();
  }*/
}
