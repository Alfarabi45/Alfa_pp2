#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v; 

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a + b, i});
    }

    sort(v.begin(), v.end()); 

    for (auto &p : v) {
        cout << p.second << " ";
    }

    return 0;
}
