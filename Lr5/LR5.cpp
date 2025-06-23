#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// 1. Вывод содержимого файла на экран (упрощенная версия)
void displayFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    cout << "Содержимое файла " << filename << ":\n";
    string line;
    while (getline(in, line)) {
        cout << line << '\n';
    }
    in.close();
}

// 2. Подсчет служебных символов
int countControlChars(const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return -1;
    }

    int count = 0;
    char ch;
    while (in.get(ch)) {
        if (iscntrl(ch) && ch != '\n' && ch != '\r') {
            count++;
        }
    }
    in.close();
    return count;
}

// 3. Поиск подстроки в файле
void findSubstring(const string& filename, const string& substring, const string& outputFile) {
    ifstream in(filename);
    ofstream out(outputFile);

    if (!in || !out) {
        cerr << "Ошибка открытия файлов\n";
        return;
    }

    string line;
    int lineNum = 1;
    bool found = false;

    out << "Результаты поиска подстроки \"" << substring << "\" в файле " << filename << ":\n";

    while (getline(in, line)) {
        size_t pos = line.find(substring);
        if (pos != string::npos) {
            out << "Строка " << lineNum << ", позиция " << pos << ": " << line << '\n';
            found = true;
        }
        lineNum++;
    }

    if (!found) {
        out << "Подстрока не найдена.\n";
    }

    in.close();
    out.close();
}

// 4. Перенос номеров страниц
void processPageNumbers(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);

    if (!in || !out) {
        cerr << "Ошибка открытия файлов\n";
        return;
    }

    string pageNumber;
    vector<string> pageLines;
    string line;
    bool firstLine = true;

    while (getline(in, line)) {
        if (line.find('\f') != string::npos) {
            // Нашли символ перевода страницы
            if (!pageNumber.empty()) {
                // Записываем все строки страницы, кроме первой
                for (size_t i = 1; i < pageLines.size(); i++) {
                    out << pageLines[i] << '\n';
                }
                // Записываем номер страницы в конце
                out << pageNumber << '\n';
            }
            pageLines.clear();
            pageNumber.clear();
            firstLine = true;
        }
        else if (firstLine) {
            // Извлекаем номер страницы из первой строки
            for (char c : line) {
                if (isdigit(c)) {
                    pageNumber += c;
                }
            }
            firstLine = false;
        }
        else {
            pageLines.push_back(line);
        }
    }

    // Обработка последней страницы
    if (!pageNumber.empty()) {
        for (size_t i = 1; i < pageLines.size(); i++) {
            out << pageLines[i] << '\n';
        }
        out << pageNumber << '\n';
    }

    in.close();
    out.close();
}

// 5. Шифрование/дешифрование файла
void encryptFile(const string& inputFile, const string& outputFile, const string& key) {
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    if (!in || !out) {
        cerr << "Ошибка открытия файлов\n";
        return;
    }

    char ch;
    size_t keyIndex = 0;
    while (in.get(ch)) {
        ch ^= key[keyIndex++ % key.size()];
        out.put(ch);
    }

    in.close();
    out.close();
}

// 6. Обработка аргументов командной строки
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "russian");
    // Проверка аргументов командной строки
    if (argc > 1) {
        if (argc == 4 && string(argv[1]) == "-encrypt") {
            // Шифрование файла: программа -encrypt input.txt output.txt key
            encryptFile(argv[2], argv[3], argv[4]);
            cout << "Файл зашифрован.\n";
            return 0;
        }
        else if (argc == 2) {
            // Просто вывод содержимого файла
            displayFile(argv[1]);
            return 0;
        }
    }

    // Интерактивный режим
    cout << "Лабораторная работа 5 - Работа с файлами\n";
    cout << "1. Вывод содержимого файла\n";
    cout << "2. Подсчет служебных символов\n";
    cout << "3. Поиск подстроки в файле\n";
    cout << "4. Перенос номеров страниц\n";
    cout << "5. Шифрование файла\n";
    cout << "Выберите действие (1-5): ";

    int choice;
    cin >> choice;
    cin.ignore(); // Очистка буфера

    string inputFile, outputFile, substring, key;

    switch (choice) {
        case 1:
            cout << "Введите имя файла: ";
            getline(cin, inputFile);
            displayFile(inputFile);
            break;

        case 2:
            cout << "Введите имя файла: ";
            getline(cin, inputFile);
            cout << "Количество служебных символов: " << countControlChars(inputFile) << endl;
            break;

        case 3:
            cout << "Введите имя входного файла: ";
            getline(cin, inputFile);
            cout << "Введите подстроку для поиска: ";
            getline(cin, substring);
            cout << "Введите имя выходного файла: ";
            getline(cin, outputFile);
            findSubstring(inputFile, substring, outputFile);
            break;

        case 4:
            cout << "Введите имя входного файла: ";
            getline(cin, inputFile);
            cout << "Введите имя выходного файла: ";
            getline(cin, outputFile);
            processPageNumbers(inputFile, outputFile);
            break;

        case 5:
            cout << "Введите имя входного файла: ";
            getline(cin, inputFile);
            cout << "Введите имя выходного файла: ";
            getline(cin, outputFile);
            cout << "Введите ключ шифрования: ";
            getline(cin, key);
            encryptFile(inputFile, outputFile, key);
            cout << "Файл зашифрован. Для проверки запустите программу с теми же параметрами еще раз.\n";
            break;

        default:
            cout << "Неверный выбор.\n";
    }

    return 0;
}