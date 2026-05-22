#include <iostream>
#include <string>

using namespace std;

class electronica {
	string name;
	int memoryCapacity;
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

	virtual int averageCapacity() {
		if (deviceCount == 0) return 0;
		else return totalMemory / deviceCount;
	}
};

int Electronica::deviceCount = 0;
int Electronica::totalMemory = 0;

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
		smartphone(
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

int main() {
	smartphone s1("iPhone 15", 256, 48);
    smartphone s2("Samsung S24", 512, 108);
	
    laptop l1("Lenovo", 1024, 16);
	
    s1.show();
    cout << endl;
    s2.show();
    cout << endl;
    l1.show();
    cout << endl;
	
    s1.work();
    cout << endl;
    l1.work();
    cout << endl;
	
    cout << "Количество устройств: "
         << Electronica::deviceCount << endl;
	
    cout << "Средний объем памяти: " << Electronica::averageCapacity() << " ГБ" << endl;
}
