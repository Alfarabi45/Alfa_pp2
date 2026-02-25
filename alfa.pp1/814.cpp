#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    set<int> uniqueSums;

    for (int i = 0; i < N - 1; i++) {
        int sum = a[i] + a[i + 1];
        uniqueSums.insert(sum);
    }

    cout << uniqueSums.size() << endl;

    return 0;
}
