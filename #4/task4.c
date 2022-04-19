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




int search_max(int ASCII[256]) {
    int max = 0;
    int cell = 0;
    for (int i = 1; i < 256; i++) {
        if (max < ASCII[i]) {
            max = ASCII[i];
            cell = i;
        }
    }
    ASCII[cell] = 0;
    return cell;
}

int main() {
    int counter = 0;
    int symbol;

    /*char* pString = (char*)malloc(counter * sizeof(char));
    (if (pString == NULL) {
        printf("Error memory allocate");
        return 1;
    }*/

    /*while (symbol = getchar() != EOF) {
        pString = (char*)realloc(pString, (counter+1) * sizeof(char));
        /*if (pString == NULL) {
            printf("Error memory allocate");
            return 1;
        }*/
        /**(pString + counter) = symbol;
        counter++;
    }

    for (int i = 0; i < counter; i++) printf("%c ", *pString+i));*/
    char array[100] = "aaa bBb cccc ddd eee fff";
    int N = 4;
    int ASCII[256] = { 0 };
    for (int i = 0; i < sizeof(array); i++) ASCII[tolower(array[i])]++;
    ASCII[' '] = 0;
    for (int i = 1; i < 256; i++) if (ASCII[i] > 0) printf("%c: %d\n\r", i, ASCII[i]);

    int inter_array[256] = {0};
    for (int i = 0; i < N; i++) {
        inter_array[i] = search_max(ASCII);
    }
    
    for (int i = 0; i < N; i++) printf("%c ", inter_array[i]);

    return 0;
}
