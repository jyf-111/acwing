#include "iostream"
#include <algorithm>
#include <cmath>
using namespace std;
const int SIZE = 105;
int dp[SIZE];
int main (int argc, char *argv[])
{
	//freopen("data.txt","r",stdin);
	int N,V;
	cin >> N >> V;
	for(int i=1;i<=N;i++){
		int S;
		cin >> S;
		int v[SIZE],w[SIZE];
		for(int j=1;j<=S;j++){
			cin >> v[j] >> w[j];
		}
		for(int j=V;j>=1;j--){
			for(int k=S;k>=1;k--){
				if(j>=v[k])
				dp[j] = max(dp[j],dp[j-v[k]]+w[k]);
			}
		}
	}
	/*for(int i=1;i<=N;i++){
		for(int j=1;j<=V;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[V] << endl;
}
