#ifndef BACKTRAKING_H
#define BACKTRAKING_H

#include "functions.h"

typedef int** SudokuField;
typedef int** CellStatusField;

int bt() {
    int size;
    printf("Enter field size (4, 9): "); //Ввод размерности поля пользователем
    scanf("%d", &size);

    if (size != 4 && size != 9) {             // Проверка на корректность введенного значения
        printf("Incorrect field size :( \n");
        return 1;
    }

    SudokuField field = (SudokuField)malloc(size * sizeof(int*));
    CellStatusField status = (CellStatusField)malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++) {
        field[i] = (int*)malloc(size * sizeof(int));
        status[i] = (int*)malloc(size * sizeof(int));
    }

    fillPartialField(field, status, size);
    printField(field, status, size, -1, -1);

    solveSudoku(field, status, size);

    freeField(field, status, size);
    return 0;
}

#endif