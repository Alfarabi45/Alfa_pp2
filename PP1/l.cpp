#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "NO\n";
        return 0;
    }

    if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}