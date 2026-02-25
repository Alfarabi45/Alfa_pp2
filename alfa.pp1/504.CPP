#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxVal;
    int row = 1, col = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (i == j) {
                if (i == 0) {
                    maxVal = val;
                    row = col = 1;
                } else if (val > maxVal) {
                    maxVal = val;
                    row = col = i + 1;
                }
            }
        }
    }

    cout << "Maximum element is: " << maxVal 
         << " with coordinates: " << row << ";" << col;
    return 0;
}