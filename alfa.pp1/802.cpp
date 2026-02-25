#include <iostream>
#include <vector>
#include <algorithm> // для min_element и max_element
using namespace std;

int main() {
    vector<int> numbers;
    int num;

    // Считываем числа до конца ввода
    while (cin >> num) {
        numbers.push_back(num);
    }

    if (numbers.empty()) return 0; // если вектор пустой

    // Находим минимум и максимум
    int min_val = *min_element(numbers.begin(), numbers.end());
    int max_val = *max_element(numbers.begin(), numbers.end());

    // Заменяем все минимальные элементы на максимум
    for (int &x : numbers) {
        if (x == min_val) x = max_val;
    }

    // Выводим результат
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i != numbers.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
