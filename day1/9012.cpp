#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    while(n--){
        stack<char> stk;
        string s;
        int flag = 0;
        
        cin >> s;
        for(char c : s){
            if(flag) break;
            if(c == '('){
                stk.push(c);
            }
            else{
                if(stk.empty() || stk.top() != '('){
                    flag = 1;
                    break;
                }
                stk.pop();
            }
        }
        if(stk.size()) flag = 1;

        if(flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}