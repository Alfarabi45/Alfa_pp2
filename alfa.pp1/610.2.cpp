#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (b.size() % a.size() != 0) {
        cout << "NO\n";
    return 0;
    }

    for (int i = 0; i < (int)b.size(); i++) {
        if (b[i] != a[i % a.size()]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
