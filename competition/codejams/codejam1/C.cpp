#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#define for0(i, N) for (int i = 0; i < (N); ++i)
using namespace std;

int main()
{
	int N;
	cin >> N;
	for0(n, N)
	{
		int A, B;
		cin >> A >> B;
		
		stringstream ss;
		ss << A;
		string s = ss.str();
		int len = s.size();
		int count = 0;
		for( int cur = A; cur < B; cur++)
		{
			
			//cout <<C<<endl;
			int C = cur;
			vector<int> found;
			for0(m, len - 1)
			{
				int pop = C%10;
				if (pop == 0)
				{
					C = C/10;
					continue;
				}
				C = C/10 + pop * pow(10, len - 1);
				if (C > cur && C <= B)
				{
					
					bool yep = true;
					for0(i, found.size())
					{
						if (C == found[i])
						{
							yep = false;	
						}
					}
					if(yep)
					{
						count++;
						
						found.push_back(C);
					}
				}
				
			}
			
		}
		cout << "Case #" << n + 1 << ": ";
		cout << count << endl;
		
	}
}
