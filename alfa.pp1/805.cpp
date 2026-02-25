#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int L, R;
        cin >> L >> R;

        int count = 0;
        int mx = 0;

        for (int i = L; i <= R; i++) {
            if (count == 0 || h[i] > mx) {
                mx = h[i];
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
