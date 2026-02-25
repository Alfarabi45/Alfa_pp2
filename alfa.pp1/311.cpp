#include <iostream>
using namespace std;

int main() {
int a;
cin >> a;


if (a > 0 && (a & (a - 1)) == 0)
cout << "YES";
else
cout << "NO";

return 0;

}