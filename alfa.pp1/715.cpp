#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k;

    cin >> s >> k;

    int countDigits = 0;

    for (char c : s) {
        if (isdigit(c)) {
            countDigits++;
        }
    }

    if (countDigits >= k)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
