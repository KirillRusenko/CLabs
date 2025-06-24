#include <iostream>
#include <cstring>
using namespace std;

// Шаблон для нахождения большего из двух элементов
template<class T>
T getmax(T t1, T t2) {
    return (t1 > t2) ? t1 : t2;
}

// Специализация шаблона для строк
const wchar_t *getmax(const wchar_t *s1, const wchar_t *s2) {
    return (wcscmp(s1, s2) > 0) ? s1 : s2;
}

template<class T>
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
    setlocale(LC_ALL, "Russian");
    int i1 = 3, i2 = 5;
    const wchar_t *s1 = L"строка1";
    const wchar_t *s2 = L"строка2";

    cout << "max int = " << getmax(i1, i2) << endl;
    wcout << L"max str = " << getmax(s1, s2) << endl;

    return 0;
}
