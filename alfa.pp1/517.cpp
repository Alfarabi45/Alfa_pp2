#include <iostream>
using namespace std;
int main(){
    int x, y;
    cin>>x>>y;
    if(x>7 || x<0 || y>7 || y<0){cout<<"Impossible"<<endl; exit(0);}
    char a[8][8];
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i==x || j==y || i+j==x+y || j-i==y-x){
                a[i][j]='2';} 
                else{a[i][j]='*';}
                }
                }
            a[x][y]='1';
            if(x>7 || x<0 || y>7 || y<0){
        cout<<"Impossible"<<endl;
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout<<a[i][j]<<" ";
            }
             cout<<endl;
             }
             return 0;
}