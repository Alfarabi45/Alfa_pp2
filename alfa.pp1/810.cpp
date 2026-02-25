#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int x;
    
    // Считываем числа до конца ввода
    while(cin >> x) {
        numbers.push_back(x);
    }

    vector<int> uniqueNumbers;

    for(int num : numbers) {
        bool found = false;
        for(int u : uniqueNumbers) {
            if(u == num) {
                found = true;
                break;
            }
        }
        if(!found) {
            uniqueNumbers.push_back(num);
        }
    }

    cout << uniqueNumbers.size() << endl;
    return 0;
}
