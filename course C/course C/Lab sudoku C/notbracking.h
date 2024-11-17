#ifndef NOTBACKTRAKING_H
#define NOTBACKTRAKING_H

#include "functions.h"

typedef int** SudokuField;

int bt() {
    int size;
    printf("Enter field size (4, 9): ");  //Ввод размерности поля пользователем
    scanf("%d", &size);

    if (size != 4 && size != 9) {             // Проверка на корректность введенного значения
        printf("Incorrect field size :(\n");
        return 1;
    }

    SudokuField field = (SudokuField)malloc(size * sizeof(int*));
    CellStatusField status = (CellStatusField)malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++) {
        field[i] = (int*)malloc(size * sizeof(int));
        status[i] = (int*)malloc(size * sizeof(int));
    }

    initializeField(field, size);

    char choice;
    printf("Choose field type (e - empty, p - partially filled): "); // Выбор пустого или частчно заполненного поля перд началом игры
    scanf(" %c", &choice);

    if (choice == 'p') {
        fillPartialField(field, status, size);
    } else if (choice != 'e') {
        printf("Incorrect value :(  try again\n");
        freeField(field, status, size);
        return 1;
    }

    int selected_row = 0, selected_col = 0;
    char input;

    while (1) {
        printField(field, status, size, selected_row, selected_col);
        fflush(stdout);

        input = _getch();

        // Обработка перемещения
        if (input == 'w' && selected_row > 0) selected_row--;
        if (input == 's' && selected_row < size - 1) selected_row++;
        if (input == 'a' && selected_col > 0) selected_col--;
        if (input == 'd' && selected_col < size - 1) selected_col++;

        // Обработка ввода числа
        if (input >= '1' && input <= '9') {
            int num = input - '0';
            *(*(field + selected_row) + selected_col) = num;
        }

        // Вывод поля после каждого ввода числа
        printField(field, status, size, selected_row, selected_col);
        fflush(stdout);

        // Проверка завершенности и корректности заполненного поля
        if (isSudokuCompleted(field, size)) {
            if (isSudokuCompletedCorrectly(field, size)) {
                printf("Sudoku solved correctly!\n");
            } else {
                printf("Incorrect solution :( \n");
            }
            break;  // Завершение игры
        }

        // if (input == 'q') break;  // Выход из игры
    }

    freeField(field, status, size);
    return 0;
}

#endif