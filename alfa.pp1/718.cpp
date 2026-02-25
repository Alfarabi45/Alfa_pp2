#include <iostream>
#include <string>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Если число 0, результат — просто "0"
    if (n == 0) {
        cout << "0";
        return 0;
    }

    string hex = "";
    string digits = "0123456789ABCDEF";

    while (n > 0) {
        int r = n % 16;        // остаток — это hex-цифра
        hex = digits[r] + hex; // добавляем соответствующий символ
        n /= 16;
    }

    cout << hex;
    return 0;
}
