#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ofstream outFile("test_writing.txt");  // Открываем файл для записи
    if (!outFile) {
        wcout << L"Ошибка при создании файла" << endl;
        return 1;
    }

    outFile << "Hello, file!" << endl;
    outFile.close();

    ifstream inFile("test.txt");  // Читаем файл
    if (!inFile) {
        wcout << L"Ошибка при чтении файла" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    return 0;
}
