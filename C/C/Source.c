#define _CRT_SECURE_NO_WORNING
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define arrSize 10	
#define stringSize 50	

int getStringLength(char str[stringSize]);
int does_create(char str[stringSize], char sub_str[stringSize]);
int shortest_str(char str[stringSize]);
int countBits(int n);
int myStrCut(char* s, char* s2);
int transfer(int* from, int* to, int amount);
void printAnAryyOfArrys(int a[][arrSize], int row, int culom);
void printArray(int* a, int size);
int srarch_larger(int* arr, int n, int k);
int* buildArray(int n);
int** buildArrayofPointer(int n);

/*
int main() {
    // pdf name of file exercise + q + number of question + () // pointers_2_8 + q + 5 + () // exemple ==> pointers_2_8q5();
}
*/

int main(){
    classExercise();
}

int classExercise() {
    printf_s("how much class?\n");
    int classnumber;
    scanf_s("%d", &classnumber);
    int **allClass = buildArrayofPointer(classnumber);
    int *classSizes = buildArray(classnumber);
    int* classAverage = buildArray(classnumber);
    
    for (int i = 0; i < classnumber; i++) {
        printf_s("what is the number of student in class number %d ?\n", i + 1);
        scanf_s("%d", &*(classSizes +i));
        *(allClass + i) = buildArray(*(classSizes + i));
    }
    for (int i = 0; i < classnumber; i++) {
        *(classAverage + i) = 0;
        for (int s = 0; s < (int)*(classSizes + i); s++) {
            printf_s("what is the grat of student num %d in class %d ?\n", s + 1, i + 1);
            scanf_s("%d", &*(*(allClass + i) + s));
            *(classAverage + i) += *(*(allClass + i) + s);
        }
    }
    for (int i = 0; i < classnumber; i++) {
        printf_s("the sum of class number %d is %d\n", i +  1, *(classAverage + i) / *(classSizes + i));
        printAnAryyOfArrys(*(allClass + i), 1, *(classSizes + 1 ));
    }
}


int** buildArrayofPointer(int n) {
    int** arr = (int**)malloc(n * sizeof(int*));
    if (!arr) {
        printf("ERROR! Not enough memory!\n");
        exit(1);
    }
    return arr;
}

/*
int main() {
    int n;
    printf("give me the array size");
    scanf_s("%d", &n);
    int arr = buildArray(n);
    //printf_s("%d", sizeof(arr) );
    //printf_s("%d", arr[0]);
    printAnAryyOfArrys(arr, 1, n );
}
*/

int* buildArray(int n) {
    int i;
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("ERROR! Not enough memory!\n");
        exit(1);
    }
    /*
    for (i = 0; i < n; i++) {
        *(arr + i) = i + 1;
    }
    */
    return arr;
}

int pointers_2_8q6() {
    int bank[] = { 5,65,4,34,3,72,48,23 };
    printf_s("%d", srarch_larger(bank, 8, 4));
}



int srarch_larger(int* arr, int n, int k) {
    int min = k;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) < k) { k = *(arr + i); }
    }
    if (min == k) {
        return -1;
    }
    return k;
}

int pointers_2_8q5() {
    ///////////////0--1-2--3--4--5--6--7
    int bank[] = { 5,65,1,34,67,72,48,23 };
    int size = sizeof(bank) / sizeof(bank[0]);
    printAnAryyOfArrys(bank, 1, size);
    printf_s("\nrimender %d\n", transfer(&bank[1], &bank[5], 10));
    printAnAryyOfArrys(bank, 1, size);
    printf_s("\nrimender %d\n", transfer(&bank[3], &bank[2], 40));
    printAnAryyOfArrys(bank, 1, size);
}



void printArray(int* a, int size) {
    printf_s("%d", size);
    for (int i = 0; i < size; i++) {
        printf_s("%d", *(a + i));
    }
}

void printAnAryyOfArrys(int a[][arrSize], int row, int culom) {
    printf_s("\n");
    for (int i = 0; i < culom; i++) {
        printf_s("______");
    }
    printf_s("\n");
    for (int i = 0; i < row; i++) {
        printf_s("|");
        for (int ii = 0; ii < culom; ii++) {
            printf_s(" %3d |", a[i][ii]);
        }
        printf_s("\n");
    }
    printf_s("|_____");
    for (int i = 1; i < culom; i++) {
        printf_s("______");
    }
    printf_s("|\n");
}

int transfer(int* from, int* to, int amount) {
    if (*from >= amount) {
        *from -= amount;
        *to += amount;
        return 0;
    }
    amount -= *from;
    *to += *from;
    *from = 0;
    return amount;
}

int unitingArray() {
    int a[] = { 0,1,2 }, b[] = { 1,2,3 }, c[3];
    int i = 0;
    int arrLength = sizeof(a) / sizeof(a[0]);
    while (i < arrLength)
    {
        *(c + i) = *(a + i) + *(b + i);
        printf_s("%d %d %d\n", *(c + i), *(a + i), *(b + i));
        i++;
    }
}

int countLongNUmber() {
    long a;
    scanf_s("%i", &a);
    printf_s("%i", a);
    int i = 0, sum = 0;
    while (a)
    {
        sum += a % 10;
        i++;
        a /= 10;
    }
    printf("\nthe number has %d digit and the sum is %d", i, sum);
}


