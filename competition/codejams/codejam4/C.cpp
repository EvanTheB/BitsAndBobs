#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

#define for0(i, N) for(int i = 0; i < (N); i++)
#define pb push_back
#define vec1(type) vector<type>
#define vec2(type) vector< vec1(type) >

typedef unsigned long long ull;

using namespace std;

struct C
{
	int b;
	int t;
	ull bn;
	ull tn;
	bool operator() (const C &l,const C &r) const
	{
		if (l.b != r.b)
			return l.b < r.b;
		if (l.t != r.t)
			return l.t < r.t;
		if (l.bn != r.bn)
			return l.bn < r.bn;
		if (l.tn != r.tn)
			return l.tn < r.tn;
		return false;		
	}
};
int B, T;
map<C, ull, C> cache;
vector<int> boxt;
vector<ull> boxn;
vector<int> toyt;
vector<ull> toyn;

ull r(C c)
{
	
	//cout << "call" << endl;
	ull ret;
	if (c.b >= boxn.size()|| c.t >= toyn.size())
		return 0;
	else
	{
		map<C, ull, C>::iterator it = cache.find(c);
		if (it != cache.end())
		{
			ret = it->second;
			//cout << "cache:" << c.b << " " << c.t<< endl;
		}	
		else if (boxt[c.b] == toyt[c.t])
		{
			if (boxn[c.b] - c.bn == toyn[c.t] - c.tn)
			{
				ret = r({c.b+1, c.t+1, 0, 0}) + boxn[c.b] - c.bn;
			}
			else if(boxn[c.b]- c.bn > toyn[c.t]- c.tn)
			{
				ret = r({c.b, c.t+1, c.bn + toyn[c.t] - c.tn, 0}) + toyn[c.t]- c.tn;
			}
			else
			{
				ret = r({c.b+ 1, c.t, 0, c.tn + boxn[c.b] - c.bn})+ boxn[c.b]- c.bn;
			}
		}
		else
		{
			ret = max ( r({c.b+1, c.t, 0, c.tn}) , r({c.b, c.t + 1, c.bn, 0}) );
		}
	}
	cache.insert(pair<C, ull>(c, ret));
	//cout << cache.size() << endl;
	return ret;
}



int main()
{
	int kases;
	
	cin >> kases;	
	for0(kase, kases)
	{
		cin >> B >> T;
		boxt.clear();
		boxt.resize(B, 0);
		boxn.clear();
		boxn.resize(B, 0);
		toyt.clear();
		toyt.resize(T, 0);
		toyn.clear();
		toyn.resize(T, 0);
		cache.clear();
				
		for0(b, B)
		{
			cin >> 	boxn[b] >> boxt[b];			
		}
		for0(t, T)
		{
			cin >> 	toyn[t] >> toyt[t];			
		}	
		cout << "Case #" << kase + 1 << ": " ;
		cout << r({0, 0, 0, 0}) << endl;
		
		
		for(map<C, ull, C>::iterator it = cache.begin(); it != cache.end(); it++)
		{
			//cout << it->second << " ";
		}
		//cout << endl << endl;
		
	}
}

