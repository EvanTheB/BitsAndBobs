#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define for0(n,N) for (int n = 0; n < N; n++)
#define debug(a) do{cout << a << endl;} while(0)
using namespace std;

typedef long double ld;

#define EPS 1e-11
#define PI 3.14159265359

struct point
{
	double x,y;
	point(double a, double b): x(a), y(b){}
	point() : x(0), y(0) {}
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
	point perp()
	{
		point p;
		p.x = e.y-s.y;
		p.y = s.x-e.x;
		return p;
	}
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
	if (0 <= b && b <= 1)
		return l.s + v*b;
	return dist(p,l.s) < dist(p,l.e) ? l.s : l.e;
}

bool intersect_line(line &a, line &b, point &c)
{
	double atemp(a.s.x * a.e.y - a.s.y * a.e.x);
	double btemp(b.s.x*b.e.y - b.s.y*b.e.x);
	double xt = atemp * (b.s.x-b.e.x) - btemp* (a.s.x-a.e.x);
	double yt = atemp * (b.s.y - b.e.y) - btemp*(a.s.y - a.e.y);
	double bot = (a.s.x - a.e.x) * (b.s.y - b.e.y) - (a.s.y - a.e.y) * (b.s.x - b.e.x);
	if (abs(bot) <= EPS)
		return false;
	c.x = xt/bot;
	c.y = yt/bot;
}

double ccw(point a, point b, point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y) * (c.x-a.x);
}

struct circle
{
	point c;
	double r;
};

bool circle_from_3(point &a, point &b, point &c, circle & res)
{
	if (abs(ccw(a,b,c)) <= EPS)
		return false;
	line l1; l1.s = a; l1.e = b;
	line l2; l2.s = b; l2.e = c;
	line pl1; pl1.s = a + (b-a)*0.5; pl1.e = pl1.s + l1.perp();
	line pl2; pl2.s = b + (c-b)*0.5; pl2.e= pl2.s + l2.perp();

	intersect_line(pl2, pl1, res.c);
	res.r = dist(res.c,a);
	return true;

}

int main()
{
	point a(0,0),b(1,0),c(0.5,1);
	cout << ccw(a,b,c) << endl;
	c.y = -1;
	cout << ccw(a,b,c) << endl;
	c.x = -1;
	cout << ccw(a,b,c) << endl;
	


}
