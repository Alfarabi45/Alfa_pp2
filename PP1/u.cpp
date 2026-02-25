#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // First check if a valid triangle
    if (a + b > c && a + c > b && b + c > a) {
        // Check for isosceles (exactly two equal sides)
        if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
            cout << "Yes\n";
        else
            cout << "No\n";
    } else {
        cout << "No\n";
    }

    return 0;
}