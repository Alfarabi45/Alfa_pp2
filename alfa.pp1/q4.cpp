#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    double a_cube = pow(a, 3);   // a^3
    double b_sqrt = sqrt(b);     // sqrt(b)

    cout << a_cube << " ";
    cout << b_sqrt << endl;

    return 0;
}