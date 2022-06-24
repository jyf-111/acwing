#include <cstdio>
#include <iostream>
using namespace std;
int N,M;
int dp[105][10005];

int main(){

	//freopen("data.txt","r",stdin);
	cin >> N >> M;

	for(int i=0;i<=N;i++){
		dp[i][0] = 1;
	}
	for(int i=1;i<=N;i++){
		int num;
		cin >> num;
		for(int j=1;j<=M;j++){
			dp[i][j] = dp[i-1][j];
			if(j>=num)
				dp[i][j] += dp[i-1][j-num];
		}
	}
	cout << dp[N][M] << endl;
}
