#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
int n, temp, pos, mn = INF, mx = -INF;
int num[14];
vector<int> oper;

void go(vector<int> v){
    int cnt = num[0];
    for(int i=0; i<v.size(); i++){
        if(v[i] == 1) cnt += num[i+1];
        else if(v[i] == 2) cnt -= num[i+1];
        else if(v[i] == 3) cnt *= num[i+1];
        else if(v[i] == 4){
            if(cnt < 0) cnt = -((-cnt) / num[i+1]);
            else cnt /= num[i+1];
        }
    }
    mn = min(cnt, mn);
    mx = max(cnt, mx);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> num[i];
    for(int i=0; i<4; i++){
        cin >> temp;
        for(int j=0; j<temp; j++) oper.push_back(i+1);
    }

    do{
        go(oper);
    }while(next_permutation(oper.begin(), oper.end()));
    cout << mx << '\n' << mn;
}