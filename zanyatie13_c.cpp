#include <iostream>
using namespace std;

#include <string>

using namespace std;

class electronica {
	string name;
	int memoryCapacity;
protected:
	string getName() const { return name; }
public:
	static int deviceCount;
	static int totalMemory;

	electronica(string n, int memory) {
		name = n;
		if (memory <= 0) memoryCapacity = 0;
		else memoryCapacity = memory;
		deviceCount++;
		totalMemory += memory;
	}

	virtual void show() {
		cout << "Название устройства: " << name << endl;
		cout << "Память устройства: " << memoryCapacity << endl;
	}

	virtual void work() const {
		cout << name << " выполняет стандартную работу." << endl;
	}

	static int averageCapacity() {
		if (deviceCount == 0) return 0;
		else return totalMemory / deviceCount;
	}
};

int electronica::deviceCount = 0;
int electronica::totalMemory = 0;

class smartphone : public electronica {
	int camera;

public:
	smartphone(
		string name = "", int memoryCapacity = 0, int camera = 0) :
		electronica(name, memoryCapacity) {
		this->camera = camera < 0 ? 0 : camera;
	}
	void show() {
		electronica::show();
		cout << "Разрешение камеры: " << camera << endl;
	}
	void work() const override {
		cout << getName() << " используется для звонков и приложений." << endl;
	}
};

class laptop : public electronica {
	int screenSize;

public:
	laptop(
		string name = "", int memoryCapacity = 0, int screenSize = 0) :
		electronica(name, memoryCapacity) {
		this->screenSize = screenSize < 0 ? 0 : screenSize;
	}
	void show() {
		electronica::show();
		cout << "Диагональ экрана: " << screenSize << " дюймов" << endl;
	}
	void work() const override {
		cout << getName() << " используется для работы и учебы." << endl;
	}
};


template <typename T>
class DeviceArray {
	T** arr;
	int capacity;
	int count;

public:
	// Конструктор
	DeviceArray(int cap = 10) {
		capacity = cap;
		count = 0;
		arr = new T * [capacity];
	}

	// Деструктор
	~DeviceArray() {
		delete[] arr;
	}

	// Добавление объектов
	void add(T* device) {
		if (count < capacity) {
			arr[count++] = device;
		}
		else {
			cout << "Массив переполнен!" << endl;
		}
	}

	// Удаление объектов со сдвигом
	void remove(int index) {
		if (index < 0 || index >= count) return;

		for (int i = index; i < count - 1; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
	}

	// Взятие по индексу
	T* operator[](int index) {
		if (index >= 0 && index < count)
			return arr[index];
		return nullptr;
	}

	// Размер массива
	int size() const {
		return count;
	}

	// Показывает все устройства
	void showAll() const {
		for (int i = 0; i < count; i++) {
			arr[i]->show();
			cout << "------------------" << endl;
		}
	}

	// Также, но с ворками
	void workAll() const {
		for (int i = 0; i < count; i++) {
			arr[i]->work();
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	smartphone s1("iPhone 15", 256, 48);
	smartphone s2("Samsung S24", 512, 108);

	laptop l1("Lenovo", 1024, 16);

	/*s1.show();
	cout << endl;
	s2.show();
	cout << endl;
	l1.show();
	cout << endl;

	s1.work();
	l1.work();
	cout << endl;

	cout << "Количество устройств: "
		<< electronica::deviceCount << endl;

	cout << "Средний объем памяти: " << electronica::averageCapacity() << " ГБ" << endl;*/


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
}
