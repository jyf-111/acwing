#include <cstdio>
#include <iostream>
using namespace std;

int n,m;
int dp[3005];

int main(){
	freopen("data.txt","r",stdin);
	cin >> n >> m;
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		int v;
		cin >> v;
		for(int j=v;j<=m;j++){
			dp[j] = dp[j] + dp[j-v];
		}
	}
	for(int j=1;j<=m;j++)
		cout << dp[j] << " ";
}
