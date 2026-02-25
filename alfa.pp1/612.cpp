#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;            // input the string
    char max_char = 'a'; // smallest possible starting point

    for (char c : s) {
        if (c > max_char)
            max_char = c;  // update if we find a larger (further) letter
    }

    cout << max_char << endl;  // print the furthest letter
    return 0;
}
