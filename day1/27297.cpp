#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p;
ll ret;
ll point[1001][1001], fpoint[1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) cin >> point[j][i];
    }
    for(int i=0; i<n; i++) sort(&point[i][0], &point[i][m]);

    for(int i=0; i<n; i++){
        fpoint[i] = point[i][m/2];
        for(int j=0; j<m; j++) ret += abs(point[i][j] - fpoint[i]);
    }
    cout << ret << '\n';
    for(int i=0; i<n; i++) cout << fpoint[i] << " ";
}