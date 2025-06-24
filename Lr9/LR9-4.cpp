#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Шаблонный класс стека
template<typename T>
class TStack {
private:
    stack<T> data;

public:
    // Добавление элемента в стек
    void push(const T &value) {
        data.push(value);
    }

    // Извлечение элемента из стека
    T pop() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        T top = data.top();
        data.pop();
        return top;
    }

    // Просмотр верхнего элемента без извлечения
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return data.top();
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return data.empty();
    }

    // Размер стека
    size_t size() const {
        return data.size();
    }
};

// Функция для сортировки вагонов с использованием стека (тупика)
template<typename T>
vector<T> sortTrain(vector<T> input) {
    vector<T> output;
    TStack<T> siding; // Тупик (стек)

    while (!input.empty()) {
        T current = input.front();
        input.erase(input.begin());

        // Если выходной состав пуст или текущий вагон подходит по порядку
        if (output.empty() || current < output.back()) {
            output.push_back(current);

            // Проверяем, можно ли переместить вагоны из тупика в выход
            while (!siding.isEmpty() && siding.peek() < output.back()) {
                output.push_back(siding.pop());
            }
        } else {
            // Иначе перемещаем текущий вагон в тупик
            siding.push(current);
        }
    }

    // Перемещаем оставшиеся вагоны из тупика в выход
    while (!siding.isEmpty()) {
        output.push_back(siding.pop());
    }

    return output;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> train1 = {1, 5, 3};
    vector<int> sorted1 = sortTrain(train1);

    wcout << L"Вход: ";
    for (int wagon: train1) cout << wagon << " ";
    wcout << L"\nВыход: ";
    for (int wagon: sorted1) cout << wagon << " ";
    cout << endl << endl;

    return 0;
}
