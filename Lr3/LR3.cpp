#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

using namespace std;

// 1. Метод "пузырька"
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2. Быстрая сортировка
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left, j = right;

        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        quickSort(arr, left, j);
        quickSort(arr, i, right);
    }
}

// 3. Сортировка четных по возрастанию, нечетных по убыванию
void customSort(int arr[], int size) {
    vector<int> even, odd;

    // Разделение на четные и нечетные
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even.push_back(arr[i]);
        } else {
            odd.push_back(arr[i]);
        }
    }

    // Сортировка четных по возрастанию
    sort(even.begin(), even.end());

    // Сортировка нечетных по убыванию
    sort(odd.begin(), odd.end(), greater<int>());

    // Слияние обратно в массив
    int e = 0, o = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = even[e++];
        } else {
            arr[i] = odd[o++];
        }
    }
}

// 4. Сортировка на интервале [N1, N2] по возрастанию
void sortRangeAsc(int arr[], int size, int N1, int N2) {
    if (N1 < 0 || N2 >= size || N1 > N2) return;
    sort(arr + N1, arr + N2 + 1);
}

// 5. Сортировка на интервале [N1, N2] по убыванию
void sortRangeDesc(int arr[], int size, int N1, int N2) {
    if (N1 < 0 || N2 >= size || N1 > N2) return;
    sort(arr + N1, arr + N2 + 1, greater<int>());
}

// Функция для вывода массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(mas) / sizeof(int);

    // Создаем копии массива для разных сортировок
    int mas1[n], mas2[n], mas3[n], mas4[n], mas5[n];
    copy(mas, mas + n, mas1);
    copy(mas, mas + n, mas2);
    copy(mas, mas + n, mas3);
    copy(mas, mas + n, mas4);
    copy(mas, mas + n, mas5);

    wcout << L"Исходный массив: ";
    printArray(mas, n);

    // 1. Сортировка пузырьком
    bubbleSort(mas1, n);
    wcout << L"\n1. Сортировка пузырьком: ";
    printArray(mas1, n);

    // 2. Быстрая сортировка
    quickSort(mas2, 0, n - 1);
    wcout << L"2. Быстрая сортировка: ";
    printArray(mas2, n);

    // 3. Сортировка четных по возрастанию, нечетных по убыванию
    customSort(mas3, n);
    wcout << L"3. Четные по возрастанию, нечетные по убыванию: ";
    printArray(mas3, n);

    // 4. Сортировка на интервале от N1 до N2 по возрастанию
    int N1 = 3, N2 = 8;
    sortRangeAsc(mas4, n, N1, N2);
    wcout << L"4. Сортировка по возрастанию от " << N1 << L" до " << N2 << ": ";
    printArray(mas4, n);

    // 5. Сортировка на интервале от N1 до N2 по убыванию
    sortRangeDesc(mas5, n, N1, N2);
    wcout << L"5. Сортировка по убыванию от " << N1 << L" до " << N2 << ": ";
    printArray(mas5, n);
}