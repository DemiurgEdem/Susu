
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class ship {
	string name;
	int volume;
	int maxSpeed;
public:
	static int count;
	static int sum_volume;

	ship(string name = "", int volume = 0, int maxSpeed = 0) {
		this->name = name;
		if (volume <= 0) this->volume = 0;
		else this->volume = volume;
		if (maxSpeed <= 0) this->maxSpeed = 0;
		else this->maxSpeed = maxSpeed;
		count++;
		sum_volume += this->volume;
	}
	virtual void show() {
		cout << "Название коробля: " << name << endl;
		cout << "Водоизмещение коробля: " << volume << endl;
		cout << "Максимальная скорость коробля: " << maxSpeed << endl;
	}
};

class sailboat : public ship {
	int mast;

public:
	sailboat(
		string name = "", int volume = 0, int maxSpeed = 0, int mast = 1) : ship(name, volume, maxSpeed) {
		this->mast = mast < 0 ? 0 : mast;
	}
	void show() {
		ship::show();
		cout << "Колличество мачт: " << mast << '\n';
	}
};

int ship::count = 0;
int ship::sum_volume = 0;

int main()
{
	setlocale(LC_ALL, "Ru");

	ship s1;
	ship s2("Морж", 1200, 15);
	ship s3("Осётр", 1700, 11);
	ship s4("Потопляемый", 1000, 10);
	ship s5("", 1500);

	sailboat sb1("Черная жемчужина", 600, 25, 2);
	sailboat sb2;

	s1.show();
	s2.show();
	s3.show();
	s4.show();
	s5.show();

	cout << endl;
	sb1.show();
	sb2.show();

	cout << endl;
	cout << ship::count << endl;
	cout << ship::sum_volume << endl;
	cout << sailboat::sum_volume << endl;

	ship* mas[]{&s1, &sb1, &s2, &sb2, new sailboat("Испаньола", 200, 20, 3)};
	ship* p;
	for (int i = 0; i < 5; i++) {
		p = mas[i];
		p->show();
		cout << "\n";
	}

	cout << endl;
	system("pause");
}



//             Дома сделать пароход(мощность[power]), карвет(пушки и паруса)

