#include <stdio.h>
#include <stdlib.h>

// Grid Sudoku 9x9 (0 berarti kosong)
int grid[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// Fungsi untuk menampilkan grid dengan visual
void printGrid() {
    system("cls"); // Clear screen (Windows)
    printf("=== SUDOKU GAME ===\n\n");
    printf("   0 1 2   3 4 5   6 7 8\n");
    printf(" +-------+-------+-------+\n");
    for (int i = 0; i < 9; i++) {
        printf("%d|", i);
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                printf(" .");
            } else {
                printf(" %d", grid[i][j]);
            }
            if ((j + 1) % 3 == 0 && j != 8) printf(" |");
        }
        printf(" |\n");
        if ((i + 1) % 3 == 0 && i != 8) {
            printf(" +-------+-------+-------+\n");
        }
    }
    printf(" +-------+-------+-------+\n\n");
}

// Fungsi untuk memeriksa apakah angka valid di posisi tertentu
int isValid(int row, int col, int num) {
    // Cek baris
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == num) return 0;
    }
    // Cek kolom
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) return 0;
    }
    // Cek kotak 3x3
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) return 0;
        }
    }
    return 1;
}

// Fungsi untuk memeriksa apakah grid penuh
int isFull() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) return 0;
        }
    }
    return 1;
}

int main() {
    int row, col, num;
    
    while (1) {
        printGrid();
        
        if (isFull()) {
            printf("Selamat! Anda telah menyelesaikan Sudoku!\n");
            break;
        }
        
        printf("Masukkan baris (0-8), kolom (0-8), dan angka (1-9): ");
        scanf("%d %d %d", &row, &col, &num);
        
        if (row < 0 || row > 8 || col < 0 || col > 8 || num < 1 || num > 9) {
            printf("Input tidak valid! Coba lagi.\n");
            continue;
        }
        
        if (grid[row][col] != 0) {
            printf("Sel sudah terisi! Coba lagi.\n");
            continue;
        }
        
        if (!isValid(row, col, num)) {
            printf("Angka tidak valid! Coba lagi.\n");
            continue;
        }
        
        grid[row][col] = num;
    }
    
    return 0;
}
