#include <iostream>
#include <string>
using namespace std;

string strToBool(string str) {
    if (str == "1")
        return "true";
    if (str == "0")
        return "false";
    return str; // другие строки возвращаем как есть
}

int main() {
    string s;
    cin >> s;

    cout << strToBool(s);

    return 0;
}
