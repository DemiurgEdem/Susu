#include <iostream> 
#include <chrono> 
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main() {
    //начало временнОго отрезка 
    auto start = chrono::high_resolution_clock::now();
    //... 
    //код 
    //... 
    //конец временнОго отрезка 
    auto end = chrono::high_resolution_clock::now();
    //вычисление длительности по времени в секундах 
    chrono::duration<double> duration = end - start;
    //вычисление длительности по времени в миллисекундах (действует округление) 
    chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(duration);
    //вывод времени в секундах 
    cout << duration.count() << " s" << endl;
    //вывод времени в миллисекундах 
    cout << ms.count() << " ms" << endl;

    return 0;
}
