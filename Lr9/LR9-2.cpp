#include <iostream>
using namespace std;

// Функция для нахождения большего из двух параметров
template <class T>
T getmax(T t1, T t2) {
    return (t1 > t2) ? t1 : t2;
}

// Функция для нахождения максимума в массиве
template <class T>
T getmax(T t[], size_t size) {
    T retval = t[0];
    for (size_t i = 1; i < size; ++i) {
        if (t[i] > retval) {
            retval = t[i];
        }
    }
    return retval;
}

int main() {
    int i1 = 3, i2 = 5;
    int mas[] = {3, 9, 5, 8};
    cout << "max int = " << getmax(i1, i2) << endl;
    cout << "max in array = " << getmax(mas, std::size(mas)) << endl;
}