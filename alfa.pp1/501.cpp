#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;        // 1) считываем размеры массива
    int a[n][m];
    int count = 0;        // счётчик отрицательных чисел

    // 2) читаем элементы массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];      // вводим элемент
            if (a[i][j] < 0)     // если он отрицательный
                count++;          // увеличиваем счётчик
        }
    }

    // 3) выводим результат
    cout << count;

    return 0;
}