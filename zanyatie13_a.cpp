
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

	// Диструктор
	-Array() {
		delete[] arr;
	}

	// Взятие размера
	int getSize() const {
		return size;
	}

	// Индекс
	X& operator[](int index) {
		if (index < 0 || index >= size) {
			count << "Ошибка индекса!" << endl;
			exit(0);
		}

		return arr[index];
	}

	// Заполение
	void set(int index, const X& value) {
		if (index >= 0 && index < size)
			arr[index] = value;
	}

	// Вывод
	void show() const {
		for (int i = 0; i < size; i++) {
			arr[i].show();
			count << endl;
		}
	}
};
