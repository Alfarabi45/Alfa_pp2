#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        // Нечётное — волна идёт вправо
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i; j++) cout << ".";
            for (int j = 0; j < i; j++) cout << "#";
            cout << endl;
        }
    } else {
        // Чётное — волна идёт влево
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) cout << "#";
            for (int j = 0; j < n - i; j++) cout << ".";
            cout << endl;
        }
    }

    return 0;
}