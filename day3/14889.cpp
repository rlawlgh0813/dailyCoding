#include <bits/stdc++.h>
using namespace std;
int n,ret = 987654321;
int a[24][24];

int go(vector<int>& s, vector<int>& l){
    pair<int,int> ret;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            if(i == j) continue;
            ret.first += a[s[i]][s[j]];
            ret.second += a[l[i]][l[j]];
        }
    }
    return abs(ret.first - ret.second);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> a[i][j];

    for(int i=0; i<(1<<n); i++){
        if(__builtin_popcount(i) != n/2) continue;
        vector<int> a,b;
        for(int j=0; j<n; j++){
            if(i & (1<<j)) a.push_back(j);
            else b.push_back(j);
        }
        ret = min(ret, go(a,b));
    }
    cout << ret;
}