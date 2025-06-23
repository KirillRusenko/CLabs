#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

const int N = 5;

// Функция для вывода матрицы
void printMatrix(float m[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            wcout << setw(8) << setprecision(5) << m[i][j];
        }
        wcout << endl;
    }
}

// 1. Минимум матрицы
float matrixMin(float m[N][N]) {
    float min_val = m[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(m[i][j] < min_val) min_val = m[i][j];
        }
    }
    return min_val;
}

// 2. Максимум матрицы
float matrixMax(float m[N][N]) {
    float max_val = m[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(m[i][j] > max_val) max_val = m[i][j];
        }
    }
    return max_val;
}

// 3. Максимум нижнетреугольной части
float lowerTriangleMax(float m[N][N]) {
    float max_val = m[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            if(m[i][j] > max_val) max_val = m[i][j];
        }
    }
    return max_val;
}

// 4. Максимум верхнетреугольной части
float upperTriangleMax(float m[N][N]) {
    float max_val = m[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            if(m[i][j] > max_val) max_val = m[i][j];
        }
    }
    return max_val;
}

// 5. Минимум нижнетреугольной части
float lowerTriangleMin(float m[N][N]) {
    float min_val = m[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            if(m[i][j] < min_val) min_val = m[i][j];
        }
    }
    return min_val;
}

// 6. Минимум верхнетреугольной части
float upperTriangleMin(float m[N][N]) {
    float min_val = m[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            if(m[i][j] < min_val) min_val = m[i][j];
        }
    }
    return min_val;
}

// 7. Минимум главной диагонали
float mainDiagonalMin(float m[N][N]) {
    float min_val = m[0][0];
    for(int i = 0; i < N; i++) {
        if(m[i][i] < min_val) min_val = m[i][i];
    }
    return min_val;
}

// 8. Максимум главной диагонали
float mainDiagonalMax(float m[N][N]) {
    float max_val = m[0][0];
    for(int i = 0; i < N; i++) {
        if(m[i][i] > max_val) max_val = m[i][i];
    }
    return max_val;
}

// 9. Минимум побочной диагонали
float secondaryDiagonalMin(float m[N][N]) {
    float min_val = m[0][N-1];
    for(int i = 0; i < N; i++) {
        if(m[i][N-1-i] < min_val) min_val = m[i][N-1-i];
    }
    return min_val;
}

// 10. Максимум побочной диагонали
float secondaryDiagonalMax(float m[N][N]) {
    float max_val = m[0][N-1];
    for(int i = 0; i < N; i++) {
        if(m[i][N-1-i] > max_val) max_val = m[i][N-1-i];
    }
    return max_val;
}

// 11. Среднеарифметическое матрицы
float matrixAverage(float m[N][N]) {
    float sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum / (N * N);
}

// 12. Среднеарифметическое нижнетреугольной части
float lowerTriangleAverage(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// 13. Среднеарифметическое верхнетреугольной части
float upperTriangleAverage(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// 14. Суммы строк
void rowSums(float m[N][N], float sums[N]) {
    for(int i = 0; i < N; i++) {
        sums[i] = 0;
        for(int j = 0; j < N; j++) {
            sums[i] += m[i][j];
        }
    }
}

// 15. Суммы столбцов
void columnSums(float m[N][N], float sums[N]) {
    for(int j = 0; j < N; j++) {
        sums[j] = 0;
        for(int i = 0; i < N; i++) {
            sums[j] += m[i][j];
        }
    }
}

// 16. Минимальные значения строк
void rowMins(float m[N][N], float mins[N]) {
    for(int i = 0; i < N; i++) {
        mins[i] = m[i][0];
        for(int j = 1; j < N; j++) {
            if(m[i][j] < mins[i]) mins[i] = m[i][j];
        }
    }
}

// 17. Минимальные значения столбцов
void columnMins(float m[N][N], float mins[N]) {
    for(int j = 0; j < N; j++) {
        mins[j] = m[0][j];
        for(int i = 1; i < N; i++) {
            if(m[i][j] < mins[j]) mins[j] = m[i][j];
        }
    }
}

// 18. Максимальные значения строк
void rowMaxs(float m[N][N], float maxs[N]) {
    for(int i = 0; i < N; i++) {
        maxs[i] = m[i][0];
        for(int j = 1; j < N; j++) {
            if(m[i][j] > maxs[i]) maxs[i] = m[i][j];
        }
    }
}

// 19. Максимальные значения столбцов
void columnMaxs(float m[N][N], float maxs[N]) {
    for(int j = 0; j < N; j++) {
        maxs[j] = m[0][j];
        for(int i = 1; i < N; i++) {
            if(m[i][j] > maxs[j]) maxs[j] = m[i][j];
        }
    }
}

// 20. Среднеарифметические значения строк
void rowAverages(float m[N][N], float avgs[N]) {
    for(int i = 0; i < N; i++) {
        avgs[i] = 0;
        for(int j = 0; j < N; j++) {
            avgs[i] += m[i][j];
        }
        avgs[i] /= N;
    }
}

// 21. Среднеарифметические значения столбцов
void columnAverages(float m[N][N], float avgs[N]) {
    for(int j = 0; j < N; j++) {
        avgs[j] = 0;
        for(int i = 0; i < N; i++) {
            avgs[j] += m[i][j];
        }
        avgs[j] /= N;
    }
}

// 22. Суммы нижней и верхней треугольных частей
void triangleSums(float m[N][N], float &lowerSum, float &upperSum) {
    lowerSum = upperSum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            lowerSum += m[i][j];
        }
        for(int j = i; j < N; j++) {
            upperSum += m[i][j];
        }
    }
}

