#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int position = -1;  
    for (int i = 0; i < 7; i++) {
        if (n & (1 << i)) {  
            position = i;
            break;           
        }
    }

    cout << position << "\n";
    return 0;
}








