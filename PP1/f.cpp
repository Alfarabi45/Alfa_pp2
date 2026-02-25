#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << "Super\n";
    } else {
        if (n >= 2 && n <= 5)
            cout << "Not Super\n";
        else if (n >= 6 && n <= 20)
            cout << "Super\n";
        else if (n > 20)
            cout << "Not Super\n";
    }

    return 0;
}