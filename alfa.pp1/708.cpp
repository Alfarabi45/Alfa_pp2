#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false; // 0, 1 и отрицательные не простые

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false; // нашли делитель → не простое
    }

    return true; // не нашли делителей → простое
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
