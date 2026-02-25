#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long max1 = -10000000000LL, max2 = -10000000000LL;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long x;
            cin >> x;
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x < max1 && x > max2) {
                max2 = x;
            }
        }
    }

    if (max2 == -10000000000LL)
        cout << 0;
    else
        cout << max2;

    return 0;
}