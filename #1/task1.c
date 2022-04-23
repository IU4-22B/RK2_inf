/*
Вариант 1.
Задача 1. 
-------------------------------------------------------------------------
Считать числа из консоли. Первое из них: N. 
При вводе числа разделены пробелом или символом перехода на новую строку.  
Пользователь может ввести произвольное количество чисел. 
Необходимо найти и вывести N самых больших в порядке их ввода.
-------------------
Sample Input 1:
    3 
    4 1 6 39 9 2 7
Sample Output 1:
    39 9 7
-------------------
Sample Input 2:
    2
    -2 1 -10
Sample Output 2:
-2 1
-------------------
Sample Input 3:
    6
    22 13 29 27
Sample Output 3:
    22 13 29 27
-------------------
Sample Input 4:
    0
    1 2 3
Sample Output 4:

-------------------
*/

#include <stdio.h>
#include <stdlib.h>

int *get_int_array(size_t *len) {
    size_t cur_len = 0;
    size_t max_len = 1;
    int *array;
    int *old_array;
    int x;
    
    array = (int *) malloc(max_len * sizeof(int));
    if (array == NULL)
        return NULL;
    
    while (scanf("%d", &x) != EOF) {
        array[cur_len++] = x;
        
        if (cur_len >= max_len) {
            max_len *= 2;
            old_array = array;
            
            array = (int *) realloc(array, max_len * sizeof(int));
            if (array == NULL) {
                free(old_array);
                return NULL;
            }
        }
    }
    
    *len = cur_len;
    old_array = array;
    
    array = (int *) realloc(array, cur_len * sizeof(int));
    if (array == NULL)
        return old_array;
    
    return array;
}

int main(void) {
    size_t N = 0;
    size_t count_of_larger_numbers = 0;
    size_t len = 0;
    int *array;
    
    scanf("%ld", &N);
    
    array = get_int_array(&len);
    if (N == 0)
        return 0;
    
    if (array == NULL) {
        printf("Reading numbers error.\n");
        return 1;
    }
    
    for (size_t i = 0; i < len; ++i) {
        int current_number = array[i];
        
        count_of_larger_numbers = 0;
        
        for (size_t j = 0; j < len; ++j)
            if (array[j] > current_number)
                ++count_of_larger_numbers;
        
        if (count_of_larger_numbers < N)
            printf("%d ", current_number);
        
    }
    
    free(array);
    
    return 0;
}
