#include <iostream>
using namespace std;

bool isUsual(int num) {
    if (num <= 0) return false; // отрицательные и 0 — не считаем
    
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;

    return num == 1; // если осталась 1 — только 2,3,5 были делителями
}

int main() {
    int n;
    cin >> n;

    if (isUsual(n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
