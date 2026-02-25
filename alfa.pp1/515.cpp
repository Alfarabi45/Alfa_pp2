#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100][100];
    int num = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // слева направо
        for (int j = left; j <= right; j++)
            a[top][j] = num++;
        top++;

        // сверху вниз
        for (int i = top; i <= bottom; i++)
            a[i][right] = num++;
        right--;

        // справа налево
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                a[bottom][j] = num++;
            bottom--;
        }

        // снизу вверх
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                a[i][left] = num++;
            left++;
        }
    }

    // вывод
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}