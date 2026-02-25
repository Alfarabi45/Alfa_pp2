#include <iostream>
#include <vector>
using namespace std;

struct Subject {
    int a1;
    int a2;
    int f;
    int credits;
};

int main() {
    int n;
    cin >> n;

    vector<Subject> subjects(n);

    for(int i = 0; i < n; i++) {
        cin >> subjects[i].a1 >> subjects[i].a2 >> subjects[i].f >> subjects[i].credits;
    }

    double weightedPoints = 0;  // сумма (баллы * кредиты)
    int totalCredits = 0;

    // Считаем сумму баллов с учетом кредитов
    for(auto s : subjects) {
        weightedPoints += (s.a1 + s.a2 + s.f) * s.credits;
        totalCredits += s.credits;
    }

    // Предположим, что максимальные баллы за предмет = 64 (примерно из теста)
    double maxPerSubject = 64.0;

    double gpa = weightedPoints / (totalCredits * maxPerSubject);

    cout.precision(9);
    cout << gpa << endl;

    return 0;
}
