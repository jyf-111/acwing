#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,R,C;
const int N = 105;
int f[N][N];
int a[N][N];

int main(){
	//freopen("data.txt","r",stdin);
	cin >> T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		cin >> R >> C;
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				cin >> a[i][j];
			}
		}
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				f[i][j] = a[i][j] + max(f[i-1][j],f[i][j-1]);
			}
		}
		cout << f[R][C] << endl;
	}
	return 0;
}
