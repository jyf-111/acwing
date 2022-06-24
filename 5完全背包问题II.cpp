#include <cstdio>
#include <iostream>
using namespace std;
const int N = 11000;
int v[N],w[N],s[N];
int f[2020];

int main(){
	int n,m;
	//freopen("data.txt","r",stdin);
	cin >> n >> m;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		int a,b,s;
		int k = 1;
		cin >> a >> b >> s;
		//cout << "split " << a << " " << b << " " << s << endl;
		while(k<=s){
			cnt++;
			v[cnt] = k*a;
			w[cnt] = k*b;
			//cout <<"current k = " << k << endl << v[cnt] << " " << w[cnt] << endl;
			s-=k;
			k*=2;
		}
		if(s>0){
			cnt++;
			v[cnt] = s*a;
			w[cnt] = s*b;
			//cout <<"current s = " << s << endl << v[cnt] << " " << w[cnt] << endl;
		}
		//cout << "------------------------" << endl;
	}
	n = cnt;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=v[i];j--){
			f[j] = max(f[j],f[j-v[i]]+w[i]);
		}
	}
	cout << f[m] << endl;
	return 0;
}
