#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x, mx = -10000000000LL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > mx) mx = x;
    }
    cout << mx;
    return 0;
}