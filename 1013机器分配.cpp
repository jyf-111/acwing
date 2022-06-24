#include <iostream>
using namespace std;
int N,M;
int w[20][20];
int f[20][20];

int main(){
	freopen("data.txt", "r", stdin);
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> w[i][j];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			f[i][j] = f[i-1][j];
			for(int k=1;k<=j;k++){
				f[i][j] = max(f[i][j],f[i-1][j-k] + w[i][k]); 
			}
		}
	}

	cout << f[N][M] << endl;
	int way[20];
	for(int i=N,j=M;i>0;i--){
		for(int k=0;k<=j;k++){
			if(f[i][j] == f[i-1][j-k]+w[i][k]){
				way[i] = k;
				j-=k;
				break;
			}
		}
	}
	for(int i=1;i<=N;i++){
		cout << way[i] << endl;
	}
	return 0;
}
