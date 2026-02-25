#include <iostream>
using namespace std;

// функция, которая выводит массив в обратном порядке
void printReverse(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;               // считываем количество элементов

    int arr[n];             // создаем массив размера n
    for (int i = 0; i < n; i++) {
        cin >> arr[i];      // считываем элементы массива
    }

    printReverse(arr, n);   // выводим в обратном порядке

    return 0;
}
