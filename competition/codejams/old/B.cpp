#include <iostream>
#define for1(a,b) for (int a = 0; a < b; a++) 

using namespace std;

int main()
{
	int T;
	cin >> T;
	char B[100][100];
	for1(t, T)
	{
		int N, M;
		cin >> N >> M;
		for1(n,N)
		{
			for1(m,M)
			{
				cin >> B[n][m];
			}
		}
		bool poss = true;
		for1(n,N)
		{
			for1(m,M)
			{
				int a = B[n][m];
				bool H = true, V = true;
				//H
				for1(x,M)
				{
					if (B[n][x] > a)
					{
						H = false;
						break;
					}
				}		
				//V
				if (!H)
				{ 
				for1(y,N)
				{
					if (B[y][m] > a)
					{
						V = false;
						break;
					}
				}
				}
				if (!H  && !V)
				{
					poss = false;
					break;
				}
			}
			if (!poss)
				break;
		}
		cout << "Case #" << t+1 << ": ";
		cout << ((poss)?"YES":"NO") << endl;
	}
}
