#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,p,q,k;
int a[10004];

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    while(m--){
        cin >> p >> q >> k;
        vector<int> v;
        for(int i=p-1; i<q; i++) v.push_back(a[i]);
        sort(v.begin(), v.end());
        cout << v[k-1];
    }
}