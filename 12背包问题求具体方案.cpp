#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int N,V;
const int SIZE = 1005;
int f[SIZE][SIZE];
int v[SIZE],w[SIZE];
int main(){
	//freopen("data.txt","r",stdin);
	cin >> N >> V;
	for(int i=1;i<=N;i++) cin >> v[i] >> w[i];
	for(int i=N;i>=1;--i){
		for(int j=0;j<=V;++j){
			f[i][j] = f[i+1][j];
			if(j>=v[i])
				f[i][j] = max(f[i][j],f[i+1][j-v[i]]+w[i]);
		}
	}
	int vol = V;
	for(int i=1;i<=N;++i){
		if(f[i][vol]==f[i+1][vol-v[i]]+w[i] && vol>=v[i]){
			cout << i << " ";
			vol-=v[i];
		}
	}
	return 0;
}
