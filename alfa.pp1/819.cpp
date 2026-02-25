#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> episodes; // key = dorama, value = total episodes

    for (int i = 0; i < n; i++) {
        string dorama;
        int k;
        cin >> dorama >> k;
        episodes[dorama] += k; // accumulate episodes
    }

    // Print in lexicographical order
    for (auto &p : episodes) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
