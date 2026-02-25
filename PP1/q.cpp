#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxVal, pos = 1;  // position starts from 1
    cin >> maxVal;        // read first element
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        if (x > maxVal) {
            maxVal = x;
            pos = i;
        }
    }

    cout << pos << "\n";

    return 0;
}