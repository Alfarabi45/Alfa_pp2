#include <iostream>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;     // 1) читаем размер массива и границы
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];        // 2) считываем элементы массива

    int sum = 0;

    // 3) считаем сумму от l до r (нумерация с 1)
    for (int i = l - 1; i < r; i++) {
        sum += a[i];
    }

    cout << sum;            // 4) выводим результат
    return 0;
}