#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        cout << abs(a[i] - b[i]);
        if (i < n - 1) cout << " ";
    }

    return 0;
}
