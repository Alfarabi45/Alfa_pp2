#include <iostream>
#include <vector>
#include <set>
#include <cctype>
using namespace std;

bool isStrong(const string &password) {
    bool hasUpper = false, hasLower = false, hasDigit = false;
    for(char ch : password) {
        if(isupper(ch)) hasUpper = true;
        else if(islower(ch)) hasLower = true;
        else if(isdigit(ch)) hasDigit = true;
    }
    return hasUpper && hasLower && hasDigit;
}

int main() {
    int n;
    cin >> n;
    vector<string> passwords(n);
    for(int i = 0; i < n; i++) {
        cin >> passwords[i];
    }

    set<string> strongPasswords;

    for(string pwd : passwords) {
        if(isStrong(pwd)) {
            strongPasswords.insert(pwd); // set хранит уникальные и отсортированные пароли
        }
    }

    cout << strongPasswords.size() << endl;
    for(const string &pwd : strongPasswords) {
        cout << pwd << endl;
    }

    return 0;
}
