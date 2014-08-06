#include <iostream>
#include <vector>
#include <algorithm>
#define for0(i, N) for(int i = 0; i < (N); i++)
#define pb push_back
using namespace std;

int cs[10][100];
int path[10][100];
int R, C;


int main()
{
	while(!(cin >> ws).eof())
	{
		cin >> R >> C;
		for0(r, R)
		{
			for0(c, C)
			{
				cin >> cs[r][c];
			}
		}
		for(int c = C-2; c>=0; c--)
		{
			for(int r = 0; r < R; r++)
			{
				int nex, p;
				vector<int> t;
				t.pb(r);
				t.pb((r+1)%R);
				t.pb((r-1+R)%R);
				sort(t.begin(), t.end());
				
				p = t[0];
				nex = cs[p][c+1];
				for(int k = 1; k < t.size(); k++)
				{
					if (cs[t[k]][c+1] < nex)
					{
						nex = cs[t[k]][c+1];
						p = t[k];
					}
				}
				
				cs[r][c] = cs[r][c] + nex;
				path[r][c] = p;
			}
		}
		
		
		int small = cs[0][0];
		int lest = 0;
		for(int r = 1; r < R; r++)
		{
			if (small > cs[r][0])
			{
				small = cs[r][0];
				lest = r;
			}
		}
		cout << lest + 1;		
		for(int c = 0; c < C-1; c++)
		{
			cout << " " << path[lest][c] + 1;
			lest = path[lest][c];
		}
		
		cout << endl << small << endl;
	}	
}
