/*给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

  输入格式
  第一行包含整数 N。

  第二行包含 N 个整数，表示完整序列。

  输出格式
  输出一个整数，表示最大长度。

  数据范围
  1≤N≤1000，
  −109≤数列中的数≤109
  输入样例：
  7
  3 1 2 1 8 5 6
  输出样例：
  4
  */
#include <cstdio>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1005;
int n;
int d[N];
int f[N];
int ans;
int main(){
	freopen("data.txt","r",stdin);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> d[i];
	}
	for(int i=0;i<n;i++){
		f[i] = 1;
		for(int j=0;j<i;j++){
			if(d[j]<d[i])
				f[i] = max(f[i],f[j]+1);
		}
		ans = max(f[i],ans);
	}
	//for(int i=0;i<n;i++){
	//	cout << f[i] << " ";
	//}
	cout << ans << endl;
}
