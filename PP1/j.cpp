#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    if (a > b) 
        cout << 1 << "\n";
    else if (b > a) 
        cout << 2 << "\n";
    else 
        cout << 0 << "\n";

    return 0;
}