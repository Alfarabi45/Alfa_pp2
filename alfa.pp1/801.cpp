#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int num;
    
    // Считываем числа до конца ввода и кладем в вектор
    while (cin >> num) {
        numbers.push_back(num);
    }

    int sum = 0;
    // Считаем сумму элементов вектора
    for (int x : numbers) {
        sum += x;
    }

    cout << sum << endl;

    return 0;
}
