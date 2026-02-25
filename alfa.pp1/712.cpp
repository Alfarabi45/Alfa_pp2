#include <iostream>
using namespace std;

long long c(long long a[], long long b[], long long n) {
    int count = 0;

    // Санау массиві (мысалы, элементтер 1..100)
    int freqA[101] = {0};
    int freqB[101] = {0};

    for (int i = 0; i < n; i++) freqA[a[i]]++;
    for (int i = 0; i < n; i++) freqB[b[i]]++;

    for (int i = 0; i <= 100; i++) {
        int minFreq = freqA[i] < freqB[i] ? freqA[i] : freqB[i];
        count += minFreq;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    long long a[100000], b[100000];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    cout << c(a, b, n);
}