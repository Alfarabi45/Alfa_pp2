#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s); // Read the input string

    bool isIncreasing = true;

    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] < s[i - 1]) { // If a later char is smaller, not increasing
            isIncreasing = false;
            break;
        }
    }

    if (isIncreasing)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
