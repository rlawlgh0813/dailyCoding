#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll sz[51];

ll go(int lev, ll pos){
    if(lev == 0) return 1;

    if(pos == 1) return 0;
    else if(pos < sz[lev-1] + 2) return go(lev-1, pos-1);
    else if(pos == sz[lev-1] + 2) return 1 + go(lev-1, pos-2);
    else if(pos < sz[lev]) return 1 + go(lev-1, sz[lev-1]) + go(lev-1, pos-sz[lev-1]-2);
    else if(pos == sz[lev]) return 1 + 2*go(lev-1, sz[lev-1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    sz[0] = 1;
    for(int i=1; i<51; i++) sz[i] = 2 * sz[i-1] + 3;
    cout << go(n,k);
}