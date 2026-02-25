#include <iostream>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    int count = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (a == x) count++;
    }

    cout << count;
    return 0;
}
