#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // пропускаем символ новой строки после числа

    vector<string> uniqueNames;

    for(int i = 0; i < n; i++) {
        string name;
        getline(cin, name); // читаем фамилию с пробелами, если есть

        // проверяем, встречалась ли фамилия ранее
        bool found = false;
        for(const string &u : uniqueNames) {
            if(u == name) {
                found = true;
                break;
            }
        }
        if(!found) {
            uniqueNames.push_back(name); // добавляем только уникальную
        }
    }

    cout << uniqueNames.size() << endl;

    return 0;
}
