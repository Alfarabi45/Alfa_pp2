#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    char best_char = s[0]; // символ самой длинной цепочки
    int best_len = 1;      // длина самой длинной цепочки
    int current_len = 1;   // длина текущей цепочки

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            current_len++;  // продолжается цепочка
        } else {
            if (current_len > best_len) {
                best_len = current_len;
                best_char = s[i - 1];
            }
            current_len = 1; // начинаем новую цепочку
        }
    }

    // Проверяем последнюю последовательность
    if (current_len > best_len) {
        best_len = current_len;
        best_char = s[s.size() - 1];
    }

    cout << best_char << " " << best_len << endl;

    return 0;
}
