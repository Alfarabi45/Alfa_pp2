#include <iostream>
using namespace std;

bool isEven(int x) {
    return x % 2 == 0;
}

int main() {
    int n;
    cin >> n;

    if (isEven(n))
        cout << "Чётное число" << endl;
    else
        cout << "Нечётное число" << endl;
}
