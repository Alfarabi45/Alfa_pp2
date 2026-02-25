#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100][100]; // n <= 100 (безопасно)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Обработка каждой строки
    for (int i = 0; i < n; i++) {
        int maxVal = a[i][0]; // предположим, что первый — максимум
        for (int j = 1; j < n; j++) {
            if (a[i][j] > maxVal)
                maxVal = a[i][j];
        }

        // выводим всю строку, заполненную maxVal
        for (int j = 0; j < n; j++) {
            cout << maxVal << " ";
        }
        cout << endl;
    }

    return 0;
}