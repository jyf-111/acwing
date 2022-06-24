#include "iostream"
#include <cstdio>
using namespace std;
int N,V;
int dp[1005];
int g[1005];
int main(){
	// freopen("data.txt","r",stdin);
	cin >> N >> V;
	g[0] = 1;
	for(int i=1;i<=N;i++){
		int v,w;
		cin >> v >> w;
		for(int j=V;j>=1;j--){
			int a = dp[j];
			int b = -1;
			if(j>=v){
				b = dp[j-v]+w;
				if(a==b) g[j] = (g[j] + g[j-v])%(int)(1e9+7);
					else if(a<b) g[j] = g[j-v];
				dp[j] = max(a,b);
			}
		}
	}
	int res = 0;
	for(int i=1;i<=V;i++){
		res = max(res,dp[i]);
	}
	int cnt = 0;
	for(int i=0;i<=V;i++){
		if(res == dp[i]){
			cnt = (cnt+g[i])%(int)(1e9+7);
		}
	}
	cout << cnt << endl;
	return 0;
}
