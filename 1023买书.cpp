#include <cstdio>
#include <iostream>
using namespace std;
int n;
int a[5] = {0,10,20,50,100};
const int N = 1005;
int dp[N];

int main(){
	cin >> n;
	dp[0] = 1;
	for(int i=1;i<5;i++){
		for(int j=a[i];j<=n;j++){
			dp[j] += dp[j-a[i]];
		}
	}
	for(int i=0;i<=4;i++){
		for(int j=0;j<=n;j++){
			cout << dp[j] << " ";
		}
		cout << endl;
	}
	cout << dp[n] << endl;
	return 0;
}
