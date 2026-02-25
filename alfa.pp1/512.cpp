#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(long long x) {
    long long root = sqrt(x);
    return root * root == x;
}

int main() {
    int n, m;
    cin >> n >> m;

    long long a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            if (isPerfectSquare(a)) {
                cout << (long long)sqrt(a) << " ";
            } else {
                cout << a << " ";
            }
        }
        cout << endl;
    }

    return 0;
}