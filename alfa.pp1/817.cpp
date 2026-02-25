#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> freq; // key = phone number, value = count
    for (int i = 0; i < n; i++) {
        string number;
        cin >> number;
        freq[number]++;
    }

    int countThreeTimes = 0;

    for (auto &p : freq) {
        if (p.second == 3) {
            countThreeTimes++;
        }
    }

    cout << countThreeTimes << endl;

    return 0;
}
