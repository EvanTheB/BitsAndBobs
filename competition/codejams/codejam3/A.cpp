#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define for0(i, N) for(int i = 0; i < (N); i++)
#define pb push_back
#define vec1(type) vector<type>
#define vec2(type) vector< vec1(type) >

using namespace std;

int main()
{
	int kases;
	cin >> kases;	
	for0(kase, kases)
	{
		int N;
		cin >> N;
		vector<int> sc(N, 0);
		int sum = 0;
		for0(n, N)
		{
			cin >> sc[n];
			sum += sc[n];
		}
		for0(n, N)
		{
			vector<int> ss = sc;
			ss[n].
		}
	}
}

