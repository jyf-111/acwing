#include <cstdio>
#include <iostream>
using namespace std;
const int SIZE = 105;
int N,V,M;
int dp[SIZE][SIZE];

int main(){
	// freopen("data.txt","r",stdin);
	cin >> N >> V >> M;
	for(int i=1;i<=N;i++){
		int v,m,w;
		cin >> v >> m >> w;
		for(int j=V;j>=v;j--){
			for(int k=M;k>=m;k--){
					dp[j][k] = max(dp[j][k],dp[j-v][k-m]+w);
			}
		}
	}
	cout << dp[V][M] << endl;
}
