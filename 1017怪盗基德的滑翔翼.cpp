/*
   怪盗基德是一个充满传奇色彩的怪盗，专门以珠宝为目标的超级盗窃犯。
   假设城市中一共有N幢建筑排成一条线，给定这些建筑的高度，每幢建筑的高度各不相同。
   初始时，怪盗基德可以在任何一幢建筑的顶端。他可以选择一个方向逃跑，但是不能中途改变方向（因为中森警部会在后面追击）。
   因为滑翔翼动力装置受损，他只能往下滑行（即：只能从较高的建筑滑翔到较低的建筑）。
   他希望尽可能多地经过不同建筑的顶部，这样可以减缓下降时的冲击力，减少受伤的可能性。
   请问，他最多可以经过多少幢不同建筑的顶部（包含初始时的建筑）？

   输入格式：
   输入数据第一行是一个整数K，代表有K组测试数据。每组测试数据包含两行：第一行是一个整数N，代表有N幢建筑。
   第二行包含N个不同的整数，每一个对应一幢建筑的高度h，按照建筑的排列顺序给出。

   输出格式：
   对于每一组测试数据，输出一行，包含一个整数，代表怪盗基德最多可以经过的建筑数量。

   数据范围：
   1 ≤ K ≤ 100 
   1 ≤ N ≤ 100
   0 < h < 10000 
 * */
#include <cstdio>
#include <iostream>
using namespace std;
const int Size = 105;
int K;
int N;
int ans;
int d[Size];
int f[Size];
int g[Size];
int main(){
	freopen("data.txt","r",stdin);
	cin >> K;
	while(K--){
		ans = 0;
		cin >> N;
		for(int i=0;i<N;i++) cin >> d[i];
		for(int i=0;i<N;i++){
			f[i] = 1;
			for(int j=0;j<i;j++){
				if(d[j]<d[i]){
					f[i] = max(f[i],f[j]+1);
				}
			}
			ans = max(ans,f[i]);
		}

		for(int i=N-1;i>=0;i--){
			g[i] = 1;
			for(int j=N-1;j>i;j--){
				if(d[j]<d[i]){
					g[i] = max(g[i],g[j]+1);
				}
			}
			ans = max(ans,g[i]);
		}
		/*for(int i=0;i<N;i++){
		  cout << f[i] << " ";
		  }
		  cout << endl;

		  for(int j=0;j<N;j++){
		  cout << g[j] << " ";
		  }
		  cout << endl;
		  */
		cout << ans << endl;
	}
	return 0;
}
