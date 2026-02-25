#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int x;
    while (cin >> x && x != 0) v.push_back(x);

    int n = v.size();
    vector<int> out;

    for (int i = 0; i < n / 2; ++i) {
        out.push_back(v[i] + v[n - 1 - i]);
    }

    if (n % 2 == 1) {
        out.push_back(v[n / 2]); // центральный элемент остаётся без изменений
    }

    for (size_t i = 0; i < out.size(); ++i) {
        if (i) cout << " ";
        cout << out[i];
    }
    cout << "\n";
    return 0;
}
