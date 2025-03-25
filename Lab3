#include <stdio.h>

// Определение символических констант
#define YES  1 
#define NO   0 

int main(void) 
{ 
    int c;          // Текущий символ из потока
    int flag;        // Признак слова (YES/NO)
    int cnt = 0;     // Счётчик слов с одинаковыми первыми двумя буквами
    int pos = 0;     // Позиция в слове (0, 1, 2...)
    int first = 0;  // Первая буква слова
    int second = 0; // Вторая буква слова

    flag = NO;

    while ((c = getchar()) != EOF) 
    { 
        if (c == ' ' || c == '.' || c == '\n' || c == ',' || c == '\t') 
        { 
            // Найден разделитель
            if (flag == YES) 
            { 
                // Если слово содержит хотя бы 2 буквы и первые две совпадают
                if (pos >= 2 && first == second) 
                { 
                    cnt++; 
                } 
            } 
            flag = NO; 
            pos = 0; // Сбрасываем позицию для нового слова
        } 
        else 
        { 
            // Найдена буква
            if (flag == NO) 
            { 
                // Начало нового слова
                flag = YES; 
                first = c; 
                pos = 1; 
            } 
            else 
            { 
                pos++; 
                if (pos == 2) 
                { 
                    second = c; 
                } 
            } 
        } 
    } 

    // Проверка последнего слова, если ввод завершился без разделителя
    if (flag == YES && pos >= 2 && first == second) 
    { 
        cnt++; 
    } 

    printf("Count word: %d\n", cnt); 
    return 0;
}
