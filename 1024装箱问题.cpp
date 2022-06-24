#include <cstdio>
#include <iostream>
using namespace std;

int V,n;
int dp[20005];

int main(){
	//freopen("data.txt","r",stdin);
	cin >> V >> n;
	for(int i=1,v;i<=n;i++){
		cin >> v;
		for(int j=V;j>=v;--j){
			dp[j] = max(dp[j],dp[j-v]+v);
		}
	}
	cout << V-dp[V] << endl;
}
