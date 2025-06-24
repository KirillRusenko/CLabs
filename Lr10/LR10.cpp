#include <iostream>
#include <string>
#include <utility>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;

    Node(T d) : data(move(d)), next(nullptr) {
    }
};

template<class T>
class SingleLinkedList {
private:
    Node<T> *head;

public:
    SingleLinkedList() : head(nullptr) {
    }

    // Добавление элемента в список
    void add(T data) {
        auto *newNode = new Node<T>(move(data));
        if (!head) {
            head = newNode;
        } else {
            Node<T> *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Удаление элемента из списка по номеру автобуса
    bool remove(int busNumber) {
        Node<T> *temp = head;
        Node<T> *prev = nullptr;

        while (temp) {
            if (temp->data.busNumber == busNumber) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

    // Вывод всех элементов списка
    void print() const {
        Node<T> *temp = head;
        while (temp) {
            wcout << temp->data << endl;
            temp = temp->next;
        }
    }

    // Проверка, пуст ли список
    bool isEmpty() const {
        return head == nullptr;
    }
};

// Структура для хранения информации о автобусе
struct Bus {
    int busNumber;
    wstring driverName;
    int routeNumber;

    Bus(int busNum, wstring driver, int route)
        : busNumber(busNum), driverName(std::move(driver)), routeNumber(route) {
    }

    // Перегрузка оператора вывода
    friend wostream &operator<<(wostream &os, const Bus &bus) {
        os << L"Номер автобуса: " << bus.busNumber << L", Водитель: " << bus.driverName
                << L", Маршрут: " << bus.routeNumber;
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SingleLinkedList<Bus> busPark;
    SingleLinkedList<Bus> routePark;
    srand(time(nullptr));

    // Добавление автобусов в парк
    busPark.add(Bus(1, L"Тестов Т.Т.", 0));
    busPark.add(Bus(2, L"Антонов А.А.", 0));
    busPark.add(Bus(3, L"Супертест", 0));

    wcout << L"Автобусы в автопарке:\n";
    busPark.print();

    while (true) {
        int choice;
        wcout << L"\nВыберите действие:\n";
        wcout << L"1. Выезд автобуса из парка\n";
        wcout << L"2. Возвращение автобуса в парк\n";
        wcout << L"3. Выйти из программы\n";
        cin >> choice;

        int busNumber;

        if (choice == 1) {
            wcout << L"Введите номер автобуса: ";
            cin >> busNumber;
            if (busPark.remove(busNumber)) {
                wcout << L"Автобус " << busNumber << L" выехал из парка.\n";
                routePark.add(Bus(busNumber, L"", rand() % 900 + 100));
            } else {
                wcout << L"Автобус " << busNumber << L" не найден в парке.\n";
            }
        } else if (choice == 2) {
            wcout << L"Введите номер автобуса: ";
            cin >> busNumber;
            if (routePark.remove(busNumber)) {
                wcout << L"Автобус " << busNumber << L" вернулся в парк.\n";
                busPark.add(Bus(busNumber, L"", 0));
            } else {
                wcout << L"Автобус " << busNumber << L" не найден на маршруте.\n";
            }
        } else if (choice == 3) {
            return 0;
        }

        wcout << L"\nАвтобусы в автопарке:\n";
        busPark.print();

        wcout << L"\nАвтобусы на маршруте:\n";
        routePark.print();
    }
}