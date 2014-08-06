#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long int ll;
typedef long double ld;

#define pb push_back
#define for0(a,b) for(int a = 0; a < b; a++)


using namespace std;

char isvow(char a)
{
	return  (a == 'a' 
	||a == 'e' 
	||a == 'i'
	||a == 'o'
	||a == 'u');
	
}

int main()
{
	int T;
	cin >> T;
	for0(t,T)
	{
		string s;
		cin >> s;
		int L;
		cin >> L;
		int rem = s.length();
		int before = 0;
		char * p = &s[0];
		int c = 0;
		ll count = 0;
		while(*p != 0)
		{
			rem--;
			if (isvow(*(p++)))
				c = 0;
			else 
				c++;
			if (c == L)
			{
				count++;
				count += before + rem - L;
				count += (before-L) * rem;
				before = L-2;
				c--;		
			}
			before++;
			cout << count << endl;
		}
		cout << "Case #" << t+1 << ": " << count << endl;
	}
}

