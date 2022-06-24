#include <iostream>
using namespace std;
const int SIZE = 100010;
int a[SIZE],f[SIZE];
int N;

int binary_search(int left,int len,int target){
	while(left < len){
		int mid = left + ((len-left)>>2);
		if(f[mid]>=target) len = mid;
		else left = mid+1;
	}
	return len;
}
int main(){
	freopen("data.txt","r",stdin);
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	f[0] = a[0];
	int len = 1;
	for(int i=1;i<N;i++){
		int index = binary_search(0, len, a[i]);
		if(index==len) f[++len] = a[i];
		else f[index] = a[i];
	}
	cout << len << endl;
	return 0;
}
