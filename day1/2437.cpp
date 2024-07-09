#include <bits/stdc++.h>
using namespace std;
int n,cur=1;
int a[1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    
    sort(&a[0], &a[n]);
    for(int i=0; i<n; i++){
        if(cur < a[i]) break;
        cur += a[i];
    }
    cout << cur;
}