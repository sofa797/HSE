#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

typedef int** playField;
typedef int** color;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Функция инициализация ячеек нулями для значений в поле
void makeField(playField field, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(field + i) + j) = 0;
        }
    }
}

// Функция нициализации ячеек нулями для определения цвета значений
void makeColor(color status, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(status + i) + j) = 0;  // 0 - нет значения(белый цвет), 1 - сгенерированное программой(синий цвет), 2 - введенное пользователем(зеленый цвет)
        }
    }
}

// Функция вывода поля игры в терминале
void printField(playField field, color status, int size, int row, int col) {
    system("cls");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == row && j == col) {
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

            if (i == row && j == col) {
                printf("]");
            }
        }
        printf("\n");
    }
}

// Функция для проверки, верно ли введено значение
int correctMove(playField field, int size, int row, int col, int num) {
    for (int i = 0; i < size; i++) {
        if (*(*(field + row) + i) == num || *(*(field + i) + col) == num) {
            return 0;
        }
    }

    int sizesq = (int)sqrt(size);
    int rowsq = row - row % sizesq;
    int colsq = col - col % sizesq;
    
    for (int i = 0; i < sizesq; i++) {
        for (int j = 0; j < sizesq; j++) {
            if (*(*(field + rowsq + i) + colsq + j) == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Функция для решения Судоку брутфорсом
int solveSudoku(playField field, color status, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (*(*(field + row) + col) == 0) {
                for (int num = 1; num <= size; num++) {
                    if (correctMove(field, size, row, col, num)) {
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
 // Функция для автоматического заполнеия поля, чтобы сгенерировать частично заполненное поле
int fillField(playField field, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (*(*(field + row) + col) == 0) {
                for (int num = 1; num <= size; num++) {
                    if (correctMove(field, size, row, col, num)) {
                        *(*(field + row) + col) = num;
                        if (fillField(field, size)) {
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
 // Функция для частично заполненного поля
void fillPartialField(playField field, color status, int size) {
    srand(time(NULL));
    makeField(field, size);
    makeColor(status, size);
    fillField(field, size);

    int count;
    if (size == 4) {
        count = rand() % 16; // Количество ячеек, которые будут случайно заполнены для поля 4*4
    } else {
        count = rand() % 81; // Количество ячеек, которые будут случайно заполнены для поля 9*9
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

// Функция для проверки, полностью ли заполнено игровое поле
int completeField(playField field, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(*(field + i) + j) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Функция для проверки на корректность заполненного поьзователем поля игры
int completeFieldCorrectly(playField field, int size) {
    int sizesq = (int)sqrt(size);
    
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
    for (int rowsq = 0; rowsq < size; rowsq += sizesq) {
        for (int colsq = 0; colsq < size; colsq += sizesq) {
            int seen[10] = {0}; // Массив для отслеживания чисел в квадрате
            for (int i = 0; i < sizesq; i++) {
                for (int j = 0; j < sizesq; j++) {
                    int num = *(*(field + rowsq + i) + colsq + j);
                    if (num == 0) continue;  // Пропустить пустые клетки
                    if (seen[num]) return 0;  // Если число уже встречалось в квадрате
                    seen[num] = 1;
                }
            }
        }
    }

    return 1;  // Все проверки прошли успешно
}

// Функция для освобожденя памяти
void freeField(playField field, color status, int size) {
    for (int i = 0; i < size; i++) {
        free(field[i]);
        free(status[i]);
    }
    free(field);
    free(status);
}

#endif
