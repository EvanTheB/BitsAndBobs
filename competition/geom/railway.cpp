#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define for0(n,N) for (int n = 0; n < N; n++)
#define debug(a) do{cout << a << endl;} while(0)
using namespace std;

typedef long double ld;

struct point
{
	double x,y;
	point operator-(const point & other)
	{
		point ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}
	point operator+(const point & other)
	{
		point ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}
	point operator*(double b)
	{
		point ret;
		ret.x = x * b;
		ret.y = y *b;
		return ret;
	}
	point operator=(const point & other)
	{
		x=other.x;
		y=other.y;
	}
};

struct line
{
	point s;
	point e;
};

double dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

double dist(point a, point b)
{
	double x = a.x-b.x;
	double y = a.y-b.y;
	return sqrt(x*x + y*y);
}

point cap(point p, line l)
{
	point v = l.e - l.s;
	point w = p - l.s;
	double b = dot(w,v) / dot(v,v);
	//debug(p.x << " " << p.y << " " << l.s.x << " " << l.s.y << " " << l.e.x << " " << l.e.y << " " << (l.s + v*b).x << " " << (l.s + v*b).y );
	if (0 <= b && b <= 1)
		return l.s + v*b;
	return dist(p,l.s) < dist(p,l.e) ? l.s : l.e;
}
int main()
{
	while((cin>>ws).good())
	{
		point tr;
		cin >> tr.x >> tr.y;
		int N;
		cin >> N;
		line lines[N];
		point last;
		cin >> last.x >> last.y;
		for0(n,N)
		{
			point cur;
			cin >> cur.x >> cur.y;
			lines[n].s=last;
			lines[n].e=cur;
			last=cur;
		}
		point best = cap(tr, lines[0]);
		double dbest = dist(best, tr);
		for(int i = 1; i < N; i++)
		{
			point ans = cap(tr, lines[i]);
			if (dist(ans,tr) < dbest)
			{
				best = ans;
				dbest = dist(ans,tr);
			}
		}
		cout.precision(4);
		cout << fixed << best.x << endl << best.y << endl;
	}
}
