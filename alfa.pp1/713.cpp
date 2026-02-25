#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int findNthNumber(int arr[], int n, int x){

    bool pres[1001] = {false};

    for(int i = 0; i < n; i++)
        if(arr[i] >= 1 && arr[i] <= 1000) pres[arr[i]] = true;
    

    int count = 0;
    for(int i = 1; i <= 1000; i++) {
        if(!pres[i]){
            count++;
            if(count == x) return i;
        }
    }
    return -1;
}

int main(){

    string s;
    getline(cin, s);

    stringstream ss(s);
    int arr[1000], n = 0;

    while(ss >> arr[n]) n++;

    int x;
    cin >> x;

    cout << findNthNumber(arr, n, x) << endl;
}