#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void drawBoard() {
    system("cls"); // Clear screen (Windows)
    printf("=== TIC-TAC-TOE ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

int checkWin() {
    // Cek baris
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1;
    }
    // Cek kolom
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1;
    }
    // Cek diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1;
    return 0;
}

int isFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void computerMove() {
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (board[x][y] != ' ');
    board[x][y] = 'O';
}

int main() {
    int row, col, turn = 0; // 0: player, 1: computer
    char playAgain;

    srand(time(NULL));

    do {
        // Reset board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        turn = 0;

        while (1) {
            drawBoard();

            if (turn == 0) { // Player turn
                printf("Giliran Anda (X). Masukkan baris (1-3) dan kolom (1-3): ");
                scanf("%d %d", &row, &col);
                row--; col--; // Adjust to 0-based index
                if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                    board[row][col] = 'X';
                    turn = 1;
                } else {
                    printf("Posisi tidak valid atau sudah terisi!\n");
                    continue;
                }
            } else { // Computer turn
                printf("Giliran Komputer (O)...\n");
                computerMove();
                turn = 0;
            }

            if (checkWin()) {
                drawBoard();
                if (turn == 1) {
                    printf("Selamat! Anda menang!\n");
                } else {
                    printf("Komputer menang!\n");
                }
                break;
            }

            if (isFull()) {
                drawBoard();
                printf("Seri!\n");
                break;
            }
        }

        printf("Apakah Anda ingin bermain lagi? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Terima kasih telah bermain!\n");
    return 0;
}

