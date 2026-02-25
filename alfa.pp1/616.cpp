#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool hasDigit(const string &word) {
    for (char c : word) {
        if (isdigit(c)) return true;
    }
    return false;
}

int main() {
    string line;
    getline(cin, line); // Read the entire sentence

    string word;
    stringstream ss(line); // Split sentence into words

    while (ss >> word) {
        if (!hasDigit(word)) {
            cout << word << endl; // Print only words without digits
        }
    }

    return 0;
}
