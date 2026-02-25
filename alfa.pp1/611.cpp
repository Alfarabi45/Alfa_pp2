#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s; // ввод строки

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'z')
            s[i] = 'a';
        else
            s[i] = s[i] + 1; // следующий символ по алфавиту
    }

    cout << s << endl; // вывод результата
    return 0;
}
