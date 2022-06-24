#include <cstdio>
#include <iostream>
using namespace std;
int N,V;
const int SIZE = 1005;

int dp[SIZE];
int v,w,s;
int main(){
	//freopen("data.txt","r",stdin);
	cin >> N >> V;
	for(int i=1;i<=N;i++){
		cin >> v >> w >> s;	
		if(s==0){//完全背包
			for(int j=v;j<=V;j++){
				dp[j] = max(dp[j],dp[j-v]+w);
			}
		}else{
			if(s==-1) {
				s=1;
			}  {
				for(int k=1;k<=s;k*=2){
					for(int j=V;j>=k*v;j--){
						dp[j] = max(dp[j],dp[j-k*v]+k*w);
					}
					s-=k;
				}
				if(s){
					for(int j=V;j>=s*v;j--){
						dp[j] = max(dp[j],dp[j-s*v]+s*w);
					}
				}
			}
		}
	}
	cout << dp[V] << endl;
}
