#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    // If lengths don't match as multiples, impossible
    if (b.size() % a.size() != 0) {
        cout << "NO\n";
        return 0;
    }

    int times = b.size() / a.size();
    string repeated = "";
    for (int i = 0; i < times; i++) {
        repeated += a;
    }

    if (repeated == b)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
