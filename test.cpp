#include <iostream>
#include <thread>
using namespace std;
int main (int argc, char *argv[])
{
	std::jthread j(
		[]{
				cout << "hi";
			}
	);
	j.join();
	cout << "hello world" << endl;
	return 0;
}
