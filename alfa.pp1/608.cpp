#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

string solve(const string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        // Remove one character at position i
        string t = s.substr(0, i) + s.substr(i + 1);
        if (isPalindrome(t, 0, t.size() - 1))
            return "YES";
    }
    return "NO";
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << "\n";
    return 0;
}
