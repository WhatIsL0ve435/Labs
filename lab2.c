#include <stdio.h>

int main() {
    float x, exp;
    int input_valid;

    // Ввод значения exp с проверкой на корректность
    do {
        printf("Enter exp: ");
        input_valid = scanf("%f", &exp);
        if (input_valid != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            // Очистка буфера ввода
            while (getchar() != '\n'); // Убираем некорректные символы из буфера
        }
    } while (input_valid != 1);

    // Ввод значения x с проверкой на корректность и на ноль
    do {
        printf("Enter x: ");
        input_valid = scanf("%f", &x);
        if (input_valid != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            // Очистка буфера ввода
            while (getchar() != '\n'); // Убираем некорректные символы из буфера
        } else if (x == 0) {
            printf("x cannot be zero. Please enter a non-zero value.\n");
            input_valid = 0; // Повторяем ввод
        }
    } while (input_valid != 1 || x == 0);

    // Вычисление суммы ряда
    float sum = 1.0;  // Первый элемент ряда
    float term = 1.0; // Текущий элемент ряда
    int n = 1;         // Счетчик для факториала и степени
    int sign = -1;     // Знак текущего элемента

    while (1) {
        // Вычисляем степень x^(2n)
        float x_power = 1.0;
        for (int i = 1; i <= 2 * n; i++) {
            x_power *= x;
        }

        // Вычисляем факториал (2n)!
        float factorial = 1.0;
        for (int i = 1; i <= 2 * n; i++) {
            factorial *= (float)i; //   Преобразование int в float
        }

        // Вычисляем текущий элемент ряда
        term = (float)sign * x_power / factorial; // Преобразование sign в float

        // Если модуль текущего элемента меньше exp, завершаем цикл
        if (term < 0) term = -term; // Модуль
        if (term < exp) break;

        // Добавляем текущий элемент к сумме
        sum += term;

        // Меняем знак для следующего элемента
        sign *= -1;

        // Увеличиваем счетчик
        n++;
    }

    // Вывод результата
    printf("Sum of the series: %.6f\n", sum);

    return 0;
}