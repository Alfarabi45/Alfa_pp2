#include <iostream>
using namespace std;

bool isLucky(int n) {
    int last_digit = n % 10;   // последняя цифра
    if (last_digit == 0) return false; // делить на 0 нельзя

    int sum = 0;
    int temp = n;

    while (temp > 0) {
        sum += temp % 10;  // прибавляем последнюю цифру
        temp /= 10;        // убираем последнюю цифру
    }

    return (sum % last_digit == 0);
}

int main() {
    int n;
    cin >> n;

    if (isLucky(n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
