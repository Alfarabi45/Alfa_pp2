#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int d1 = n / 1000;         // first digit
    int d2 = (n / 100) % 10;   // second digit
    int d3 = (n / 10) % 10;    // third digit
    int d4 = n % 10;           // fourth digit

    if (d1 == d4 && d2 == d3)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}