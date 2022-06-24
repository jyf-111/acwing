#include <cstdio>
#include <iostream>
using namespace std;
const int N = 505;
int f[N][N];
int n;
int main(){
	//freopen("data.txt","r",stdin);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin >> f[i][j];
		}
	}
	for(int i=n-1;i>0;i--){
		for(int j=i;j>0;j--){
			f[i][j] += max(f[i+1][j],f[i+1][j+1]);
		}
	}
	cout << f[1][1] << endl;
}
