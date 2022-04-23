/*
Вариант 6.
Задача 1. 
-------------------------------------------------------------------------
Вывести нечетные числа в порядке возрастания из массива длиной N.
Пользователь вводит числа в консоль. 
При вводе числа разделены пробелом или символом перехода на новую строку. 
Пользователь может ввести произвольное количество чисел.
Если введено больше чем N символов, то считать необходимо лишь первые N символов.
-------------------
Sample Input 1:
    7
    4 1 6 39 9 2 7
Sample Output 1:
    1 7 9 39
-------------------
Sample Input 2:
    10
    35 70 23 17 93 80 42 23 20 90 42 40 92 18 95
Sample Output 2:
    17 23 23 35 93
-------------------
Sample Input 3:
    50
    20 49 57 99 24 7 72 60 82 91 68 18 49 75 12 57 66 28 48 5
Sample Output 3:
    5 7 49 49 57 57 75 91 99
-------------------
Sample Input 4:
    0
    1 2 3
Sample Output 4:

-------------------
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *Array, int index1, int index2) {
    int tmp = Array[index1];
    Array[index1] = Array[index2];
    Array[index2] = tmp;
}

int partition(int *Array, int left, int right) {
    int pivot = Array[right];
    int i = left - 1;
    i = left - 1;
    for (int j = left; j != right; ++j)
        if (Array[j] <= pivot)
            swap(Array, ++i, j);
    swap(Array, i + 1, right);
    return i + 1;
}

void quick_sort(int *Array, int left, int right) {
    if (left < right) {
        int mid = partition(Array, left, right);
        quick_sort(Array, left, mid - 1);
        quick_sort(Array, mid + 1, right);
    }
}

int main(void) {
    size_t count = 0;
    size_t N;
    size_t cnt = 0;
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

    /* Считывание чисел и добавление нечётных в массив */
    while (scanf("%d", &x) != EOF && cnt < N) {
        ++cnt;
        if (x % 2 == 1)
            numbers[count++] = x;
    }

    quick_sort(numbers, 0, count-1);
    
    /* Распечатка встретившихся нечётных чисел */
    for (size_t i = 0; i < count; ++i)
        printf("%d ", numbers[i]);
    printf("\n");

    free(numbers);

    return 0;
}
