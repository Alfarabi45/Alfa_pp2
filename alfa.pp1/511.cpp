#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[10][10]; // максимум 10×10
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int minSum = 1e9; // большое число
    int minIndex = 0; // индекс строки

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }

        if (sum < minSum) {
            minSum = sum;
            minIndex = i; // сохраняем индекс
        }
    }

    cout << minIndex + 1; // индексация с 1
    return 0;
}