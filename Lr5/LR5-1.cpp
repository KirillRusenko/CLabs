#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

#define MAX_STRING_SIZE 1024

using namespace std;

void createTestFile() {
    wchar_t path[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, path);
    wstring filePath = wstring(path) + L"\\test.txt";

    wofstream file(filePath.c_str());
    if (!file.is_open()) {
        wcerr << L"Ошибка создания тестового файла!" << endl;
        return;
    }

    file << L"This is a test file for Laboratory Work #5.\n"
         << L"It contains several lines of text.\n"
         << L"\tLine with tabulation and spaces   \n"
         << L"Last line without line break";
    file.close();
    wcout << L"Создан тестовый файл: " << filePath << endl;
}

void displayFile(wchar_t *filename) {
    wifstream file(filename);
    if (!file.is_open()) {
        wcerr << L"Ошибка: не удалось открыть файл " << filename << endl;
        return;
    }

    wcout << L"\nСодержимое файла '" << filename << L"':\n";
    wcout << L"----------------------------------------\n";

    wchar_t line[MAX_STRING_SIZE];
    int lineNum = 1;
    while (file.getline(line, MAX_STRING_SIZE)) {
        wcout << lineNum++ << L": " << line << endl;
    }

    wcout << L"----------------------------------------\n";
    file.close();
}

void countSymbols(wchar_t *filename) {
    FILE *file;
    _wfopen_s(&file, filename, L"r, ccs=UTF-8");
    if (!file) {
        wcerr << L"Ошибка открытия файла " << filename << endl;
        return;
    }

    int empty = 0, visible = 0;
    wchar_t ch;

    while ((ch = fgetwc(file)) != WEOF) {
        if (iswspace(ch) || iswcntrl(ch)) {
            empty++;
        } else {
            visible++;
        }
    }

    fclose(file);

    wcout << L"\nСтатистика для файла '" << filename << L"':\n";
    wcout << L"Пустых символов: " << empty << endl;
    wcout << L"Непустых символов: " << visible << endl;
}

void searchInFile(wchar_t *filename, wchar_t *substring) {
    FILE *file;
    _wfopen_s(&file, filename, L"r, ccs=UTF-8");
    if (!file) {
        wcerr << L"Ошибка: не удалось открыть файл " << filename << endl;
        return;
    }

    FILE *out;
    _wfopen_s(&out, L"result.txt", L"w, ccs=UTF-8");
    if (!out) {
        wcerr << L"Ошибка: не удалось создать файл result.txt" << endl;
        fclose(file);
        return;
    }

    wchar_t line[MAX_STRING_SIZE];
    int lineNum = 0, found = 0;

    while (fgetws(line, MAX_STRING_SIZE, file)) {
        lineNum++;
        // Создаем копии строки и подстроки для регистронезависимого поиска
        wchar_t lineLower[MAX_STRING_SIZE], subLower[MAX_STRING_SIZE];
        wcscpy_s(lineLower, line);
        wcscpy_s(subLower, substring);
        _wcslwr_s(lineLower, MAX_STRING_SIZE);
        _wcslwr_s(subLower, MAX_STRING_SIZE);

        // Поиск подстроки с учетом регистра и вычисление позиции
        if (wcsstr(lineLower, subLower)) {
            found++;
            wcout << L"Найдено в строке " << lineNum << L": " << line;
            if (found == 1) {
                fwprintf(out, L"Результаты поиска '%ls' в файле '%ls':\n", substring, filename);
            }
            fwprintf(out, L"Строка %d, позиция %d\n", lineNum, (int) (wcsstr(lineLower, subLower) - lineLower + 1));
        }
    }

    if (!found) {
        wcout << L"Подстрока '" << substring << L"' не найдена в файле " << filename << endl;
        fwprintf(out, L"Подстрока '%ls' не найдена\n", substring);
    }

    fclose(file);
    fclose(out);
    wcout << L"Результаты сохранены в result.txt" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    wchar_t filename[MAX_PATH], substring[MAX_STRING_SIZE];

    wcout << L"Введите имя файла: ";
    _getws(filename);

    wcout << L"Введите подстроку для поиска: ";
    _getws(substring);

    createTestFile();
    displayFile(filename);
    countSymbols(filename);
    searchInFile(filename, substring);
    return 0;
}