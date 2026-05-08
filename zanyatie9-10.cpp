#include <iostream>
#include <fstream>

using namespace std;

enum ttype { charter, transit, docking };
const int SIZE = 20;
struct ttime {
	int h, m;
};

struct timetable {
	char destination[25];
	ttime departure;
	ttime arrival;
	ttime flight;
	int price;
	ttype typeflight;
};

timetable* init() {
	timetable* tables = new timetable[SIZE];
	tables[0] = { "Санкт-Петербург", { 19, 6 }, { 20, 15 }, { 1, 9 }, 5236, charter };
	tables[1] = { "Сочи", { 1, 17 }, { 3, 0 }, { 1, 43 }, 4362, docking };
	tables[2] = { "Калининград", { 9, 32 }, { 11, 16 }, { 1, 34 }, 6426, charter };
	tables[3] = { "Махачкла", { 13, 46 }, { 15, 15 }, { 1, 59 }, 12452, transit };
	tables[4] = { "Казань", { 3, 11 }, { 4, 11 }, { 1, 0 }, 8350, charter };
	tables[5] = { "Екатеринбург", { 3, 22 }, { 5, 45 }, { 2, 23 }, 32523, docking };
	tables[6] = { "Краснодар", { 21, 6 }, { 23, 19 }, { 2, 13 }, 17652, transit };
	tables[7] = { "Самара", { 23, 29 }, { 1, 45 }, { 2, 16 }, 26256, charter };
	tables[8] = { "Челябинск", { 5, 3 }, { 6, 16 }, { 1, 13 }, 8238, docking };
	tables[9] = { "Сочи", { 14, 57 }, { 16, 7 }, { 1, 10 }, 7271, charter };
	tables[10] = { "Краснодар", { 21, 17 }, { 23, 52 }, { 2, 35 }, 27237, transit };
	tables[11] = { "Калининград", { 7, 19 }, { 10, 9 }, { 2, 50 }, 37828, transit };
	tables[12] = { "Махачкла", { 10, 4 }, { 12, 44 }, { 2, 40 }, 27278, docking };
	tables[13] = { "Санкт-Петербург", { 0, 43 }, { 3, 20 }, { 2, 37 }, 37348, transit };
	tables[14] = { "Челябинск", { 13, 0 }, { 15, 47 }, { 2, 47 }, 29069, transit };
	tables[15] = { "Екатеринбург", { 15, 43 }, { 18, 11 }, { 2, 28 }, 14637, charter };
	tables[16] = { "Махачкла", { 12, 8 }, { 13, 47 }, { 1, 39 }, 6835, docking };
	tables[17] = { "Калининград", { 0, 7 }, { 2, 2 }, { 1, 55 }, 12835, transit };
	tables[18] = { "Краснодар", { 13, 14 }, { 14, 19 }, { 1, 5 }, 8994, docking };
	tables[19] = { "Екатеринбург", { 0, 43 }, { 2, 35 }, { 1, 52 }, 9023, charter };
	return tables;
}

//bool isGrad(const char* str) {
//	if (str[-4] == "град")
//}

int main() {
	setlocale(LC_ALL, "");

	timetable* tables;
	tables = init();

	cout << tables[17].destination << endl;
	cout << tables[0].arrival.h << endl;

	char lilStr[25];
	strcpy_s(lilStr, tables[17].destination);
	cout << lilStr;












	system("pause");
}







//struct timetable w;
//timetable* tables;
//tables = init();

//ifstream fin1;
////string str;
//fin1.open("prices.txt"); // файл должен быть в ANSI _кодировке, чтобы выводились русские буквы
//if (fin1.is_open()) {
//	int i = 0;
//	while (!fin1.eof())
//	{
//		fin1 >> tables[i].price;
//		cout << tables[i].destination << " " << tables[i].price << endl;
//		i++;
//	}
//	fin1.close();
//}
//else cout << "File not found";

//ofstream out;
//out.open("prices2.txt");
//int i = 10;
//char s[10]{ "Hello" };
//double d = 2e-10;
//out << i << "\n" << s << "\n" << d <<
//	endl;
//out.close();
