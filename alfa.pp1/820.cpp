#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // ignore newline after integer input

    map<string, string> document;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "set") {
            string key, value;
            cin >> key >> value;
            document[key] = value; // insert or update
        } 
        else if (command == "get") {
            string key;
            cin >> key;
            if (document.find(key) != document.end()) {
                cout << document[key] << endl;
            } else {
                cout << "KE: no key " << key << " found in the document" << endl;
            }
        }
    }

    return 0;
}
