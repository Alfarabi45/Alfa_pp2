#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string s;
    const string target = "@gmail.com";

    for (int i = 0; i < n; ++i) {
        cin >> s;
        // find last '@'
        size_t at_pos = s.rfind('@');
        if (at_pos != string::npos) {
            // check if domain (including '@') equals "@gmail.com"
            if (s.size() >= target.size() && s.substr(at_pos) == target) {
                // ensure there is something before '@' (non-empty login)
                if (at_pos > 0) {
                    cout << s.substr(0, at_pos) << '\n';
                }
            }
        }
    }
    return 0;
}
