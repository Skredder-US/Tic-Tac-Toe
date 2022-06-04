/*
 * Tic Tac Toe
 * A two player game of Tic Tac Toe. Players alternate placing their mark (X or O) until
 * no moves are left (draw) or 3 marks in a row (win!). 
 * 
 * Requires MinGW compiler (for example) or Cygwin with extras. 
 * 
 * 6/3/2022 by Taylor Juve
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 3
#define P1_MARK 'X'
#define P2_MARK 'O'

char grid[SIZE][SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void printGame();
int getMove(bool isP1Turn);
bool isWin();

int main() {
    // Play game
    bool isP1Turn = true;
    int movesLeft = SIZE * SIZE;
    do {
        printGame();
        int move = getMove(isP1Turn);
        if (move != -1) { 
            // is valid move
            // set mark at move location
            grid[move / SIZE][move % SIZE] = isP1Turn ? P1_MARK : P2_MARK; 
            isP1Turn = !isP1Turn; // swap turns
            movesLeft--; 
        }
    } while (movesLeft > 0 && !isWin());

    // Print results
    printGame(); // print final move
    if (isWin()) {
        printf("==>Player %c won!\n", isP1Turn ? '2' : '1');
    } else {
        printf("==>Game draw\n");
    }

    return 0;
}

// Prints the grid to terminal in it's current state of X's, O's, and avaiable spaces.
void printGame() {
    system("cls"); // clears the screen (requires MinGW or Cygwin with extras)
    printf("\n");
    printf("\n");
    printf("\tTic Tac Toe\n");
    printf("\n");
    printf("Player 1 (%c)  -  Player 2 (%c)\n", P1_MARK, P2_MARK);
    printf("\n");
    printf("\n");
    printf("     |     |\n");
    printf("  %c  |  %c  |  %c\n", grid[0][0], grid[0][1], grid[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |\n");
    printf("  %c  |  %c  |  %c\n", grid[1][0], grid[1][1], grid[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |\n");
    printf("  %c  |  %c  |  %c\n", grid[2][0], grid[2][1], grid[2][2]);
    printf("     |     |\n");
    printf("\n");
}

// Prompts terminal for a move and returns it. Invalid moves are checked and execution pauses
// with error message
int getMove(bool isP1Turn) {
    // prompt
    printf("Player %c, enter a number: ", isP1Turn ? '1' : '2');
    
    // get move
    int move;
    scanf("%d", &move);
    move--;

    // check validity, returning only valid moves
    if (move >= 0 && move < SIZE * SIZE) {
        char mark = grid[move / SIZE][move % SIZE];
        if (!(mark == P1_MARK || mark == P2_MARK)) {
            return move;
        }
    }

    // Error msg and pause, returning error code 
    printf("Invalid move\n");
    getch(); // pause until input (requires MinGW or Cygwin with extras)
    return -1;
}

// Tests for wins, true for any 3 of the same mark in a row.
bool isWin() {
    // horizontal
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2]) {
            return true;
        }
    }

    // vertical
    for (int col = 0; col < SIZE; col++) {
        if (grid[0][col] == grid[1][col] && grid[1][col] == grid[2][col]) {
            return true;
        }
    }

    // both diagonal
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) || 
            (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2])) {
        return true;
    }

    return false;
}
