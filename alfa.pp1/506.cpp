#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;

    int value;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> value;
            if (j == n - i - 1) { // если элемент на побочной диагонали
                sum += value;
            }
        }
    }

    cout << sum;
    return 0;
}