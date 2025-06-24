#include "Stroka.cpp"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Stroka s1("qwerty"), s3, s4(s1), s5;
    wcout << L"Пожалуйста, введите строку для s3: ";
    s3.vvod();
    wcout << L"Вы ввели строку: ";
    s3.vyvod();
    s3 = "asdfg";
    wcout << L"После присваивания строки: ";
    s3.vyvod();
    s5 = s1 + s3 + s4;
    wcout << L"Результат конкатенации строк: ";
    s5.vyvod();
    wcout << L"Длина строки s5 = " << s5.dlina() << endl;
    if (s1 == s5) {
        wcout << L"Строки s1 и s5 идентичны" << endl;
    } else {
        wcout << L"Строки s1 и s5 разные" << endl;
    }
    if (s1 == s4) {
        wcout << L"Строки s1 и s4 идентичны" << endl;
    }

    return 0;
}