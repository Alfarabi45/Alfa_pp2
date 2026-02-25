#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> firstIndex; // key = string, value = first occurrence index

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (firstIndex.find(s) == firstIndex.end()) {
            firstIndex[s] = i; // store first occurrence
        }
    }

    // map keys are automatically sorted lexicographically
    for (auto &p : firstIndex) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
