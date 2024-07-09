#include <bits/stdc++.h>
using namespace std;
int n,m,p,q,ret;
string s;
int a[1004][9], check[1004], vis[1004];

void go(int pos, int dir){
    if(pos < 1 || pos > n || vis[pos]) return;
    vis[pos] = 1;
    
    if(pos < n && !vis[pos+1])
        check[pos+1] = (a[pos][2] == a[pos+1][6]) ? 0 : -dir;
    if(pos > 1 && !vis[pos-1])
        check[pos-1] = (a[pos][6] == a[pos-1][2]) ? 0 : -dir;

    go(pos+1,check[pos+1]);
    go(pos-1,check[pos-1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s;
        for(int j=0; j<8; j++) a[i][j] = s[j] - '0';
    }
    cin >> m;
    for(int i=0; i<m; i++){
        memset(vis,0,sizeof(vis));
        memset(check,0,sizeof(check));

        cin >> p >> q;
        check[p] = q;
        go(p,q);

        for(int i=1; i<=n; i++){
            if(check[i] == 0) continue;
            vector<int> temp(8);
            if(check[i] == 1) for(int j=0; j<8; j++) temp[(j+1) % 8] = a[i][j];
            else if(check[i] == -1) for(int j=0; j<8; j++) temp[j] = a[i][(j+1)%8];
            for(int j=0; j<8; j++) a[i][j] = temp[j];
        }
    }

    for(int i=1; i<=n; i++) if(a[i][0]) ret++;
    cout << ret;
}