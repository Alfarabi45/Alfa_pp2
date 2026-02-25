#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << "coordinates of min elements: " << endl;

    long long sum = 0;

    for (int j = 0; j < m; j++) {
        int minVal = a[0][j];
        int minRow = 0;

        for (int i = 1; i < n; i++) {
            if (a[i][j] < minVal) {
                minVal = a[i][j];
                minRow = i;
            }
        }

        cout << minRow + 1 << ";" << j + 1 << endl;
        sum += minVal;
    }

    cout << "\nTheir sum:\n" << sum;
    return 0;
}