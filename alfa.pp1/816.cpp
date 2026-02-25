#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> freq; // key = number, value = count
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    // Iterator to traverse the map
    auto it = freq.begin(); // first (minimum)
    ++it; // move to second element (second minimum)

    cout << it->second << endl; // print frequency of 2nd min

    return 0;
}
