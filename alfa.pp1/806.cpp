#include <iostream>
#include <vector>
#include <map> // for counting frequency

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> freq; // element -> count
    for(int x : a) {
        freq[x]++;
    }

    int max_count = 0;
    int result = 0;

    for(auto &p : freq) {
        if(p.second > max_count) {
            max_count = p.second;
            result = p.first;
        } else if(p.second == max_count && p.first < result) {
            result = p.first;
        }
    }

    cout << result << endl;

    return 0;
}
