#include <iostream>
#include <cmath>     
#include <iomanip>   
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    double c = sqrt(a * a + b * b);

    cout << setprecision(4) << c << endl;
    return 0;
}
