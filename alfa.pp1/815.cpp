#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> numbers; // key = number, value = count
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers[x]++; // store frequency (count)
    }

    // The last element in the map is the maximum key
    cout << numbers.rbegin()->first << endl;

    return 0;
}
