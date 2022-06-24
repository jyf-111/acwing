#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int N = 1e5+5;
constexpr int M = 2*N;

int h[N],e[M],ne[M],idx;
int w[M];
int n;
int ret;

int dfs(int u,int fa){
	int d1,d2;
	d1 = d2 = 0;
	for(int i=h[u];~i;i = ne[i]){
		int j = e[i];
		if(j==fa) continue;
		int d = dfs(j,u) + w[i];
		// maxn = max(maxn,d);	
		if(d>=d1){
			d2 = d1;
			d1 = d;
		}else if(d>d2){
			d2 = d;
		}
	}
	ret = max(ret,d1+d2);
	return d1;
}

void add(int a,int b,int c){
	e[idx] = b,w[idx] = c,ne[idx] = h[a], h[a] = idx++;
}
int main(){
	freopen("data.txt","r",stdin);
	memset(h,-1,sizeof h);	
	cin >> n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin >>a >> b >> c;
		add(a,b,c),add(b,a,c);
	}
	cout << dfs(1,-1) << endl;
	cout << ret << endl;
	return 0;
}
