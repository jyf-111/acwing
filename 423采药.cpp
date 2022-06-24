#include <cstdio>
#include <iostream>
using namespace std;
int T;
int M;
int dp[1005];

int main(){
	//freopen("data.txt","r",stdin);
	cin >> T >> M;
	for(int i=1,t,v;i<=M;i++){
		cin >> t >> v;
		for(int j=T;j>=t;j--){
			dp[j] = max(dp[j],dp[j-t]+v);
		}
	}
	cout << dp[T] << endl;
}
