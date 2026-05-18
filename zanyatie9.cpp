#include <iostream>
#include <cstring>

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

    tables[0] = { "Санкт-Петербург",{19,6},{20,15},{1,9},5236,charter };
    tables[1] = { "Сочи",{1,17},{3,0},{1,43},4362,docking };
    tables[2] = { "Калининград",{9,32},{11,16},{1,34},6426,charter };
    tables[3] = { "Махачкала",{13,46},{15,15},{1,59},12452,transit };
    tables[4] = { "Казань",{3,11},{4,11},{1,0},8350,charter };
    tables[5] = { "Екатеринбург",{3,22},{5,45},{2,23},32523,docking };
    tables[6] = { "Краснодар",{21,6},{23,19},{2,13},17652,transit };
    tables[7] = { "Самара",{23,29},{1,45},{2,16},26256,charter };
    tables[8] = { "Челябинск",{5,3},{6,16},{1,13},8238,docking };
    tables[9] = { "Сочи",{14,57},{16,7},{1,10},7271,charter };
    tables[10] = { "Краснодар",{21,17},{23,52},{2,35},27237,transit };
    tables[11] = { "Волгоград",{7,19},{10,9},{2,50},37828,transit };
    tables[12] = { "Махачкала",{10,4},{12,44},{2,40},27278,docking };
    tables[13] = { "Санкт-Петербург",{0,43},{3,20},{2,37},37348,transit };
    tables[14] = { "Челябинск",{13,0},{15,47},{2,47},29069,transit };
    tables[15] = { "Екатеринбург",{15,43},{18,11},{2,28},14637,charter };
    tables[16] = { "Махачкала",{12,8},{13,47},{1,39},6835,docking };
    tables[17] = { "Калининград",{0,7},{2,2},{1,55},12835,transit };
    tables[18] = { "Краснодар",{13,14},{14,19},{1,5},8994,docking };
    tables[19] = { "Екатеринбург",{0,43},{2,35},{1,52},9023,charter };

    return tables;
}

//////////////////////////////////////////////////////

bool isGrad(const char* str)
{
    int len = strlen(str);

    if (len < 4)
        return false;

    return strcmp(str + len - 4, "град") == 0;
}

//////////////////////////////////////////////////////

void printFlight(const timetable& t)
{
    cout << "Пункт: " << t.destination << endl;

    cout << "Вылет: "
        << t.departure.h << ":"
        << t.departure.m << endl;

    cout << "Прилет: "
        << t.arrival.h << ":"
        << t.arrival.m << endl;

    cout << "Длительность: "
        << t.flight.h << "ч "
        << t.flight.m << "м" << endl;

    cout << "Цена: " << t.price << endl;

    cout << "Тип: ";

    switch (t.typeflight)
    {
    case charter:
        cout << "charter";
        break;

    case transit:
        cout << "transit";
        break;

    case docking:
        cout << "docking";
        break;
    }

    cout << endl << endl;
}

//////////////////////////////////////////////////////

void printArray(timetable arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printFlight(arr[i]);
    }
}

//////////////////////////////////////////////////////

int flightMinutes(ttime t)
{
    return t.h * 60 + t.m;
}

//////////////////////////////////////////////////////

void sortFlights(timetable arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (flightMinutes(arr[j].flight) >
                flightMinutes(arr[j + 1].flight))
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//////////////////////////////////////////////////////

void changeFlight(timetable& t)
{
    cout << "Новый пункт: ";
    cin >> t.destination;

    cout << "Новая цена: ";
    cin >> t.price;
}

//////////////////////////////////////////////////////

bool isNight(ttime t)
{
    return (t.h >= 0 && t.h < 6);
}

//////////////////////////////////////////////////////

int main()
{
    setlocale(LC_ALL, "");

    timetable* tables = init();

    //////////////////////////////////////////////////
    // 1. Рейсы на "град" и transit

    timetable gradFlights[SIZE];

    int gradCount = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (isGrad(tables[i].destination) &&
            tables[i].typeflight == transit)
        {
            gradFlights[gradCount++] = tables[i];
        }
    }

    //////////////////////////////////////////////////
    // 2. Сортировка

    sortFlights(gradFlights, gradCount);

    cout << "Рейсы на 'град' transit:\n\n";

    printArray(gradFlights, gradCount);

    //////////////////////////////////////////////////
    // 3. Конкретный рейс

    cout << "\nКонкретный рейс:\n\n";

    printFlight(tables[3]);

    //////////////////////////////////////////////////
    // 4. 5 чартерных ночных рейсов

    cout << "\nНочные чартерные рейсы:\n\n";

    int cnt = 0;

    for (int i = 0; i < SIZE && cnt < 5; i++)
    {
        if (tables[i].typeflight == charter &&
            isNight(tables[i].departure))
        {
            printFlight(tables[i]);
            cnt++;
        }
    }

    //////////////////////////////////////////////////
    // 5. Изменение рейса

    changeFlight(tables[0]);

    cout << "\nПосле изменения:\n";

    printFlight(tables[0]);

    //////////////////////////////////////////////////
    // 6. Стыковочные дешевле N

    int N;

    cout << "\nВведите N: ";
    cin >> N;

    timetable cheapDocking[SIZE];

    int cheapCount = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (tables[i].typeflight == docking &&
            tables[i].price < N)
        {
            cheapDocking[cheapCount++] = tables[i];
        }
    }

    cout << "\nДешевые стыковочные рейсы:\n\n";

    printArray(cheapDocking, cheapCount);

    delete[] tables;

    return 0;
}
