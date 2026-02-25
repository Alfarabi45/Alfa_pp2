#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ids(n);
    for (int i = 0; i < n; ++i)
        cin >> ids[i];

    int x;
    cin >> x;

    bool found = false;
    for (int id : ids) {
        if (id == x) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
