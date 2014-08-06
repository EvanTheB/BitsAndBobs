#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pare;

#define pb push_back
#define for0(a,b) for(int a = 0; a < b; a++)


class s
{
	int x,y,z;
	char d;
	s(int xx, int yy, int zz, int dd)
	{
		x = xx;y=yy;z=zz;d=dd;
	}
	bool operator()(s rhs)
	{
		return this.z < rhs.z;
	}
}

using namespace std;

int main()
{
	int T;
	cin >> T;
	pare m[201][201][500];
	for0(i,201) for0(j,201) for0(k,500) m[i][j][k] = make_pair(-1,-1);
	priority_queue<pare> pq;
	pq.push(s(0,0,0,0)
	while(!pq.empty())
	{
		
	}
	for0(t,T)
	{
		pare 
		cout << "Case #" << t+1 << ": " << p << endl;
	}
}

