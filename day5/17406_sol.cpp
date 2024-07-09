#include <bits/stdc++.h>
using namespace std;
int n,m,k,r,c,s,ret=987654321,sx,sy,ex,ey,dir;
int a[101][101], b[101][101], vis[101][101];
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
struct A{
    int x,y,cnt;
};
vector<A> v;
vector<int> vv;
vector<pair<int,int>> temp;

void go(int x, int y, int first){
    if(!first && x == sx && y == sy) dir++;
    if(!first && x == sx && y == ey) dir++;
    if(!first && x == ex && y == sy) dir++;
    if(!first && x == ex && y == ey) dir++;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(vis[nx][ny]) return;
    vis[nx][ny] = 1;
    temp.push_back({nx,ny});
    go(nx,ny,0);
}

void rotateArr(int x, int y, int cnt){
    for(int i=1; i<=cnt; i++){
        sx = x - 1*i;
        sy = y - 1*i;
        ex = x + 1*i;
        ey = y + 1*i;
        temp.clear();
        dir = 0;
        memset(vis, 0, sizeof(vis));
        vis[sx][sy] = 1;
        temp.push_back({sx,sy});
        go(sx,sy,1);

        vector<int> temp2;
        for(auto i : temp) temp2.push_back(b[i.first][i.second]);
        rotate(temp2.rbegin(), temp2.rbegin()+1, temp2.rend());
        for(int i=0; i<temp.size(); i++) b[temp[i].first][temp[i].second] = temp2[i];
    }
}

int solve(){
    for(int i : vv) rotateArr(v[i].x, v[i].y, v[i].cnt);
    int mn = 987654321;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<m; j++) cnt += b[i][j];
        mn = min(mn,cnt);
    }
    return mn;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> a[i][j];
    for(int i=0; i<k; i++){
        cin >> r >> c >> s;
        v.push_back({r-1,c-1,s});
        vv.push_back(i);
    }

    do{
        memcpy(b,a,sizeof(b));
        ret = min(ret, solve());
    }while(next_permutation(vv.begin(), vv.end()));
    cout << ret;
}