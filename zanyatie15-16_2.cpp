// Подзадание 2

#include <iostream> 
#include <chrono> 
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main() {
    auto start = chrono::high_resolution_clock::now();

    Matrix2d A;
    A << 2, 1,
        5, 3;

    Matrix2d B;
    B << 1, 2,
         4, 3;

    Matrix2d X = A.colPivHouseholderQr().solve(B);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(duration);

    cout << "Solution: \n" << X << endl;
    cout << duration.count() << " s" << endl;
    cout << ms.count() << " ms" << endl;

    return 0;
}

// Подзадание 5

#include <iostream> 
#include <chrono> 
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main() {
    int n, m;
    cout << "Enter the dimensions of the matrix n×m: ";
    cin >> n;
    cin >> m;
    MatrixXd mat(n, m);
    cout << "Enter the numbers for the " << n << "×" << m << " matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat(i, j);
            cout << endl;
        }
    }

    auto start = chrono::high_resolution_clock::now();

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
