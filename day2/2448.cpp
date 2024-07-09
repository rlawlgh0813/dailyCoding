#include <bits/stdc++.h>
using namespace std;
int n;
char a[7000][7000];
char star[3][6] = {"  *  ", " * * ", "*****"};

void go(int sz, int x, int y){
    if(sz == 3){
        for(int i=0; i<3; i++) for(int j=0; j<5; j++) a[x+i][y+j] = star[i][j];
        return;
    }
    go(sz/2, x, y+sz/2);
    go(sz/2, x+sz/2, y);
    go(sz/2, x+sz/2, y+sz);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<7000; i++) for(int j=0; j<7000; j++) a[i][j] = ' ';
    go(n,0,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<(2*n+1); j++) cout << a[i][j];
        cout << '\n';
    }
}