#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int N,V;
const int SIZE = 10005;
int dp[SIZE];

struct Stone{
	int s,e,l;
	bool operator<(const Stone& w){
		return l*w.s > s*w.l; 
	}
}stone[SIZE];
int main(){
	cin >> T;
	for(int t=1;t<=T;t++){
		cin >> N;
		V = 0;
		memset(dp,-0x3f,sizeof dp);
		dp[0] = 0;

		for(int i=1;i<=N;i++){
			cin >> stone[i].s >> stone[i].e >> stone[i].l;
			V+= stone[i].s;
		}
		sort(stone+1,stone+1+N);
		for(int i=1;i<=N;i++){
			int s = stone[i].s;
			int e = stone[i].e;
			int l = stone[i].l;
			for(int j=V;j>=s;j--){
				dp[j] = max(dp[j],dp[j-s]+e-l*(j-s));
			}
		}
		int res = 0;
		for(int i=0;i<=V;i++){
			res = max(res,dp[i]);
		}
		cout <<"Case #" << t << ": " <<  res << endl;
	}
	return 0;
}
