#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int T,n;
const int SIZE = 25005;
int dp[SIZE];
int num[SIZE];
int main(){
	// freopen("data.txt","r",stdin);
	cin >> T;
	while(T--){
		memset(dp,0,sizeof dp);
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> num[i];
		}
		sort(num+1,num+n+1);
		dp[0] = 1;
		int res = 0;
		for(int i=1;i<=n;i++){
			if(dp[num[i]]==0) res++; 
			for(int j=num[i];j<=num[n];j++){
				dp[j] += dp[j-num[i]];
			}
		}
		cout << res << endl;
	}
	return 0;
}
