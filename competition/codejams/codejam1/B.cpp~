#include <iostream>
#include <vector>
#include <algorithm>
#define for0(i, N) for (int i = 0; i < (N); ++i)
using namespace std;

int main()
{
	int M;
	cin >> M;
	for0(n, M)
	{
		int N, S ,p, count = 0;
		cin >> N >> S >> p;
		vector<int> ls;
		vector<int> l0;
		vector<int> l2;
		for0(i, N)
		{
			int k;
			cin >> k;
			ls.push_back(k);
		}		
		sort(ls.begin(), ls.end());		
		while(!ls.empty())
		{
			int k = ls.back();
			ls.pop_back();
			if (k%3 == 1)
			{
				if((k / 3 + 1) >= p)
				{
					count++;
				}
			}
			else if (k % 3 == 0)
			{
				if(k/3 >= p)
				{
					count++;
				}
				else
				{
					if (k != 0)
						l0.push_back(k);
				}
			}
			else if (k % 3 == 2)
			{
				if(k/3 + 1 >= p)
				{
					count++;
				}
				else
				{
					l2.push_back(k);
				}
			}			
		}
		cout << "Case #" << n +1 << ": ";
		sort(l0.begin(), l0.end());		
		sort(l2.begin(), l2.end());		
		while(S > 0 && l2.size() > 0)
		{
			int k = l2.back() / 3 ;
			l2.pop_back();
			if ((k + 2 >= p) && (k + 2 < 11))
			{
				count++;
				S--;
			}
			else
			{
				break;
			}
		}
		while(S > 0 && l0.size() > 0)
		{
			int k = l0.back() / 3 ;
			l0.pop_back();
			if (k + 1 >= p)
			{
				count++;
				S--;
			}
			else
			{
				break;
			}
		}
		cout << count << endl;
	}
}
