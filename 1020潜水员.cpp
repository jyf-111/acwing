#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int m,n,num;
int f[5000][25][80];
int main(){
	freopen("data.txt","r",stdin);
	cin >> m >> n >> num;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=num;i++){
					f[i][0][0] = 0;
	}
	f[0][0][0] = 0;

	for(int i=1;i<=num;i++){
		int w1,w2,v;
		cin >> w1 >> w2 >> v;
		for(int j=m;j>0;--j){
			for(int k=n;k>0;--k){
				f[i][j][k] = min(f[i-1][j][k],f[i-1][max(0,j-w1)][max(0,k-w2)]+v);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout << f[5][i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
