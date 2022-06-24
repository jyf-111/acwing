#include <cstdio>
#include <iostream>
using namespace std;
const int Size = 105;
int K;
int N;
int ans;
int d[Size];
int f[Size];
int g[Size];
int main(){
	freopen("data.txt","r",stdin);
	ans = 0;
	cin >> N;
	for(int i=0;i<N;i++) cin >> d[i];
	for(int i=0;i<N;i++){
		f[i] = 1;
		for(int j=0;j<i;j++){
			if(d[j]<d[i]){
				f[i] = max(f[i],f[j]+1);
			}
		}
	}

	for(int i=N-1;i>=0;i--){
		g[i] = 1;
		for(int j=N-1;j>i;j--){
			if(d[j]<d[i]){
				g[i] = max(g[i],g[j]+1);
			}
		}
	}
	for(int i=0;i<N;i++){
		ans = max(ans,f[i]+g[i]);
	}
	cout << N-ans+1 << endl;
	return 0;
}
