#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 105;
int N,V;
int v[SIZE],w[SIZE],q;
int dp[SIZE][SIZE];
vector<int> vec[SIZE];

void dfs(int u){
	for(int j=v[u];j<=V;j++){
		dp[u][j] = w[u];
	}
	int size = vec[u].size();
	for(int i=0;i<size;i++){
		int son = vec[u][i];
		dfs(son);
		for(int j=V;j>=v[u];j--){
			for(int k=0;k<=j-v[u];k++){
				dp[u][j] = max(dp[u][j],dp[u][j-k]+dp[son][k]);
			}
		}
	}
}

int root;
int main(){
	//freopen("data.txt","r",stdin);
	cin >> N >> V;
	for(int i=1;i<=N;i++){
		cin >> v[i] >> w[i] >> q;
		if(q==-1){
			root = i;
		}else{
			vec[q].push_back(i);
		}
	}
	dfs(root);
	cout << dp[root][V] << endl;
	return 0;
}
