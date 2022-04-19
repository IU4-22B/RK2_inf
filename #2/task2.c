/*
Вариант 2.
Задача 1. 
-------------------------------------------------------------------------
Найти и вывести N четных чисел.
Пользователь вводит числа в консоль. 
При вводе числа разделены пробелом или символом перехода на новую строку.  
Пользователь может ввести произвольное количество чисел. 
Первое введенное пользователем число — N.
-------------------
Sample Input 1:
    3
    4 1 -6 
    39 
    9 2 7 
Sample Output 1:
    4 -6 2
-------------------
Sample Input 2:
    0
    1 2 3
Sample Output 2:

-------------------
Sample Input 3:
    50
    22 45 18 59 38 94 73 97 88 91 -10 82 85 89 45 42 39 15 81 34
Sample Output 3:
    22 18 38 94 88 -10 82 42 34
-------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t count = 0;
    size_t N;
    int x;
    int *numbers;

    scanf("%ld", &N);
    if (N == 0)
        return 0;

    numbers = (int *) malloc(N * sizeof(int));
    if (numbers == NULL) {
        printf("Allocation error!\n");
        return 1;
    }

    /* Считывание чисел и добавление чётных в массив */
    while (scanf("%d", &x) != EOF && count < N)
        if (x % 2 == 0)
            numbers[count++] = x;

    /* Распечатка встретившихся чётных чисел */
    for (int i = 0; i < count; ++i)
        printf("%d ", numbers[i]);
    printf("\n");

    free(numbers);

    return 0;
}
