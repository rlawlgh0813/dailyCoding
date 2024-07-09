#include <bits/stdc++.h>
using namespace std;
int n;
int a[65][65];

string go(int sz, int x, int y){
    if(sz == 1) return to_string(a[x][y]);
    
    int flag = 1;
    for(int i=x; i<x+sz; i++) for(int j=y; j<y+sz; j++) if(a[i][j] != a[x][y]) flag = 0;
    if(flag) return to_string(a[x][y]);
    else{
        string ret = "";
        ret += "(";
        ret += go(sz/2, x, y);
        ret += go(sz/2, x, y+sz/2);
        ret += go(sz/2, x+sz/2, y);
        ret += go(sz/2, x+sz/2, y+sz/2);
        ret += ")";
        return ret;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<n; j++) a[i][j] = s[j] - '0';
    }
    cout << go(n, 0, 0);
}