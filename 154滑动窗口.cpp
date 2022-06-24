#include <cstdio>
#include <iostream>
using namespace std;
int n,k;
const int N = 1e6+5;
int a[N],g[N];

int main(){
	//freopen("data.txt","r",stdin);
	cin >> n >> k;
	int hh=0,tt=-1;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(hh<=tt && g[hh] < i-k+1) hh++;
		while(hh<=tt && a[g[tt]]>=a[i]) tt--;
		g[++tt] = i;
		if(i>=k-1)
		
		cout << a[g[hh]] << " ";
	}
	puts("");
	hh=0;
	tt=-1;
	for(int i=0;i<n;i++){
		if(hh<=tt && g[hh]<i-k+1) hh++;	
		while(hh<=tt && a[g[tt]]<=a[i]) tt--;
		g[++tt]=i;
		if(i>=k-1) cout << a[g[hh]] << " ";
	}
	return 0;
}
