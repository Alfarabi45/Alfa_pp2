#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    int current = 0;   // текущая длина подряд идущих цифр
    int best = 0;      // максимальная длина подряд цифр

    for (char c : s) {
        if (isdigit(c)) {
            current++;
            if (current > best)
                best = current;
        } else {
            current = 0;  // последовательность прерывается
        }
    }

    if (best >= k)
        cout << "Valid";
    else
        cout << "Not valid";

    return 0;
}
