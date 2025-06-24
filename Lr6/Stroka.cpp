#include <cstring>
#include <iostream>

class Stroka {
private:
    char *str;  // Указатель на символьный массив для хранения строки
    int length; // Текущая длина строки без учета нуль-терминатора

public:
    // Базовые конструкторы и деструктор
    Stroka();                          // Создает пустую строку
    Stroka(const char *);               // Создает строку из С-строки
    Stroka(const Stroka &);             // Создает копию существующей строки
    ~Stroka();                         // Освобождает выделенную память

    // Операторы для работы со строками 
    Stroka &operator=(const Stroka &);  // Копирует содержимое другой строки
    Stroka operator+(const Stroka &);   // Объединяет две строки в новую
    bool operator==(const Stroka &);    // Проверяет строки на равенство

    // Вспомогательные методы
    int dlina();      // Возвращает текущую длину строки
    void vvod();      // Считывает строку с клавиатуры 
    void vyvod();     // Выводит строку на экран
};

// Инициализирует пустую строку
Stroka::Stroka() {
    length = 0;
    str = new char[1];
    str[0] = '\0';
}

// Инициализирует строку из C-строки
Stroka::Stroka(const char *string) {
    length = std::strlen(string);
    str = new char[length + 1];
    std::strcpy(str, string);
}

// Создает глубокую копию существующей строки
Stroka::Stroka(const Stroka &s) {
    length = s.length;
    str = new char[length + 1];
    std::strcpy(str, s.str);
}

// Освобождает выделенную память
Stroka::~Stroka() {
    delete[] str;
}

// Выполняет глубокое копирование с проверкой самоприсваивания
Stroka &Stroka::operator=(const Stroka &s) {
    if (this == &s) return *this;

    delete[] str;
    length = s.length;
    str = new char[length + 1];
    std::strcpy(str, s.str);

    return *this;
}

// Создает новую строку путем объединения двух существующих
Stroka Stroka::operator+(const Stroka &s) {
    Stroka temp;
    temp.length = length + s.length;
    temp.str = new char[temp.length + 1];
    std::strcpy(temp.str, str);
    std::strcat(temp.str, s.str);
    return temp;
}

// Сравнивает строки посимвольно
bool Stroka::operator==(const Stroka &s) {
    return std::strcmp(str, s.str) == 0;
}

// Возвращает длину строки
int Stroka::dlina() {
    return length;
}

// Считывает строку с консоли с ограничением в 255 символов
void Stroka::vvod() {
    char buffer[256];
    std::cin.getline(buffer, 256);

    delete[] str;
    length = std::strlen(buffer);
    str = new char[length + 1];
    std::strcpy(str, buffer);
}

// Выводит строку с переносом строки
void Stroka::vyvod() {
    std::cout << str << std::endl;
}