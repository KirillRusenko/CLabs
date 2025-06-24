#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void processFile(const string &inputFile, const string &outputFile, const string &key) {
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    if (!in || !out) {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }

    char c;
    size_t keyIndex = 0;
    while (in.get(c)) {
        c = c ^ key[keyIndex];
        out.put(c);
        keyIndex = (keyIndex + 1) % key.length();
    }

    in.close();
    out.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    string inputFile, outputFile, key;

    wcout << L"Введите имя входного файла: ";
    getline(cin, inputFile);
    if (inputFile.empty()) {
        inputFile = "test.txt";
    }

    wcout << L"Введите ключ шифрования: ";
    getline(cin, key);
    if (key.empty()) {
        key = "defaultkey";
    }

    outputFile = "encrypted_test.txt";
    processFile(inputFile, outputFile, key);

    // Шифруем зашифрованный файл еще раз
    processFile(outputFile, "encrypted_double.txt", key);

    return 0;
}