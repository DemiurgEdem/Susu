#include <iostream>
#include <string>

using namespace std;

class electronica {
	string name;
	int memoryCapacity;
public:
	int deviceCount;
	int totalMemory;

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

	virtual int averageCapacity() {
		if (deviceCount == 0) return 0;
		else return totalMemory / deviceCount;
	}
};

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
};

int main() {
	
}
