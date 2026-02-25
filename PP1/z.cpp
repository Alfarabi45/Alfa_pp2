#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "No\n";
        return 0;
    }

    if (a == b || a == c || b == c)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}