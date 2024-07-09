#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int Answer;

bool vis[300001];
vector<int> v[300004];

int go(int here){
    if(vis[here]) return 0;
    vis[here] = 1;
    int ret = 0;
    for(auto there : v[here]){
        if(vis[there] || v[there].size() & 1) continue;
        ret += go(there) + 1;
        break;
    }
    return ret;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n,a,b,start=0,node1,node2, sum1=0, sum2=0;

        cin >> n;
        for(int i=0; i<=n; i++){
            cin >> a >> b; 
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1; i<=n; i++){
            if(v[i].size() & 1){
                start = i;
                break;
            }
        }
        node1 = go(start);
        if(node1 & 1) sum1 = (node1+1) / 2 * (node1);
        else sum1 = (node1) / 2 * (node1+1);
        node2 = n - node1 - 2;
        if(node2 & 1) sum2 = (node2+1) / 2 * (node2);
        else sum2 = (node2) / 2 * (node2+1);
        Answer = sum1 + sum2;

        for(int i=1; i<=n; i++) v[i].clear();
        memset(vis, 0, sizeof(vis));
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}