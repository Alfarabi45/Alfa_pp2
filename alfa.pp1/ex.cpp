#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;              // считываем размер массива
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];       // считываем элементы массива
    }

    int maxNum = a[0];     // считаем, что первый элемент — максимум

    for (int i = 1; i < n; i++) {  // начинаем со второго элемента
        if (a[i] > maxNum)         // если нашли число больше
            maxNum = a[i];         // обновляем максимум
    }

    cout << maxNum;        // выводим максимальное число
    return 0;
}