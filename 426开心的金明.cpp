#include <iostream>
using namespace std;
int N;int m;
int dp[30005];

int main(){
	freopen("data.txt","r",stdin);
	cin >> N >> m;
	for(int i=1;i<=m;i++){
		int v,w;
		cin >> v >> w;
		for(int j=N;j>=v;j--){
				dp[j] = max(dp[j],dp[j-v]+v*w);
		}
	}
	cout << dp[N] << endl;
}
