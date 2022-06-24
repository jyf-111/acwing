#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 5005;
typedef pair<int,int> PPI;
int ans;
int N;
PPI v[SIZE];
int f[SIZE];
int main(){
	//freopen("data.txt","r",stdin);
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> v[i].first >> v[i].second;
		//cout << v[i].first << " " << v[i].second << endl;
	}

	sort(begin(v),begin(v)+N);
	for(int i=0;i<N;i++){
		f[i] = 1;
		for(int j=0;j<i;j++){
			if(v[j].second < v[i].second){
				f[i] = max(f[i],f[j]+1);
			}
			ans = max(ans,f[i]);
		}
	}	
	cout << ans << endl;
	return 0;
}

