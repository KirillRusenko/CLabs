#define PR(x) wprintf(L"x=%p, *x=%d, &x=%p\n", (void*)x, *x, (void*)&x)
#include <cstdio>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");
    char charArr[] = {11, 22, 33};
    int intArr[] = {111, 222, 333};
    double doubleArr[] = {1.111, 22.222, 3.333};
    long long longArr[] = {10000000000LL, 20000000000LL, 30000000000LL};

    char *pChar = charArr;
    int *pInt = intArr;
    double *pDouble = doubleArr;
    long long *pLong = longArr;

    wprintf(L"Изначальные адресса:\n");
    wprintf(L"char*    = %p\n", (void *) pChar);
    wprintf(L"int*     = %p\n", (void *) pInt);
    wprintf(L"double*  = %p\n", (void *) pDouble);
    wprintf(L"long long* = %p\n", (void *) pLong);

    pChar++;
    pInt++;
    pDouble++;
    pLong++;

    wprintf(L"\nПосле изменения:\n");
    wprintf(L"char*    = %p\n", (void *) pChar);
    wprintf(L"int*     = %p\n", (void *) pInt);
    wprintf(L"double*  = %p\n", (void *) pDouble);
    wprintf(L"long long* = %p\n", (void *) pLong);
}
