#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int maxZeros = 0;
    int current = 0;

    for(char c : s) {
        if(c == '0') {
            current++;
            maxZeros = max(maxZeros, current);
        } else {
            current = 0;
        }
    }

    cout << maxZeros;
    return 0;
}
 