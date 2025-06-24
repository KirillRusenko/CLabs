#include <iostream>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

class FileProcessor {
private:
    string key;
    size_t keyIndex;

public:
    explicit FileProcessor(string encryptionKey) : key(std::move(encryptionKey)), keyIndex(0) {
    }

    void process(const string &inputFile, const string &outputFile) {
        ifstream in(inputFile, ios::binary);
        ofstream out(outputFile, ios::binary);

        if (!in || !out) {
            cerr << "Ошибка при открытии файла!" << endl;
            return;
        }

        char c;
        keyIndex = 0; // Reset keyIndex before processing
        while (in.get(c)) {
            c = c ^ key[keyIndex];
            out.put(c);
            keyIndex = (keyIndex + 1) % key.length();
        }

        in.close();
        out.close();
    }
};

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

    FileProcessor processor(key);

    outputFile = "encrypted_test.txt";
    processor.process(inputFile, outputFile);

    // Шифруем зашифрованный файл еще раз
    processor.process(outputFile, "encrypted_double.txt");

    return 0;
}
