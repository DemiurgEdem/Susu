#include <iostream>
using namespace std;

template <class X>
class Array {
    X* arr;
    int size;

public:
    // Конструктор
    Array(int s = 0) {
        size = s;

        if (size > 0)
            arr = new X[size];
        else
            arr = nullptr;
    }

    // Деструктор
    ~Array() {
        delete[] arr;
    }

    // Перегрузка int() -> размер массива
    operator int() const {
        return size;
    }

    // Доступ по индексу
    X& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Ошибка индекса!" << endl;
            exit(1);
        }

        return arr[index];
    }

    // Константная версия []
    const X& operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Ошибка индекса!" << endl;
            exit(1);
        }

        return arr[index];
    }

    // Заполнение
    void set(int index, const X& value) {
        if (index >= 0 && index < size)
            arr[index] = value;
    }

    // Вывод
    void show() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array<int> a(5);

    for (int i = 0; i < (int)a; i++) {
        a[i] = i * 10;
    }

    a.show();

    cout << "Размер массива: " << (int)a << endl;

    return 0;
}
