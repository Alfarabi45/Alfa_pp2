#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<bool>> schedule(n, vector<bool>(1440, false));

    for(int i = 0; i < n; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        int start = A * 60 + B;
        int end = C * 60 + D;

        if(start <= end) {
            for(int t = start; t < end; t++) {
                schedule[i][t] = true;
            }
        } else { // магазин работает через полночь
            for(int t = start; t < 1440; t++) schedule[i][t] = true;
            for(int t = 0; t < end; t++) schedule[i][t] = true;
        }
    }

    int result = 0;
    for(int t = 0; t < 1440; t++) {
        bool allOpen = true;
        for(int i = 0; i < n; i++) {
            if(!schedule[i][t]) {
                allOpen = false;
                break;
            }
        }
        if(allOpen) result++;
    }

    cout << result << endl;

    return 0;
}
