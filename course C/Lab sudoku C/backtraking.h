#ifndef BACKTRAKING_H
#define BACKTRAKING_H

#include "functions.h"

typedef int** playField;
typedef int** color;

int bt() {
    int size;
    printf("Enter field size (4, 9): "); //Ввод размерности поля пользователем
    scanf("%d", &size);

    if (size != 4 && size != 9) {             // Проверка на корректность введенного значения
        printf("Incorrect field size :( \n");
        return 1;
    }

    playField field = (playField)malloc(size * sizeof(int*)); // Объявление и выделение памяти для двумерного массива (поля игры)
    color status = (color)malloc(size * sizeof(int*)); // Объявление и выделение памяти для двумерного массива (значения: 0, 1, 2 для определения цвета значения)

    for (int i = 0; i < size; i++) {
        field[i] = (int*)malloc(size * sizeof(int)); // Выделение памяти для каждой строчки поля (для введённых значений)
        status[i] = (int*)malloc(size * sizeof(int)); // Выделение памяти для каждой строчки поля (для определения ывета значения)
    }

    fillPartialField(field, status, size); // Частичное заполнение поля
    printField(field, status, size, -1, -1); // Вывод поля в терминале

    solveSudoku(field, status, size); // Решение Судоку брутфорсом

    freeField(field, status, size); // Освобождение памяти
    return 0;
}

#endif
