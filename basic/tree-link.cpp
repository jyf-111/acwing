#include "iostream"
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 10;
const int M = 10;
int h[N],e[M],ne[M],index;

void add(int a,int b) //a->b
{
	e[index] = b,ne[index] = h[a] , h[a] = index++;
}
int vis[N];
void dfs(int root){
	for(int i=h[root];~i;i = ne[i]){
		if(!vis[e[i]]){
			cout << e[i] << endl;
			vis[e[i]]=1;
			dfs(e[i]);
		}
	}
}
int main(){
	freopen("../data.txt","r",stdin);
	memset(h,-1,sizeof h);
	int num ;
	cin >> num;
	for(int i=1;i<=num;i++){
		int a,b;
		cin >> a >> b;
		add(a,b);
	}
	for(int i=0;i<index;i++){
		cout << e[i] << " ";
	}
	cout << endl;
	for(int i=0;i<index;i++){
		cout << ne[i] << " ";
	}
	cout << endl;

	for(int i=0;i<index;i++){
		cout << h[i] << " ";
	}
	cout << endl;

	// for(int i=h[1];~i;i=ne[i]){
	// 	cout << e[i] << endl;
	// }
	int root = 1;
	dfs(root);
	return 0;
}
