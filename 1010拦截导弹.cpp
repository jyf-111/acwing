#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1010;
int a[N];
int f[N],g[N];
int ans;
int binary_search(int left,int len,int target){
	while(left < len){
		int mid = left + ((len-left) >> 2);
		if(g[mid]>=target){
			len = mid;
		}else{
			left = mid+1;
		}
	}
	return len;
}
int main(){
	freopen("data.txt","r",stdin);
	int size = 0;
	while(cin >> a[size]){
		size++;
	}
	for(int i=0;i<size;i++){
		f[i] = 1;
		for(int j=0;j<i;j++){
			if(a[j]>a[i]){
				f[i] = max(f[i],f[j]+1);
			}
			ans = max(ans,f[i]);
		}
	}
	cout << ans << endl;
	//第二问
	g[0] = a[0];
	int cnt = 1;
	for(int i=1;i<size;i++){
		int p = binary_search(0, cnt, a[i]); 
		if(p==cnt) g[cnt++] = a[i];
		else g[p] = a[i];
	}
	cout << cnt << endl;
	return 0;
}
