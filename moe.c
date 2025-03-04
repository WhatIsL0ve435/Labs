#include <stdio.h>

int main(){
    double x, exp, sum, element, factorial, denominator, numerator, f;
    int sign, input_valid;
    do {
        printf("Enter exp: ");
        input_valid = scanf("%lf", &exp);
        if (input_valid != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            // Очистка буфера ввода
            while (getchar() != '\n'); // Убираем некорректные символы из буфера
        } else if (exp == 0) {
            printf("exp cannot be zero. Please enter a non-zero value.\n");
            input_valid = 0; // Повторяем ввод
        }
    } while (input_valid != 1 || exp == 0);

    // Ввод значения x с проверкой на корректность
    do {
        printf("Enter x: ");
        input_valid = scanf("%lf", &x);
        if (input_valid != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            // Очистка буфера ввода
            while (getchar() != '\n'); // Убираем некорректные символы из буфера
        }
    } while (input_valid != 1);
    element = 0; // Данный элемент
    numerator = x * x; // числитель
    denominator = 2; // знаменатель
    factorial = 2; // факториал
    sum = 1; // сумма
    sign = -1; // знак элемента

    do{
        element = numerator / denominator;
        sum += element * sign;
        numerator = numerator * x * x;
        denominator = 1;
        factorial += 2;
        sign = -sign;
        f = factorial;
        while (f > 0)
        {
            denominator = denominator*f;
            f = f - 1;
        }
    } while (element * element > exp * exp); 
    printf("summa = %lf\n", sum);
    return 0;
}

