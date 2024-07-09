#include <bits/stdc++.h>
using namespace std;
int n,x,y,ret;
int a[25],check[13];

void go(){
    int flag = 1;
    for(int i=1; i<=2*n; i++) if(a[i] == 0) flag = 0;
    if(flag){
        ret++;
        return;
    }

    int pos = -1;
    for(int i=1; i<=2*n; i++){
        if(a[i] == 0){
            pos = i;
            break;
        }
    }
    for(int i=1; i<=n; i++){
        if(check[i] || pos+i+1 > 2*n || a[pos] || a[pos+i+1]) continue;
        check[i] = 1;
        a[pos] = a[pos+i+1] = i;
        go();
        check[i] = 0;
        a[pos] = a[pos+i+1] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x >> y;
    a[x] = a[y] = y - x - 1;
    check[y-x-1] = 1;
    go();
    cout << ret;
}