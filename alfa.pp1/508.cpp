#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100][100]; // можно заменить на вектор, если нужно

    // Считываем матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bool isPerfect = true;

    // Проверяем симметрию относительно главной диагонали
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // только верхний треугольник
            if (a[i][j] != a[j][i]) {
                isPerfect = false;
                break;
            }
        }
        if (!isPerfect) break;
    }

    if (isPerfect)
        cout << "Perfect.";
    else
        cout << "Not perfect.";

    return 0;
}