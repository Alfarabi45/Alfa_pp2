

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int maxZeros = 0;    // Максимум подряд
    int current = 0;     // Текущая серия нулей

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            current++;             
            if (current > maxZeros) {
                maxZeros = current;  
            }
        } else {
            current = 0; // обнулили потому что серия прервалась
        }
    }

    cout << maxZeros;
    return 0;
}