#include <bits/stdc++.h>
using namespace std;
int n, p, q;

int go(int n, int x, int y){
    if(n == 0) return 0;

    int m = 1 << (n-1), sz = m*m, ret = 0;
    if(x < m && y < m) ret += go(n-1, x, y);
    else if(x < m && y >= m) ret += sz + go(n-1, x, y-m);
    else if(x >= m && y < m) ret += sz*2 + go(n-1, x-m, y);
    else ret += sz*3 + go(n-1, x-m, y-m);
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p >> q;
    
    cout << go(n,p,q);
}