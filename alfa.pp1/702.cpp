#include <iostream>
#include <cmath>
using namespace std;
double c(double a, double b) {
    double result;
    result = (sqrt(a*a + b*b));
    return result;
}

int main(){
    double a, b;
    cin >> a >> b;
    double result;
    result = c(a, b);
    cout<<scientific;
    cout.precision(3);  
    cout << result;
    return 0;
}