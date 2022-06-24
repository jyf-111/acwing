#include <cstdio>
#include <iostream>
using namespace std;

int n,m;
int dp[6006];

int main(){
	freopen("data.txt","r",stdin);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int v,w,num;
		cin >> v >> w >> num;
		for(int j=m;j>=1;j--){
			for(int k=0;k<=num;k++){
				if(j>=k*v)
					dp[j]= max(dp[j],dp[j-k*v]+k*w);
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
