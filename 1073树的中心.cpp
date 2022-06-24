#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int N = 1e4+5, M = 2*N;

int h[N],e[M],ne[M],idx,w[M];

int d1[N],d2[N],p1[N],up[N];

int dfs_d(int u,int father){
	d1[u] = d2[u] = 0;
	for(int i=h[u];~i;i = ne[i]){
		int j = e[i];
		if(father == j) continue;
		int d = dfs_d(j,u)+w[i];
		if(d>=d1[u]){
			d2[u] = d1[u];
			d1[u] = d;
			p1[u] = j;
		}else if(d>d2[u]){
			d2[u] = d;
		}
	}
	return d1[u];
}

 void dfs_u(int u,int father){
	for(int i=h[u];~i;i = ne[i]){
		int j = e[i];
		if(j==father) continue;
		if(j==p1[u]){
			up[j] = max(up[u],d2[u])+w[u];
		}else{
			up[j] = max(up[u],d1[u])+w[u];
		}
		dfs_u(j,u);
	}	
}

void add(int a,int b,int c){
	w[idx] = c,e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

int main (int argc, char *argv[])
{
	freopen("data.txt","r",stdin);
	int n;
	memset(h,-1,sizeof h);
	cin >> n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c),add(b,a,c);
	}

	cout <<dfs_d(1,-1)<<endl;

	dfs_u(1,-1);
	int res = 0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		res = min(res,max(d1[i],up[i]));
	}
	cout << res << endl;
	return 0;
}
