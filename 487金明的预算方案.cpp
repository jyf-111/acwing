#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
int  N,m;
const int SIZE = 65;
int cnt = 0;
PII far[SIZE];
vector<PII> son[SIZE];
int dp[32005];

int main(){
	//freopen("data.txt","r",stdin);
	cin >> N >> m;
	for(int i=1;i<=m;i++){
		int v,p,q;
		cin >> v >> p >> q;
		if(!q){
			far[i] = {v,p};
			cnt++;

		}
		else
			son[q].push_back({v,p});
	}
	for(int i=1;i<=m;i++){
		if(far[i].first ==0 && far[i].second==0) continue;
		for(int j=N;j>=1;j--){
			int sz = son[i].size();
			for(int k=0;k< 1<<sz ;k++){
				int val = far[i].first,wei = far[i].first*far[i].second;
				for(int p = 0;p<sz;p++){
					if(k>>p & 1){
						val+=son[i][p].first;
						wei+=son[i][p].first*son[i][p].second;	
					}
				}
				if(j>=val){
					dp[j] = max(dp[j],dp[j-val]+wei);
				}
			}
		}
	} 
	cout << dp[N] << endl;
	return 0;
}
