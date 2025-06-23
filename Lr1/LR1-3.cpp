#include <iostream>
using namespace std;

void obmen(int, int);
void obmen2(int*, int*);
void obmen3(int&, int&);

int main() {
    setlocale(LC_ALL, "Russian");
    int a = 2, b = 5;

    wcout << L"Перед обменом: a = " << a << ", b = " << b << endl;

    obmen(a, b);
    wcout << L"После обмена 1: a = " << a << ", b = " << b << endl;

    obmen2(&a, &b);
    wcout << L"После обмена 2: a = " << a << ", b = " << b << endl;

    obmen3(a, b);
    wcout << L"После обмена 3: a = " << a << ", b = " << b << endl;

    return 0;
}
/**
 * Передача по значению - изменений не будет
 * @param x
 * @param y
 */
void obmen(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

/**
 * Передача указателей
 * @param x
 * @param y
 */
void obmen2(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Передача по ссылке
 * @param x
 * @param y
 */
void obmen3(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}