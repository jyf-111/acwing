#include <cstdio>
#include <iostream>
using namespace std;
const int SIZE = 3003;
int a[SIZE],b[SIZE];
int N;
int dp[SIZE][SIZE];
int main(){
	//freopen("data.txt","r",stdin);
	cin >> N;
	for(int i=1;i<=N;i++) cin >> a[i];
	for(int i=1;i<=N;i++) cin >> b[i];
	for(int i=1;i<=N;i++){
		int maxv = 0;
		for(int j=1;j<=N;j++){
			dp[i][j] = dp[i-1][j];
			if(a[i]==b[j]){
				dp[i][j] = max(dp[i][j],maxv+1);
			}
			if(b[j]<a[i])
				maxv = max(maxv,dp[i-1][j]);
		}
	}
	int ans= 0;
	for(int i=1;i<=N;i++)
		ans = max(ans,dp[N][i]);

	/*for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << ans << endl;
}
