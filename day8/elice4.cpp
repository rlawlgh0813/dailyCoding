#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long ll;
const int INF = 100004;
int n, mx;
int vis[INF];
ll depth[INF];
vector<ll> t[INF], adj[INF];

bool cmp(ll a, ll b){
    if(depth[a] != depth[b]) return depth[a] > depth[b];
    return a > b;
}

ll dfs(int here){
    ll ret = 0;
    for(auto there : adj[here]) ret = dfs(there) + 1;
    return ret;
}

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
    for(int i=1; i<=n; i++) depth[i] = dfs(i);
    for(int i=1; i<=n; i++) sort(adj[i].begin(), adj[i].end(), cmp);
}

int solve(int start){
    int ret[2] = {0,0}, order = 0;
    queue<pair<int,int>> q;
    q.push({order,start});

    while(q.size()){
        auto here = q.front(); q.pop();
        
        ret[here.first] += here.second;
        order = (order == 1) ? 0 : 1;
        if(adj[here.second].size()) q.push({order,adj[here.second][0]});
    }
    return (ret[0] >= ret[1]) ? 1 : 0;
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
    for(int i=1; i<=n; i++) cout << solve(i) << '\n';
}
