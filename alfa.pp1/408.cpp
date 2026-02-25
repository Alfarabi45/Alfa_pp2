#include <iostream>
#include <algorithm>  // для sort() и reverse()
using namespace std;

int main() {
    int n;
    cin >> n;                // 1) считываем размер массива
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];         // 2) вводим элементы

    sort(a, a + n);          // 3) сортировка по возрастанию
    reverse(a, a + n);       // 4) разворачиваем (по убыванию)

    for (int i = 0; i < n; i++)
        cout << a[i] << " "; // 5) выводим результат

    return 0;
}