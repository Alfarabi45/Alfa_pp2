#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    char ch = t[0]; // буква, которую ищем
    int first = -1, last = -1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ch) {
            if (first == -1)
                first = i;  // первая встреча
            last = i;       // обновляем последнюю
        }
    }

    if (first == -1) {
        // ничего не выводим, буква не найдена
        return 0;
    } 
    else if (first == last) {
        cout << first << endl; // только одна встреча
    } 
    else {
        cout << first  << " " << last << endl; // первая и последняя
    }

    return 0;
}
