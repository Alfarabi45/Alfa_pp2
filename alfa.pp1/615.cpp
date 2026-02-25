#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);  // Read the full line, including spaces

    string result = "";
    string vowels = "aeiouAEIOU";

    for (char c : s) {
        if (vowels.find(c) == string::npos) {  // If character not found in vowels
            result += c;
        }
    }

    cout << result;
    return 0;
}
