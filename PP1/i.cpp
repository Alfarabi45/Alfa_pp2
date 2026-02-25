#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // attendance percentage
    double attendance = (m * 100.0) / n;

    if (attendance >= 80.0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}