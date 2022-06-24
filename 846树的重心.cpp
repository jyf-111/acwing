#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5+5;
int h[N],e[N],ne[N],index;
int n;
bool vis[N];
int ret = N;

void add(int a,int b){
	//a->b
	e[index] = b,ne[index] = h[a],h[a] = index++;
}
//root size
int dfs(int root){
	vis[root] = true;
	int ans = 0;
	int sum = 1;
	for(int i = h[root];~i;i = ne[i]){
		if(!vis[e[i]]){
			// cout << e[i]<< endl;
			int d = dfs(e[i]);
			ans = max(ans,d);
			sum+=d;
		}
		ans =  max(ans,n-sum);
		ret = min(ret,ans);
	}
	return sum;
}
int main (int argc, char *argv[])
{
	freopen("data.txt","r",stdin);
	memset(h,-1,sizeof h);
	cin >> n;
	for(int i = 1;i<=n;i++){
		int a,b;
		cin >> a >> b;
		add(a,b),add(b,a);
	}
	dfs(1);
	cout << ret << endl;
	return 0;
}
