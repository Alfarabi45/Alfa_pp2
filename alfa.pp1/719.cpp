#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char normalize(char c) {
    c = tolower(c);

    if (c == 'b' || c == 'p')
        return 'b';
    if (c == 'i' || c == 'e')
        return 'i';

    return c;
}

bool similar(string a, string b) {
    if (a.size() != b.size()) return false;

    for (int i = 0; i < a.size(); i++) {
        if (normalize(a[i]) != normalize(b[i]))
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string a, b;
        cin >> a >> b;

        if (similar(a, b))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
