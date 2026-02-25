#include <iostream>
#include <algorithm>  // для reverse()
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;     // 1) считываем размер массива и границы
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];        // 2) вводим элементы массива

    reverse(a + l - 1, a + r);  // 3) переворачиваем элементы от l до r

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";    // 4) выводим массив

    return 0;
}