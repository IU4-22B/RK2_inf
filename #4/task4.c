/*
Вариант 4.
Задача 1.
-------------------------------------------------------------------------
Вывести N символов, которые чаще всего встречаются в тексте.
Пользователь вводит число N и далее вводит в консоли текст из букв латинского алфавита. 
Регистр букв игнорируется.
Если буквы встречались одинаковое количество раз, выводится та, которая идёт раньше в алфавите.
-------------------
Sample Input 1:
    4
    aaa bBb cccc ddd eee fff
Sample Output 1:
    a b c d
-------------------
Sample Input 2:
    3
    abcdef
Sample Output 2:
    a b c
-------------------
Sample Input 3:
    0
    qwertyqwertrewqqwewqq
Sample Output 3:

-------------------
Sample Input 4:
    12
    aa fb r
Sample Output 4:
    a b f r
-------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define COUNT_OF_SYMBOLS_IN_ENG_ALPHABET 26

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
    size_t N;
    size_t unique_symbols_count = 0;
    size_t *symbols_counter;
    size_t count_of_larger_numbers;
    int *most_frequency_symbols;
    int c;
    int a;
    
    scanf("%ld", &N);
    /* 
       Нужно вывести 0 чисел <=> ничего не нужно выводить. 
       Программу можно завершать 
    */
    if (N == 0)
        return 0;
    
    symbols_counter = (size_t *) calloc(COUNT_OF_SYMBOLS_IN_ENG_ALPHABET, sizeof(size_t));
    if (symbols_counter == NULL) {
        printf("Allocation error!\n");
        return 1;
    }
     
    /* Подсчёт частоты, с которой встречается тот или иной символ */
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            continue;
        
        a = (isupper(c) ? 'A' : 'a');
        ++symbols_counter[c - a];
    }
    
    /* Массив для чисел, которые встречаются чаще всего */
    most_frequency_symbols = (int *) malloc(N * sizeof(int));
    if (most_frequency_symbols == NULL) {
        printf("Allocation error!\n");
        return 1;
    }
    
    /* Подсчёт уникальных символов, встретившихся среди введённых */
    for (size_t i = 0; i < COUNT_OF_SYMBOLS_IN_ENG_ALPHABET; ++i)
        if (symbols_counter[i])
            ++unique_symbols_count;
    
    /* 
       Если уникальных символов МЕНЬШЕ, чем количество символов, 
       которые нужно вывести, то нужно вывести все уникальные символы.
       После вывода завершаем программу
    */
    if (unique_symbols_count <= N) {
        for (size_t i = 0; i < COUNT_OF_SYMBOLS_IN_ENG_ALPHABET; ++i)
            if (symbols_counter[i])
                printf("%c%s", 'a' + i, (i < COUNT_OF_SYMBOLS_IN_ENG_ALPHABET - 1) ? " " : "\n");
        
        return 0;
    }
    
    /*
       Если уникальных символов БОЛЬШЕ, чем количество симвлолов,
       которые нужно вывести, то нужно подсчитать самые частые и
       добавить их в массив
    */
    for (size_t i = 0; i < N; ++i) {
        size_t index = 0;
        size_t max_count = symbols_counter[0];
        
        for (size_t j = 1; j < COUNT_OF_SYMBOLS_IN_ENG_ALPHABET; ++j) {
            if (symbols_counter[j] > max_count) {
                max_count = symbols_counter[j];
                index = j;
            }
        }
        
        most_frequency_symbols[i] = 'a' + index;
        symbols_counter[index] = 0;
        
    }
    
    /* 
       Сортируем массив, чтобы вывести самые частовстречающиемся
       в алфавитном порядке
    */
    quick_sort(most_frequency_symbols, 0, N-1);
    
    for (size_t i = 0; i < N; ++i)
        printf("%c%s", most_frequency_symbols[i], (i < N - 1) ? " " : "\n");
    
    free(most_frequency_symbols);
    free(symbols_counter);
    
    return 0;
}
