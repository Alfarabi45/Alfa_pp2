#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int power = 1;
    while (power <= N) {
        cout << power << " ";
        power *= 2;
    }

    return 0;
}