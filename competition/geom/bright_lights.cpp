#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>

#define for0(n,N) for (int n = 0; n < N; n++)
#define debug(a) do{cout << a << endl;} while(0)
using namespace std;

#define EPS 1e-11

int gcd(int a, int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
struct pole
{
	int x,y,z;
	long double theta;
	long double dist;
};

bool closer(pole a, pole b)
{
	return (a.dist > b.dist)
		&& a.z <= b.z;
}

bool mycomp2(const pole& a, const pole& b)
{
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

class myclass
{
	public:	bool operator() (const double a, const double b)
	{
		return (abs(a - b) > EPS) && a > b;
	}

	public: bool operator() (const pole &a, const pole & b)
		{
			return a.dist > b.dist;
		}
};


int main()
{
	int N;
	int kase = 0;
	cin >> N;
	while(N != 0)
	{
		kase++;
	pole poles[N];
	map<double, priority_queue<pole, vector<pole>, myclass>, myclass > angles;
	for0(n,N)
	{
		int x,y,z;
		cin >> x >> y >> z;
		pole cur;
		cur.x=x;
		cur.y=y;
		cur.z=z;
		cur.dist=x*x+y*y;
		angles[atan2(y,x)].push(cur); 
		
	}
	vector<pole> ans;
	long double eps = 1e-12;
	
	auto it = angles.begin();
	for(; it != angles.end(); ++it)
	{
		int bmax = -1;
		if (it->second.size() > 1)
		while(it->second.size())
		{
			if (it->second.top().z <= bmax)
			{
				ans.push_back(it->second.top());
			}
			bmax = max(it->second.top().z, bmax);
			it->second.pop();
		}
	}

	sort(ans.begin(), ans.end(), mycomp2);
	cout << "Data set " << kase <<  ":" << endl;
	if (ans.size())
	{
		cout << "Some lights are not visible:" << endl;
		for0(n, ans.size()-1)
			cout << "x = " << ans[n].x << ", y = " << ans[n].y << ";" << endl;
		cout << "x = " << ans[ans.size()-1].x << ", y = " << ans[ans.size()-1].y << "." << endl;
	}
	else
		cout << "All the lights are visible." << endl;
	cin >> N;
	}
}
