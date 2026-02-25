#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int minNumber = numbers[0]; // предполагаем, что первый элемент минимальный
    for(int i = 1; i < n; i++) {
        if(numbers[i] < minNumber) {
            minNumber = numbers[i];
        }
    }

    cout << minNumber << endl;
    return 0;
}
