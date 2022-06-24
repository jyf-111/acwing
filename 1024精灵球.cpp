#include <cstdio>
#include <iostream>
using namespace std;
const int SIZE = 105;
int N,M,K;
int dp[SIZE][SIZE];

int main(){
	freopen("data.txt","r",stdin);
	cin >> N >> M >> K;
	for(int k=1,v1,v2;k<=K;k++){
		cin >> v1 >> v2;
		for(int n=N;n>=v1;--n){
			for(int m=M-1;m>=v2;--m){
				if(n>=v1 && m>=v2)
				dp[n][m] = max(dp[n][m],dp[n-v1][m-v2]+1);
			}
		}
	}	
	cout << dp[N][M-1] << endl;
	int k = M-1;
	while(k>0 && dp[N][k-1]==dp[N][M-1]) k--;
	cout << M-k << endl;
}
