#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 6005;
vector<int> ne[SIZE];
bool h[SIZE];//有父节点
int N;
int w[SIZE];
int root;
int f[SIZE][2];
void add(int a,int b){
	ne[a].push_back(b);
}
void dfs(int root){
	f[root][0] = 0;//not select
	f[root][1] = w[root];//select
	for(int i=0;i<ne[root].size();i++){
		dfs(ne[root][i]);
		f[root][0]+=max(f[ne[root][i]][0],f[ne[root][i]][1]);
		f[root][1]+=f[ne[root][i]][0];
	}

}
int main(){
	// freopen("data.txt","r",stdin);
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> w[i];
	}
	for(int i=1;i<=N-1;i++){
		int a,b;
		cin >> a >> b;
		add(b,a);
		h[a] = true;
	}
	// for(int i=1;i<=N;i++){
	// 	cout << i << ":" ;
	// 	for(auto j:ne[i]){
	// 		cout << "("<< j.first << " " << j.second <<")";
	// 	}
	// 	cout << endl;
	// }
	for(int i=1;i<=N;i++){
		if(!h[i]){
			root = i;
			break;
		}
	}
	dfs(root);
	cout << max(f[root][0],f[root][1]) << endl;
}
