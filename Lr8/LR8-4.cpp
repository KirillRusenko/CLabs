// Программа, которая считает до 10 в 2 потока, первый считает нечётные, второй чётные
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;


mutex consoleMutex;

// Функция для вывода нечетных чисел
void printOdd() {
    for (int i = 1; i <= 9; i += 2) {
        lock_guard<mutex> lock(consoleMutex);
        wcout << L"Нечетное число: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

// Функция для вывода четных чисел
void printEven() {
    for (int i = 2; i <= 10; i += 2) {
        lock_guard<mutex> lock(consoleMutex);
        wcout << L"Четное число: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем два потока
    thread oddThread(printOdd);
    thread evenThread(printEven);


    // Ждем завершения обоих потоков
    oddThread.join();
    evenThread.join();

    return 0;
}
