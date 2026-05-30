



// Нужно изменять текстовый файл с прайсами на спец кодировку, а не UTF-8



#include <iostream>
#include <Windows.h>
#include <fstream>
#include <locale>

using namespace std;

enum ttype { charter, transit, docking };
const int TABLE_SIZE = 20;
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
	timetable* tables = new timetable[TABLE_SIZE];
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

int main() {
	setlocale(LC_ALL, "Russian");

	wchar_t destination[25];

	timetable* tables;
	tables = init();
	ifstream fin;
	fin.open("prices.txt");

	if (fin.is_open())
	{
		char oldDestination[25];
		int newPrice;

		
		/*for (int i = 0; i < TABLE_SIZE; i++)
		{
			fin >> oldDestination >> newPrice;
			cout << oldDestination << " " << newPrice << endl;

		}*/

		while (!fin.eof())
		{
			fin >> oldDestination >> newPrice;
			cout << oldDestination << " " << newPrice << endl;

			for (int i = 0; i < TABLE_SIZE; i++)
			{
				if (oldDestination == tables[i].destination)
				{
					tables[i].price = newPrice;
					cout << "Изменено: " << tables[i].destination << " - цена перелета " << tables[i].price << endl;
					break;
				}
			}
		}
		fin.close();
	}
	else cout << "File not found" << endl;


	//ofstream out;
	//out.open("prices2.txt");
	//int i = 10;
	//char s[10]{ "Hello" };
	//double d = 2e-10;
	//out << i << "\n" << s << "\n" << d <<
	//	endl;
	//out.close();

	system("pause");
}
