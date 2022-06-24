#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 11;
int a[SIZE][SIZE];
int f[2*SIZE][SIZE][SIZE];

int N;
int main(){
	//67
	freopen("data.txt","r",stdin);
	cin >> N;
	int x,y,c;
	while(cin >> x >> y >> c && x||y||c){
		a[x][y] = c;
	}
	for(int k=2;k<=2*N;k++)
		for(int i1=1;i1<=N;i1++){
			for(int i2=1;i2<=N;i2++){
				int j1 = k-i1;
				int j2 = k-i2;
				if(j1>0 && j2>0 && j1<=N && j2<=N){
					int &p = f[k][i1][i2];
					int t = a[i1][j1];
					if(i1!=i2) t+=a[i2][j2];
					p = max(p,f[k-1][i1][i2]+t);
					p = max(p,f[k-1][i1-1][i2]+t);
					p = max(p,f[k-1][i1][i2-1]+t);
					p = max(p,f[k-1][i1-1][i2-1]+t);
				}
			}
		}
	cout << f[2*N][N][N] << endl;
	return 0;
}
