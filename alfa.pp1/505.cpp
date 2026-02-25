#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num = 1; // start from first odd number

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << num << " ";
        }
        cout << endl;
        num += 2; // next odd number for next row
    }

    return 0;
}