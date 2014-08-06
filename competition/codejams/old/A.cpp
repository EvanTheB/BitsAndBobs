#include <iostream>
#define for1(a,b) for (int a = 0; a < b; a++) 

using namespace std;

int main()
{
	int T;
	cin >> T;
	char B[4][4];
	for1(t, T)
	{
		bool done = true;
		char win = 0;
		for1(x,4)
		{
			for1(y,4)
			{
				cin >> B[x][y];
				if (B[x][y] == '.')
					done = false;
			}
		}
		//h
		for1(y,4)
		{
			char c = B[0][y];
			if (c == 'T')
				c = B[1][y];
			if (c == '.') continue;
			
			for1(x,4)
			{
				if (!(B[x][y] == c || B[x][y] == 'T'))
					break;
				if (x==3)
					win = c;
			}
		}
		
		//v
		for1(x,4)
		{
			char c = B[x][0];
			if (c == 'T')
				c = B[x][1];
							if (c == '.') continue;
			for1(y,4)
			{
				if (!(B[x][y] == c || B[x][y] == 'T'))
					break;
				if (y==3)
					win = c;
			}
		}
		
		//d
		char c = B[0][0];
			if (c == 'T')
				c = B[1][1];
				
		for1 (x,4)
		{
						if (c == '.') break;
			if (!(B[x][x] == c || B[x][x] == 'T'))
					break;
				if (x==3)
					win = c;
		}
		
		c = B[3][0];
			if (c == 'T')
				c = B[2][1];
		for1 (x,4)
		{
					if (c == '.') break;
			if (!(B[3-x][x] == c || B[3-x][x] == 'T'))
					break;
				if (x==3)
					win = c;
		}
		cout << "Case #" << t+1 << ": ";
		if (win)
			cout << win << " won" << endl;
		else if (done)
			cout << "Draw" << endl;
		else 
			cout << "Game has not completed" << endl;
	}
}
