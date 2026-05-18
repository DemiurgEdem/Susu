// Задача 1

#include <iostream>

using namespace std;

double sqrt_rec(double a, int tochnost) {
    if (tochnost == 0)
        return (1 + a) / 2;
    else
    {
        double x = sqrt_rec(a, tochnost - 1);
        return 0.5 * (x + a / x);
    }
}

void main() {
    double x = 2;
    cout << sqrt(x) << endl;
    int t = 6;
    cout << sqrt_rec(x, t) << endl;
}

/*------------------------------------------------------------*/
// Задача 2

#include <iostream>

using namespace std;

double rec(int n)
{
    if (n == 0)
        cout << "Vvedite korektnoye chislo ";
        return 0;
    if (n == 1)
        return 2.0 / 1;
    if (n % 2 == 0)
        return rec(n - 1) * n / (n - 1.0);
    else
        return rec(n - 1) * (n - 1.0) / n;
}

void main() {
    int n;
    cin >> n;
    cout << rec(n);
}

/*------------------------------------------------------------*/
// Задача 3

#include <iostream>
using namespace std;

void reverse_print(int a[], int n, int index)
{
    if (index == n)
        return;

    reverse_print(a, n, index + 1);

    cout << a[index] << " ";
}

int main()
{
    int a[] = { 1, 2, 3 };

    reverse_print(a, 3, 0);
}

/*------------------------------------------------------------*/
// Задача 4

#include <iostream>
using namespace std;

bool power2(int n)
{
    if (n == 1)
        return true;

    if (n % 2 != 0)
        return false;

    return power2(n / 2);
}

int main()
{
    int n;
    cin >> n;

    if (power2(n))
        cout << "YES";
    else
        cout << "NO";
}

/*------------------------------------------------------------*/
// Задача 5

#include <iostream>
using namespace std;

int ackermann(int m, int n)
{
    if (m == 0)
        return n + 1;

    if (n == 0)
        return ackermann(m - 1, 1);

    return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    int m, n;

    cin >> m >> n;

    cout << ackermann(m, n);
}

/*------------------------------------------------------------*/
// Задача 6

#include <iostream>
using namespace std;

double power(double x, int a)
{
    if (a == 0)
        return 1;

    if (a % 2 == 0)
    {
        double t = power(x, a / 2);
        return t * t;
    }
    else
    {
        return x * power(x, a - 1);
    }
}

int main()
{
    double x;
    int a;

    cin >> x >> a;

    cout << power(x, a);
}

/*------------------------------------------------------------*/
// Задача 7

#include <iostream>
using namespace std;

int sum_digits(int n)
{
    if (n < 10)
        return n;

    return n % 10 + sum_digits(n / 10);
}

int main()
{
    int n;

    cin >> n;

    cout << sum_digits(n);
}

/*------------------------------------------------------------*/
// Задача 8

#include <iostream>
using namespace std;

void rec(int &maxi, int &count)
{
    int x;
    cin >> x;

    if (x == 0)
        return;

    if (x > maxi)
    {
        maxi = x;
        count = 1;
    }
    else if (x == maxi)
    {
        count++;
    }

    rec(maxi, count);
}

int main()
{
    int maxi = -1;
    int count = 0;

    rec(maxi, count);

    cout << count;
}
