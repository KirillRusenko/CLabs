#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string extractPageNumber(const string &line) {
    size_t start = line.find('-');
    if (start == string::npos) return "";

    size_t end = line.find('-', start + 1);
    if (end == string::npos) return "";

    string number = line.substr(start + 1, end - start - 1);
    // Remove spaces
    number.erase(0, number.find_first_not_of(" "));
    number.erase(number.find_last_not_of(" ") + 1);
    return number;
}

void processFile(const string &inputPath, const string &outputPath) {
    ifstream input(inputPath);
    ofstream output(outputPath);

    if (!input || !output) {
        wcout << L"Ошибка открытия файлов!" << endl;
        return;
    }

    string line;
    vector<string> currentPage;
    int pageNumber = 1;
    bool firstLineOfPage = true;
    string tempLine;

    while (getline(input, line)) {
        if (line.find("\\f") != string::npos) {
            // Write current page
            for (const string &pageLine: currentPage) {
                output << pageLine << endl;
            }
            output << pageNumber << endl << "\\f" << endl;

            // Prepare for next page
            currentPage.clear();
            pageNumber++;
            firstLineOfPage = true;
            continue;
        }

        if (firstLineOfPage) {
            string num = extractPageNumber(line);
            if (!num.empty()) {
                firstLineOfPage = false;
                continue;
            }
            firstLineOfPage = false;
        }

        if (!line.empty() && line[line.length() - 1] == '-') {
            tempLine = line.substr(0, line.length() - 1);
            continue;
        }

        if (!tempLine.empty()) {
            currentPage.push_back(tempLine + line);
            tempLine = "";
        } else {
            currentPage.push_back(line);
        }
    }

    // Write last page
    if (!currentPage.empty()) {
        for (const string &pageLine: currentPage) {
            output << pageLine << endl;
        }
        output << pageNumber;
    }

    input.close();
    output.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    string inputFile, outputFile;
    wcout << L"Введите имя входного файла: ";
    getline(cin, inputFile);
    if (inputFile.empty()) {
        inputFile = "page_example.txt";
    }
    wcout << L"Введите имя выходного файла: ";
    getline(cin, outputFile);
    if (outputFile.empty()) {
        outputFile = "page_output.txt";
    }

    processFile(inputFile, outputFile);
    return 0;
}