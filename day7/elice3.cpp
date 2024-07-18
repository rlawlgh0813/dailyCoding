#include <iostream>
#include <stack>
using namespace std;
stack<char> stk;
int len;
string s;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for(auto cur : s){
        if(cur != ')') stk.push(cur);
        else{
            while(stk.size() && stk.top() != '('){ stk.pop(), len++; }
            stk.pop();
            len *= stk.top()-'0';
            stk.pop();
        }
    }
    cout << len + stk.size();
} 