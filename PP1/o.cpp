#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Use formula for sum of first n natural numbers
    long long sum = n * (n + 1) / 2;

    cout << sum << "\n";

    return 0;
}