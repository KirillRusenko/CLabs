#include <iostream>
using namespace std;

class Money {
private:
    long dollars;
    int cents;

public:
    Money() : dollars(0), cents(0) {}
    Money(long d, int c) : dollars(d), cents(c) {}

    bool operator>(const Money& amt) const {
        return (dollars > amt.dollars) ||
               ((dollars == amt.dollars) && (cents > amt.cents));
    }

    friend ostream& operator<<(ostream& os, const Money& amt) {
        os << "$" << amt.dollars << "." << amt.cents;
        return os;
    }
};

// Шаблон для сортировки массива
template <typename T>
void Sort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    Money mad[] = {
        Money(19, 10),
        Money(99, 99),
        Money(99, 95),
        Money(19, 95)
    };
    int size = sizeof(mad) / sizeof(mad[0]);

    Sort(mad, size);

    for (int i = 0; i < size; ++i) {
        cout << "Money[" << i << "] = " << mad[i] << endl;
    }

    return 0;
}
