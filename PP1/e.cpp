#include <iostream>
using namespace std;

int main() {
    int midterm, endterm, finalExam;
    cin >> midterm >> endterm >> finalExam;

    int total = midterm + endterm + finalExam;
    int attestations = midterm + endterm;

    if (total >= 70 && attestations >= 30 && finalExam >= 20)
        cout << "YES!\n";
    else
        cout << "NO.\n";

    return 0;
}