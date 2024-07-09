#include <bits/stdc++.h>
using namespace std;
int n;
int a[5001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<(n+1)/2; i++) cout << n-i+1 << " " << i << " ";
    if(n & 1) cout << n/2+1;
    else cout << n/2 + 1 << " " << n/2;
}