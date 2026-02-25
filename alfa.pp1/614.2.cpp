#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    char letter = s[0];
    int count = 1;
    int maxCount = 1;
    char maxLetter = s[0];

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            maxLetter = s[i];
        }
    }

    cout << maxLetter << " " << maxCount << endl;
    return 0;
}
