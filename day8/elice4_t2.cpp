#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 100004;
int n,flag;
int vis[INF],depth[INF];
vector<int> t[INF], adj[INF], v;

void make_tree(int start){
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while(q.size()){
        int here = q.front(); q.pop();
        for(auto there : t[here]){
            if(vis[there]) continue;
            vis[there] = 1;
            adj[here].push_back(there);
            q.push(there);
        }
    }
}

void dfs(int start){
    if(adj[start].size() == 0){
        v.push_back(start);
        int order = 0;
        int ret[2] = {0,0};
        for(auto here : v){
            ret[order] += here;
            order = (order == 0) ? 1 : 0;
        }
        if(ret[0] >= ret[1]) flag = 1;
        v.pop_back();
    }
    for(auto there : adj[start]){
        v.push_back(start);
        dfs(there);
        v.pop_back();
    }
}

void solve(){
    for(int i=1; i<=n; i++){
        flag = 0;
        dfs(i);
        if(flag) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b; cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    make_tree(1);
    solve();
}
