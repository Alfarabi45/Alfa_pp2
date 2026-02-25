#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxNum = a[0], minNum = a[0];

    
    for (int i = 1; i < n; i++) {
        if (a[i] > maxNum) maxNum = a[i];
        if (a[i] < minNum) minNum = a[i];
    }

    
    for (int i = 0; i < n; i++) {
        if (a[i] == maxNum)
            a[i] = minNum;
        cout << a[i] << " ";  
    }

    return 0;
}