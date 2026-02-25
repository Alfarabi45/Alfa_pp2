#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    if (n % 2 == 0)
        cout << "EAGLE\n";
    else
        cout << "TAILS\n";
    
    return 0;
}