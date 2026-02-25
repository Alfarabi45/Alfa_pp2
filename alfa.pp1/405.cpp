#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
int maxNum = a[0];
int pos = 0;
 for (int i = 0; i < n; i++) {
    if (a[i] > maxNum){
    maxNum = a[i];
    pos = i;
 }
}
 cout << pos + 1;
 return 0;
}