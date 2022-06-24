#include <cstdio>
#include <iostream>
using namespace std;
const int SIZE = 1010;
int a[SIZE];
int f[SIZE];
int N;
int ans;
int main(){
	freopen("data.txt","r",stdin);
	cin >> N;
	for(int i=0;i<N;i++) cin >> a[i];
	for(int i=0;i<N;i++){
		f[i] = a[i];
		for(int j=0;j<N;j++){
			if(a[j]<a[i])
				f[i] = max(f[i],f[j]+a[i]);
		}
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
	return 0;
}
