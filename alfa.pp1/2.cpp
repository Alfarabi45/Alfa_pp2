#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;              // ввод строки (без пробелов)

    char first = s[0];     // первая буква
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == first) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
