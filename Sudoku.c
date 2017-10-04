#include <stdio.h>
#include <stdbool.h>
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

int board[ROW][COL];
int boardI[ROW][COL];

void initBoard() {
  int i, j, x;
  // Reads checker[] into board[][]
  x = 0;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      board[i][j] = checker[x];
      boardI[i][j] = checker[x];
      x++;
    }
  }

}

void print_board() {
  int i, j, x;

  // Prints the column headings.
  printf("    A   B   C    D   E   F    G   H   I\n");

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

bool isValidCell(int row, int col){
  if(boardI[row][col]== 0){
    return true;
  } else {
    return false;
  }
}

bool gameOver() {
  //check if game board is solved
  return false;
}

bool isValidMove(int row, int col, int input){
  bool valid = true;

  //check to make sure the variable is in bounds
  if(input<0 || input>8){
    return false;
  }

  //have to check if the box its in is valid (dosent have number in cell)

  //check if the row its in dosent have the val

  //check if the col its in dosent have the val

  return valid;
}

int main() {
  int userROW;
  int userCOL;
  int tempVal;

initBoard();

  while(gameOver()!= true){
    print_board();

    printf("Please select a row: ");
    scanf("%d", &userROW);
    while (userROW < 0 || userROW > 8) {
      printf("Invaild Move. Please select a row: ");
      scanf("%d", &userROW);
    }

    printf("Please select a column: ");
    scanf("%d", &userCOL);
    while (userCOL < 0 || userCOL > 8) {
      printf("Invaild Move. Please select a row: ");
      scanf("%d", &userCOL);
    }

    printf("The current value in that cell is %d.\n", board[userROW][userCOL]);

    if(!isValidCell(userROW,userCOL)){
      printf("Invaild Cell, cant change!\n");
      continue;
    }
    printf("Enter new number for cell: ");
    scanf("%d", &tempVal);
    if(isValidMove(userROW,userCOL,tempVal)){
      board[userROW][userCOL] = tempVal;
    }else {
      printf("That is an illegal move!\n");
    }
  }

  printf("Congrats you have won the game! Final Board: \n");
  print_board();


/*  while (userCOL < 1 || userCOL > 9) {
    printf("Invaild Move. Please select a column: ");
    userCOL = getchar();
  }*/
}
