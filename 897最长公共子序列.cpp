#include <cstdio>
#include <iostream>
using namespace std;

const int SIZE = 1010;
int N,M;

int a[SIZE];
int b[SIZE];
int dp[SIZE][SIZE];

int main(){
	//freopen("data.txt","r",stdin);
	cin >> N >> M;
	for(int i=1;i<=N;i++) cin >> a[i];
	for(int i=1;i<=M;i++) cin >> b[i];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			dp[i][j] = (max(dp[i-1][j],dp[i][j-1]));
			if(a[i]==b[j])
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
		}
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
