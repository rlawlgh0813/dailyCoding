#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,m,k,r,c,s,ret=INF,sx,sy,ex,ey,dir;
int a[54][54], b[54][54], vis[54][54];
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
        memset(vis,0,sizeof(vis));
        dir = 0;
        temp.push_back({sx,sy});
        vis[sx][sy] = 1;
        go(sx,sy,1);

        vector<int> val;
        for(auto i : temp) val.push_back(b[i.first][i.second]);
        rotate(val.rbegin(), val.rbegin()+1, val.rend());
        for(int i=0; i<temp.size(); i++) b[temp[i].first][temp[i].second] = val[i];
    }
}

int solve(){
    for(int i : vv) rotateArr(v[i].x, v[i].y, v[i].cnt);
    int mn = INF;
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
        ret = min(ret,solve());
    }while(next_permutation(vv.begin(), vv.end()));
    cout << ret;
}