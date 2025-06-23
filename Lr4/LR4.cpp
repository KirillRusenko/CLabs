#include <iostream>
#include <cstdlib> // для malloc/calloc/free

using namespace std;


// Собственные реализации функций

// Три способа вычисления длины строки
int myStrLen1(const char* str) {
    int len = 0;
    while (*str++) len++;
    return len;
}

int myStrLen2(const char* str) {
    const char* p = str;
    while (*p) p++;
    return p - str;
}

int myStrLen3(const char* str) {
    int len = 0;
    for (; str[len]; len++);
    return len;
}

// Копирование строки
void myStrCpy(char* dest, const char* src) {
    while ((*dest++ = *src++));
}

// Сравнение строк
int myStrCmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

// Конкатенация строк
void myStrCat(char* dest, const char* src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}

// 3. Функции с динамической памятью (malloc)
void dynamicMemory() {
    wcout << L"\n3. Работа с динамической памятью (malloc):\n";

    char* str1 = (char*)malloc(100);
    char* str2 = (char*)malloc(100);

    myStrCpy(str1, "Dynamic");
    myStrCpy(str2, "Memory");

    wcout << L"str1: " << str1 << endl;
    wcout << L"str2: " << str2 << endl;

    myStrCat(str1, " ");
    myStrCat(str1, str2);
    wcout << L"После конкатенации: " << str1 << endl;

    free(str1);
    free(str2);
}

// 4. Функции с динамической памятью (calloc)
void callocMemory() {
    wcout << L"\n4. Работа с динамической памятью (calloc):\n";

    char* str1 = (char*)calloc(100, sizeof(char));
    char* str2 = (char*)calloc(100, sizeof(char));

    myStrCpy(str1, "Calloc");
    myStrCpy(str2, "Example");

    wcout << L"str1: " << str1 << endl;
    wcout << L"str2: " << str2 << endl;

    myStrCat(str1, " ");
    myStrCat(str1, str2);
    wcout << L"После конкатенации: " << str1 << endl;

    free(str1);
    free(str2);
}

// 5. Работа с массивом строк
void stringArray() {
    wcout << L"\n5. Работа с массивом строк:\n";

    const int COUNT = 3;
    char** strings = (char**)malloc(COUNT * sizeof(char*));

    // Инициализация строк
    strings[0] = (char*)malloc(20);
    strings[1] = (char*)malloc(20);
    strings[2] = (char*)malloc(20);

    myStrCpy(strings[0], "First");
    myStrCpy(strings[1], "Second");
    myStrCpy(strings[2], "Third");

    // Применение наших функций к массиву строк
    for (int i = 0; i < COUNT; i++) {
        wcout << L"Строка " << i << ": " << strings[i]
             << L", длина: " << myStrLen1(strings[i]) << endl;
    }

    // Конкатенация первой и второй строк
    myStrCat(strings[0], " ");
    myStrCat(strings[0], strings[1]);
    wcout << L"После конкатенации: " << strings[0] << endl;

    // Освобождение памяти
    for (int i = 0; i < COUNT; i++) {
        free(strings[i]);
    }
    free(strings);
}

int main() {
    setlocale(LC_ALL, "Russian");

    char a[] = "qwerty";
    char b[] = "1234567890";

    wcout << L"Длина a (способ 1): " << myStrLen1(a) << endl;
    wcout << L"Длина a (способ 2): " << myStrLen2(a) << endl;
    wcout << L"Длина a (способ 3): " << myStrLen3(a) << endl;

    wcout << L"До копирования: a = " << a << ", b = " << b << endl;
    myStrCpy(a, b);
    wcout << L"После копирования: a = " << a << ", b = " << b << endl;

    wcout << L"Сравнение строк: " << myStrCmp(a, b) << endl;

    char c[50] = "Hello";
    char d[] = " World!";
    myStrCat(c, d);
    wcout << L"После конкатенации: " << c << endl;

    // 3. Работа с динамической памятью (malloc)
    dynamicMemory();

    // 4. Работа с динамической памятью (calloc)
    callocMemory();

    // 5. Работа с массивом строк
    stringArray();
}