#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Stroka {
private:
    string text;

public:
    Stroka(const string &t = "") : text(t) {}

    friend ostream &operator<<(ostream &os, const Stroka &s) {
        os << s.text;
        return os;
    }

    friend istream &operator>>(istream &is, Stroka &s) {
        is >> s.text;
        return is;
    }

    void setText(const string &t) {
        text = t;
    }

    string getText() const {
        return text;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Stroka s;
    wcout << L"Введите текст: ";
    cin >> s;
    wcout << L"Вы ввели: ";
    cout << s << endl;
    return 0;
}
