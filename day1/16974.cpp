#include <bits/stdc++.h>
using namespace std;
int n,ret;
int a[21][21];
vector<int> t;

int sum(vector<int> v){
    int ret = 0;
    for(auto x : v) for(auto y : v) ret += a[x][y];
}

void go(int start, vector<int> v){
    if(v.size() == n/2){
        vector<int> vv;
        for(int i=0; i<n; i++) if(find(v.begin(), v.end(), i) != v.end()) vv.push_back(i);
        ret = min(ret, abs(sum(v) - sum(vv)));
        return;
    }
    for(int i=start; i<n; i++){
        v.push_back(i);
        go(i+1, v);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> a[i][j];

    go(0,t);
    cout << ret;
}