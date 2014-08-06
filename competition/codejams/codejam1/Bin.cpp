#include <iostream>
#include <vector>
#include <algorithm>
#define for0(i, N) for (int i = 0; i < (N); ++i)
using namespace std;

int main()
{
	cout << 100 << endl;
	for0(n, 100)
	{
		cout << 100 << " ";
		cout << 75 << " " << 5;
		for0(m, 100)
		{
			cout << " " << m/10 * 3;
		}		
		cout << endl;
	}
}