int arrayExsam() {
    int a[5][3];
    printf("%d\n", sizeof(a[0][0]));
    printf("%d\n", sizeof(a[0]));
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(a[0]) / sizeof(a[0][0]));
    printf("%d\n", sizeof(a) / sizeof(a[0]));
    printf("%d\n", sizeof(a) / sizeof(a[0]) * sizeof(a[0]) / sizeof(a[0][0]));
}


int myStrCut(char* s, char* s2) {
    while (*s != '\0')
    {
        s++;
    }
    *s = ' ';
    while (*s2 != '\0')
    {
        s++;
        *s = *s2;
        s2++;
    }
    s++;
    *s = '\0';
}

int pointerExsam() {
    int max[arrSize][arrSize] = { 0 };
    printf_s("%d %p %d\n", *max[0], max[0], max[0][0]);
    printf_s("%d %p %d\n", *(max[0] + 1), max[0] + 1, max[0][0]);
    printf_s("%d %p %d\n", *(max + 1)[0], (max + 1) + 1, max[1][0]);
}

int getTooStringToghter() {
    /*
    char str[stringSize] = "mor", sub_str[] = "bargig";
    */
    char str[stringSize], sub_str[stringSize];
    printf_s("give me string\n");
    gets(str);
    printf_s("give me sub string\n");
    gets(sub_str);
    myStrCut(str, sub_str);
    printf_s("%s\n", str);
    puts(str);
}


unsigned int f(int a, int b)
/* : טענת כניסה a ' - ו b שלמים מס */
/* : טענת יציאה ???????????????? */
{
    int i, x = 0, y = sizeof(int) * 8;
    for (i = 0; i < y; i++)
        x += (a & (1 << i)) + (b & (1 << i));
    return x;
}

/*
char* index(char str[stringSize],char ch ) {
    for (int i = 0; i < stringSize; i++) {
        if (str[i] == ch) {
            return &str[i];
        }
    }
}
int main() {
    char str[stringSize];
    fgets(str, stringSize, stdin);
    printf_s("%p %d", index(str, 'l'), index(str, 'l' ) ;

}
*/

char* index(char* str, char ch) {
    while (*str)
    {
        if (*str == ch)
        {
            return str;
        }
        str++;
    }
    return NULL;
}

int findChar()
{
    char str[] = "This is a sample string";
    printf("Looking for the 's' character in \"%s\"...\n", str);
    printf("%d", index(str, 'l') - &str + 1);
    return 0;
}

int q5() {
    for (int i = 0; i < 10; i++) {
        i <<= 1;
        printf("%d\n", i);
    }
}

/*
int main()
{
    int i, a = 12, b = 0;
    for (i = 0; i < sizeof(int) * 8; i++, a >>= 1, b <<= 1)
        if (a & 1) b ^= 1;
    printf("%d\n", b);
}
*/

int countBits(int n) {
    int count = 0;
    while (n != 0) {
        // printf_s("%d\n", n);
        count++;
        n &= n - 1;
    }
    printf_s("%d", count);
}



int q12p7() {
    char str[stringSize], sub_str[stringSize];
    printf_s("give me string\n");
    //str[0] = 'f';
    fgets(str, stringSize, stdin);
    printf_s("give me a sub string\n");
    fgets(sub_str, stringSize, stdin);
    does_create(str, sub_str) ? printf_s("the secound string appired in the first string\n") : printf_s("the secound strin doest apered in the first string\n");
    printf_s("the string in bilud from srial of %d chars \n", shortest_str(str));
    //printf_s("%d", getStringLength(str));
}


int getStringLength(char str[stringSize]) {
    int index = 0;
    for (int i = 0; i < stringSize; i++) {
        // printf_s("%d", (int)str[i]);
        if ((int)str[i] == 0) { // -52 zebel
            index = i - 1;
            break;
        }
        if ((int)str[i] == -52) { // -52 zebel
            index = i;
            break;
        }
    }
    return index;
}

int does_create(char str[stringSize], char sub_str[stringSize]) {
    int n = getStringLength(str), n1 = getStringLength(sub_str);
    // printf_s("%d %d\n", n,n1);
    if (n % n1 != 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (str[i] != sub_str[i % n1]) {
            return 0;
        }
    }
    return 1;
}


int shortest_str(char str[stringSize]) {
    int n = getStringLength(str);
    char sub_str[stringSize];
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        sub_str[i] = str[i];
        if (does_create(str, sub_str) == 1) {
            count = getStringLength(sub_str);
        }
    }
    return count;
}

/*
int main()
{
    int x, y, z;
    x = 0x3; y = 0x2; z = 0x1;
    // x = 3; y = 2; z = 1;
    printf("%d\n", x | y & z);
    printf("%d\n", x | y & ~z);
    printf("%d\n", x ^ y & ~z);
    printf("%d\n", x & y && z);
    x = 1; y = -1;
    printf("%d\n", !x | x);
    printf("%d\n", ~x | x);
    printf("%d\n", x ^ x);
    x <<= 3; printf("%d\n", x);
    y <<= 3; printf("%d\n", y);
    y >>= 3; printf("%d\n", y);
    return 0;
}
*/