#include <iostream>
#include <string>
using namespace std;

int main() {
    string dish;
    getline(cin, dish); // Read the entire dish name

    int sum = 0;
    for (char c : dish) {
        sum += int(c); // Add ASCII value of each character
    }

    if (sum > 300)
        cout << "It is tasty!";
    else
        cout << "Oh, no!";

    return 0;
}
