#include <vector>
#include <iostream>
#include <string>
#define for0(i, N) for(int i = 0; i < (N); i++)
using namespace std;

int main()
{
	cin >> ws;
	while(!cin.eof())
	{
		string a, b;
		getline(cin, a);
		getline(cin, b);
		short tab[a.size()+1][ b.size()+1];
		
		for0(i, a.size()+1)
		{
			for0(j, b.size()+1)
			{
				if (i==0 || j == 0)
					tab[i][j] = 0;
				else if(a[i-1] == b[j-1])
					tab[i][j] = tab[i-1][j-1] + 1;
				else
					tab[i][j] = max(tab[i-1][j], tab[i][j-1]);			
			}
		}
	/*	for0(i, a.size()+1)
		{
			for0(j, b.size()+1)
			{
				cout << tab[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << tab[a.size()][ b.size()] << endl;
		cin >> ws;
	}
	
}
