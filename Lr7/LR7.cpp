#include <iostream>

using namespace std;

// Базовый абстрактный класс для геометрических фигур
class Shape {
protected:
    int x, y; // Координаты фигуры

public:
    // Конструктор с инициализацией координат
    Shape(int x, int y) : x(x), y(y) {}

    // Виртуальная функция для рисования фигуры
    virtual void draw() = 0;

    // Виртуальная функция для перемещения фигуры
    virtual void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    // Виртуальный деструктор
    virtual ~Shape() {}
};

// Производный класс для круга
class Circle : public Shape {
private:
    int radius; // Радиус круга

public:
    // Конструктор с инициализацией координат и радиуса
    Circle(int x, int y, int radius) : Shape(x, y), radius(radius) {}

    // Переопределение функции рисования для круга
    void draw() override {
        wcout << L"Рисуем круг в координатах (" << x << L", " << y << L") с радиусом " << radius << endl;
    }

    // Переопределение функции перемещения для круга
    void move(int dx, int dy) override {
        Shape::move(dx, dy);
        wcout << L"Круг перемещен в координаты (" << x << L", " << y << L")" << endl;
    }
};

// Производный класс для прямоугольника
class Rectangle : public Shape {
private:
    int width, height; // Ширина и высота прямоугольника

public:
    // Конструктор с инициализацией координат, ширины и высоты
    Rectangle(int x, int y, int width, int height) : Shape(x, y), width(width), height(height) {}

    // Переопределение функции рисования для прямоугольника
    void draw() override {
        wcout << L"Рисуем прямоугольник в координатах (" << x << L", " << y << L") с шириной " << width
              << L" и высотой " << height << endl;
    }

    // Переопределение функции перемещения для прямоугольника
    void move(int dx, int dy) override {
        Shape::move(dx, dy);
        wcout << L"Прямоугольник перемещен в координаты (" << x << L", " << y << L")" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание объектов фигур через указатели на базовый класс
    Shape *shape1 = new Circle(10, 20, 5);
    Shape *shape2 = new Rectangle(30, 40, 100, 50);

    // Демонстрация полиморфного поведения при рисовании
    shape1->draw();
    shape2->draw();

    // Демонстрация полиморфного поведения при перемещении
    shape1->move(5, 10);
    shape2->move(-10, -20);

    // Проверка новых позиций фигур
    shape1->draw();
    shape2->draw();

    // Освобождение памяти
    delete shape1;
    delete shape2;

    return 0;
}