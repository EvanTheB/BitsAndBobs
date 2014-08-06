#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> ar((1<<6), 0);
	ar[10] = 1;
	for(int i = 1; i < (1<<6); i++)
	{
		ar[i] = ar[i^(i&(-i))];
	}
	for(int i = 0; i < (1<<6); i++)
	{
		cout << ar[i] << endl;
	}
}
