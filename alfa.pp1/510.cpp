#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                // первая строка
                cout << j << " ";
            } else if (j == 0) {
                // первый столбец
                cout << i << " ";
            } else if (i == j) {
                // главная диагональ
                cout << i * i << " ";
            } else {
                // остальные элементы
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}