#ifndef NOTBACKTRAKING_H
#define NOTBACKTRAKING_H

#include "functions.h"

typedef int** playField;

int bt() {
    int size;
    printf("Enter field size (4, 9): ");  //Ввод размерности поля пользователем
    scanf("%d", &size);

    if (size != 4 && size != 9) { // Проверка на корректность введенного значения
        printf("Incorrect field size :( try again\n");
        return 1;
    }

    playField field = (playField)malloc(size * sizeof(int*)); // Объявление и выделение памяти для двумерного массива (поля игры)
    color status = (color)malloc(size * sizeof(int*)); // Объявление и выделение памяти для двумерного массива (значения: 0, 1, 2 для определения цвета значения)

    for (int i = 0; i < size; i++) {
        field[i] = (int*)malloc(size * sizeof(int)); // Выделение памяти для каждой строчки поля (для введённых значений)
        status[i] = (int*)malloc(size * sizeof(int)); // Выделение памяти для каждой строчки поля (для определения ывета значения)
    }

    makeField(field, size);

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

    int row = 0, col = 0;
    char input;

    while (1) { // Пока пользователь вводит значения, выполняется следующий цикл
        printField(field, status, size, row, col);
        fflush(stdout);

        input = _getch();

        if (input == '\x1B') { // Досрочный выход из программы с помощью клавиши ESС
            break;;
        }

        // Перемещение по полю
        if (input == 'w' && row > 0) row--;
        if (input == 's' && row < size - 1) row++;
        if (input == 'a' && col > 0) col--;
        if (input == 'd' && col < size - 1) col++;

        // Заполнение поля
        if (input >= '1' && input <= '9') {
            int num = input - '0';
            *(*(field + row) + col) = num;
        }

        // Вывод поля после каждого ввода числа
        printField(field, status, size, row, col);
        fflush(stdout);

        // Проверка завершенности и корректности заполненного поля
        if (completeField(field, size)) {
            if (completeFieldCorrectly(field, size)) {
                printf("Sudoku solved correctly!\n");
            } else {
                printf("Incorrect solution :( \n");
            }
            break;  // Завершение игры 
        }

    }

    freeField(field, status, size); // Освобождение памяти
    return 0;
}

#endif
