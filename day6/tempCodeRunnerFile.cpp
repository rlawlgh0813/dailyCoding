#include <bits/stdc++.h>
using namespace std;
int n,a,b,k,len,pos,ret;
vector<pair<int,int>> v;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        if(pos >= v[i].second) continue;
        if(pos >= v[i].first) v[i].first = pos+1;

        len = v[i].second - v[i].first + 1;
        if(len % k == 0) ret += len / k;
        else ret += len / k + 1;

        pos = v[i].second + (len - len % k);
    }
    cout << ret;
}