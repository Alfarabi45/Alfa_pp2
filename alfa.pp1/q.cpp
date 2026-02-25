#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string vowels = "aeiouAEIOU";
    for (char &c : s) {
        if (vowels.find(c) != string::npos)
            c = toupper(c);
    }
    cout << s;
}