#include <iostream>
using namespace std;

int power(int, int);

int main() {
    setlocale(LC_ALL, "Russian");
    int base, exponent;

    wcout << L"Введите основание: ";
    cin >> base;

    wcout << L"Введите степень, она должна быть целым неотрицательным числом: ";
    cin >> exponent;

    // Вычисляем степень и выводим результат
    wcout << base << "^" << exponent << " = " << power(base, exponent) << endl;

    return 0;
}

int power(int x, int n) {
    int p = 1;
    for (int i = 0; i < n; i++)
        p *= x;
    return p;
}
