// Подзадание 2



// Подзадание 5

#include <iostream> 
#include <chrono> 
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main() {
    //начало временнОго отрезка 
    auto start = chrono::high_resolution_clock::now();

    int n, m;
    cout << "Enter the dimensions of the matrix n×m: ";
    cin >> n, m;
    MatrixXd mat(n, m);
    cout << "Enter the numbers for the " << n << "×" << m << " matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat(i, j);
            cout << endl;
        }
    }

    MatrixXd trMat = mat.transpose();
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(duration);

    cout << "Original matrix: \n" << mat << endl;
    cout << "Transpose matrix: \n" << trMat << endl;
    
    cout << duration.count() << " s" << endl;
    cout << ms.count() << " ms" << endl;

    return 0;
}