// 23. Элемент, наиболее близкий к среднеарифметическому
void closestToAverage(float m[N][N], int &row, int &col) {
    float avg = matrixAverage(m);
    float min_diff = fabs(m[0][0] - avg);
    row = col = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            float diff = fabs(m[i][j] - avg);
            if(diff < min_diff) {
                min_diff = diff;
                row = i;
                col = j;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    float m[N][N];

    // Инициализация матрицы случайными значениями
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            m[i][j] = rand() % 1000 / 10.0f;
        }
    }

    // Вывод матрицы
    wcout << L"Матрица:" << endl;
    printMatrix(m);

    // Вычисление и вывод всех требуемых значений
    wcout << L"\n1. Минимум матрицы: " << matrixMin(m) << endl;
    wcout << L"2. Максимум матрицы: " << matrixMax(m) << endl;
    wcout << L"3. Максимум нижнетреугольной части: " << lowerTriangleMax(m) << endl;
    wcout << L"4. Максимум верхнетреугольной части: " << upperTriangleMax(m) << endl;
    wcout << L"5. Минимум нижнетреугольной части: " << lowerTriangleMin(m) << endl;
    wcout << L"6. Минимум верхнетреугольной части: " << upperTriangleMin(m) << endl;
    wcout << L"7. Минимум главной диагонали: " << mainDiagonalMin(m) << endl;
    wcout << L"8. Максимум главной диагонали: " << mainDiagonalMax(m) << endl;
    wcout << L"9. Минимум побочной диагонали: " << secondaryDiagonalMin(m) << endl;
    wcout << L"10. Максимум побочной диагонали: " << secondaryDiagonalMax(m) << endl;
    wcout << L"11. Среднеарифметическое матрицы: " << matrixAverage(m) << endl;
    wcout << L"12. Среднеарифметическое нижнетреугольной части: " << lowerTriangleAverage(m) << endl;
    wcout << L"13. Среднеарифметическое верхнетреугольной части: " << upperTriangleAverage(m) << endl;

    float sums[N];
    rowSums(m, sums);
    wcout << L"\n14. Суммы строк: ";
    for(int i = 0; i < N; i++) wcout << sums[i] << L" ";

    columnSums(m, sums);
    wcout << L"\n15. Суммы столбцов: ";
    for(int j = 0; j < N; j++) wcout << sums[j] << L" ";

    float mins[N], maxs[N], avgs[N];
    rowMins(m, mins);
    wcout << L"\n16. Минимальные значения строк: ";
    for(int i = 0; i < N; i++) wcout << mins[i] << L" ";

    columnMins(m, mins);
    wcout << L"\n17. Минимальные значения столбцов: ";
    for(int j = 0; j < N; j++) wcout << mins[j] << L" ";

    rowMaxs(m, maxs);
    wcout << L"\n18. Максимальные значения строк: ";
    for(int i = 0; i < N; i++) wcout << maxs[i] << L" ";

    columnMaxs(m, maxs);
    wcout << L"\n19. Максимальные значения столбцов: ";
    for(int j = 0; j < N; j++) wcout << maxs[j] << L" ";

    rowAverages(m, avgs);
    wcout << L"\n20. Среднеарифметические значения строк: ";
    for(int i = 0; i < N; i++) wcout << avgs[i] << L" ";

    columnAverages(m, avgs);
    wcout << L"\n21. Среднеарифметические значения столбцов: ";
    for(int j = 0; j < N; j++) wcout << avgs[j] << L" ";

    float lowerSum, upperSum;
    triangleSums(m, lowerSum, upperSum);
    wcout << L"\n22. Сумма нижнетреугольной части: " << lowerSum;
    wcout << L"\n    Сумма верхнетреугольной части: " << upperSum << endl;

    int row, col;
    closestToAverage(m, row, col);
    wcout << L"23. Элемент, наиболее близкий к среднеарифметическому: m["
          << row << L"][" << col << L"] = " << m[row][col] << endl;
}
