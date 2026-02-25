#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, char> toDigit = {
        {"ZER", '0'}, {"ONE", '1'}, {"TWO", '2'}, {"THR", '3'},
        {"FOU", '4'}, {"FIV", '5'}, {"SIX", '6'}, {"SEV", '7'},
        {"EIG", '8'}, {"NIN", '9'}
    };

    unordered_map<char, string> toTriplet = {
        {'0', "ZER"}, {'1', "ONE"}, {'2', "TWO"}, {'3', "THR"},
        {'4', "FOU"}, {'5', "FIV"}, {'6', "SIX"}, {'7', "SEV"},
        {'8', "EIG"}, {'9', "NIN"}
    };

    string s;
    cin >> s;

    
    int opPos = -1;
    char op;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
            opPos = i;
            op = s[i];
            break;
        }
    }

    
    string left = s.substr(0, opPos);
    string right = s.substr(opPos + 1);

    
    auto decode = [&](string t) -> long long {
        string num = "";
        for (int i = 0; i < t.size(); i += 3) {
            string tri = t.substr(i, 3);
            num += toDigit[tri];
        }
        return stoll(num);
    };

    long long A = decode(left);
    long long B = decode(right);

    
    long long result;
    if (op == '+') result = A + B;
    else if (op == '-') result = A - B;
    else result = A * B;

    
    string res = to_string(result);
    string output = "";

    for (char c : res) {
        output += toTriplet[c];
    }

    cout << output;
    return 0;
}
