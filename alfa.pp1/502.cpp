#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;                // считываем размер массива (n x n)
    int a[n][n];

    int maxNum;              // максимальный элемент
    int row = 0, col = 0;    // его позиция

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];  // вводим элемент

            if (i == 0 && j == 0) // первый элемент — начальный максимум
                maxNum = a[i][j];

            if (a[i][j] > maxNum) { // если нашли больше
                maxNum = a[i][j];
                row = i;
                col = j;
            }
        }
    }

    cout << row + 1 << " " << col + 1; // выводим позицию (1-based)
    return 0;
}