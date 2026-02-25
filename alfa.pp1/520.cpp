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

    int winner = 0;
    int best_throw = -1e9;
    int best_sum = -1e9;

    for (int i = 0; i < n; i++) {
        int cur_best = a[i][0];
        int cur_sum = 0;

        for (int j = 0; j < m; j++) {
            cur_sum += a[i][j];
            if (a[i][j] > cur_best)
                cur_best = a[i][j];
        }

        if (cur_best > best_throw ||
           (cur_best == best_throw && cur_sum > best_sum) ||
           (cur_best == best_throw && cur_sum == best_sum && i < winner)) {
            best_throw = cur_best;
            best_sum = cur_sum;
            winner = i;
        }
    }

    cout << winner;
    return 0;
}