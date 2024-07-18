#include <bits/stdc++.h>
using namespace std;
int n,m,k,p,q;
struct shark{
    int v,d,m;
};
struct A{
    int x,y,dir;
};
shark a[104][104], del;
A ret;

void go(int x, int y, int cnt, int dir){
    if(cnt == 0){
        ret.x = x; ret.y = y; ret.dir = dir;
        return;
    }
    if(dir == 1){
        if(x-1 < 0) go(x+1,y,cnt-1,dir+1);
        else go(x-1,y,cnt-1,dir);
    }else if(dir == 2){
        if(x+1 >= n) go(x-1,y,cnt-1,dir-1);
        else go(x+1,y,cnt-1,dir);
    }else if(dir == 3){
        if(y+1 >= m) go(x,y-1,cnt-1,dir+1);
        else go(x,y+1,cnt-1,dir);
    }else if(dir == 4){
        if(y-1 < 0) go(x,y+1,cnt-1,dir-1);
        else go(x,y-1,cnt-1,dir);
    }
}

void move(){
    shark temp[104][104];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) temp[i][j] = del;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j].m){
                go(i,j,a[i][j].v,a[i][j].d);
                if(temp[ret.x][ret.y].m > a[i][j].m) continue;
                temp[ret.x][ret.y] = a[i][j];
                temp[ret.x][ret.y].d = ret.dir;
            }
        }
    }
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) a[i][j] = temp[i][j];
}

void solve(){
    int ret = 0;
    del.m = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[j][i].m){
                ret += a[j][i].m;
                a[j][i] = del;
                break;
            } 
        }
        move();
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<k; i++){
        shark t; cin >> p >> q >> t.v >> t.d >> t.m;
        p--; q--;
        a[p][q] = t;
    }

    solve();
    return 0;
}