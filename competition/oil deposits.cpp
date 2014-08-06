#include <iostream>

using namespace std;

int m, n;
bool oil[100][100];
vector< vector< bool > > vis(m, vector<bool>(n, false));

int main()
{
	
	cin >> m >> n;
	while(m != 0)
	{
		
		char temp;
		for ( int M = 0; M < m; M++)
		{
			for (int N = 0; N < n; N++)
			{
				cin >> temp;
				if (temp == '*')
				{
					oil[M][N] = false;
				}
				else
				{
					oil[M][N] = true;
				}
			}
		}
		for (int M = 0; M < m; M++)
		{
			for (int N = 0; N < n; N++)
			{
				if (!vis[M][N] && oil[M][N])
				{
					
				}
			}
		}	
		
		
		cin >> m >> n;
	}
}

