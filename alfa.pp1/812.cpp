#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> seen;

    for(int x : arr) {
        if(seen.count(x) == 0) {
            cout << "YES" << endl;
            seen.insert(x);
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
