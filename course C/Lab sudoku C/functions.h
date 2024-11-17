#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

typedef int** SudokuField;
typedef int** CellStatusField;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Инициализация ячеек нулями для значений в поле
void initializeField(SudokuField field, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(field + i) + j) = 0;
        }
    }
}

// Инициализация ячеек нулями для определения цвета значений
void initializeCellStatus(CellStatusField status, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(status + i) + j) = 0;  // 0 - нет значения(белый цвет), 1 - сгенерированное программой(синий цвет), 2 - введенное пользователем(зеленый цвет)
        }
    }
}

// Вывод поля игры в терминале
void printField(SudokuField field, CellStatusField status, int size, int selected_row, int selected_col) {
    system("cls");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == selected_row && j == selected_col) {
                printf("[");
            } else {
                printf(" ");
            }

            if (*(*(field + i) + j) == 0) {
                printf(" . ");
            } else {
                if (*(*(status + i) + j) == 2) {
                    setColor(10);
                } else {
                    setColor(9); 
                }
                printf("%2d ", *(*(field + i) + j));
                setColor(15);
            }

            if (i == selected_row && j == selected_col) {
                printf("]");
            }
        }
        printf("\n");
    }
}

int isValidMove(SudokuField field, int size, int row, int col, int num) {
    for (int i = 0; i < size; i++) {
        if (*(*(field + row) + i) == num || *(*(field + i) + col) == num) {
            return 0;
        }
    }

    int squareSize = (int)sqrt(size);
    int squareRow = row - row % squareSize;
    int squareCol = col - col % squareSize;
    
    for (int i = 0; i < squareSize; i++) {
        for (int j = 0; j < squareSize; j++) {
            if (*(*(field + squareRow + i) + squareCol + j) == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(SudokuField field, CellStatusField status, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (*(*(field + row) + col) == 0) {
                for (int num = 1; num <= size; num++) {
                    if (isValidMove(field, size, row, col, num)) {
                        *(*(field + row) + col) = num;
                        *(*(status + row) + col) = 2;
                        printField(field, status, size, -1, -1);
                        Sleep(100);
                        if (solveSudoku(field, status, size)) {
                            return 1;
                        }
                        *(*(field + row) + col) = 0;
                        *(*(status + row) + col) = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int fillSudoku(SudokuField field, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (*(*(field + row) + col) == 0) {
                for (int num = 1; num <= size; num++) {
                    if (isValidMove(field, size, row, col, num)) {
                        *(*(field + row) + col) = num;
                        if (fillSudoku(field, size)) {
                            return 1;
                        }
                        *(*(field + row) + col) = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

void fillPartialField(SudokuField field, CellStatusField status, int size) {
    srand(time(NULL));
    initializeField(field, size);
    initializeCellStatus(status, size);
    fillSudoku(field, size);

    int count;
    if (size == 4) {
        count = rand() % 16;
    } else {
        count = rand() % 81;
    }

    while (count > 0) {
        int row = rand() % size;
        int col = rand() % size;
        if (*(*(field + row) + col) != 0) {
            *(*(field + row) + col) = 0;
            *(*(status + row) + col) = 0;
            count--;
        }
    }
}

int isSudokuCompleted(SudokuField field, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(*(field + i) + j) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Проверка на корректность заполненного поьзователем поля игры
int isSudokuCompletedCorrectly(SudokuField field, int size) {
    int squareSize = (int)sqrt(size);
    
    // Проверка строк и столбцов
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            int num = *(*(field + row) + col);
            if (num == 0) return 0; // Пустые клетки не должны быть в решении

            // Проверка на повторы в строках
            for (int k = 0; k < size; k++) {
                if (k != col && *(*(field + row) + k) == num) {
                    return 0;
                }
            }

            // Проверка на повторы в столбцах
            for (int k = 0; k < size; k++) {
                if (k != row && *(*(field + k) + col) == num) {
                    return 0;
                }
            }
        }
    }
    
    // Проверка на повторы в квадратах
    for (int squareRow = 0; squareRow < size; squareRow += squareSize) {
        for (int squareCol = 0; squareCol < size; squareCol += squareSize) {
            int seen[10] = {0}; // Массив для отслеживания чисел в квадрате
            for (int i = 0; i < squareSize; i++) {
                for (int j = 0; j < squareSize; j++) {
                    int num = *(*(field + squareRow + i) + squareCol + j);
                    if (num == 0) continue;  // Пропустить пустые клетки
                    if (seen[num]) return 0;  // Если число уже встречалось в квадрате
                    seen[num] = 1;
                }
            }
        }
    }

    return 1;  // Все проверки прошли успешно
}

// Освобождение памяти
void freeField(SudokuField field, CellStatusField status, int size) {
    for (int i = 0; i < size; i++) {
        free(field[i]);
        free(status[i]);
    }
    free(field);
    free(status);
}

#endif