template <typename T>
class DeviceArray {
    T** arr;
    int capacity;
    int count;

public:
    DeviceArray(int cap = 10) {
        capacity = cap;
        count = 0;
        arr = new T*[capacity];
    }

    ~DeviceArray() {
        delete[] arr;
    }

    void add(T* device) {
        if (count < capacity) {
            arr[count++] = device;
        } else {
            cout << "Массив переполнен!" << endl;
        }
    }

    void remove(int index) {
        if (index < 0 || index >= count) return;

        for (int i = index; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    T* operator[](int index) {
        if (index >= 0 && index < count)
            return arr[index];
        return nullptr;
    }

    int size() const {
        return count;
    }

    void showAll() const {
        for (int i = 0; i < count; i++) {
            arr[i]->show();
            cout << "------------------" << endl;
        }
    }

    void workAll() const {
        for (int i = 0; i < count; i++) {
            arr[i]->work();
        }
    }
};


DeviceArray<electronica> devices(10);

devices.add(&s1);
devices.add(&s2);
devices.add(&l1);

cout << "\n=== Все устройства ===\n";
devices.showAll();

cout << "\n=== Работа устройств ===\n";
devices.workAll();

cout << "\nРазмер массива: " << devices.size() << endl;

cout << "\nПервое устройство:\n";
devices[0]->show();

devices.remove(1);

cout << "\nПосле удаления:\n";
devices.showAll();
