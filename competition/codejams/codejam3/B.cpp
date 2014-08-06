#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define for0(i, N) for(int i = 0; i < (N); i++)
#define pb push_back
#define vec1(type) vector<type>
#define vec2(type) vector< vec1(type) >


using namespace std;

struct loc
{
	int x, y;
};

vec2(int) C;
vec2(int) F;
vec2(double) T;
int H;

bool cango(loc s, loc e, int H)
{
	if (H + 50 <= C[e.x][e.y] && F[s.x][s.y] + 50 <= C[e.x][e.y] 	
			&& F[e.x][e.y] + 50 <= C[e.x][e.y] && F[e.x][e.y] + 50 <= C[s.x][s.y])
	{
		return true;
	}
	return false;
}

int cango2(loc s, loc e, int H)
{
	int t = 0;
	if (F[s.x][s.y] + 50 <= C[e.x][e.y] 	
			&& F[e.x][e.y] + 50 <= C[e.x][e.y] && F[e.x][e.y] + 50 <= C[s.x][s.y])
	{
		if (H + 50 <= C[e.x][e.y])
			t = 0;
		else
		{
			t = (H - C[e.x][e.y]	+ 50.0 ) / 10.0;
		}
		if (H - 10 * t >= F[s.x][s.y])
			t += 1;
		else t += 10;
		return t;
	}
	return 100000000;
}

void r(int x, int y, double cT)
{
	if (cT >= T[x][y])
		 return;
		 
	if (x > 0)
	{
		if (cango2({x, y}, {x - 1, y}, H- cT * 10) < T[x-1][y])
		{
			T[x-1][y] = cango2({x,y}, {x - 1, y}, H- cT * 10);
			r(x-1, y, T[x-1][y]);
		}		
	}
	if ( x < C.size() -1)
	{
		if (cango2({x, y}, { x +1,  y}, H- cT * 10) < T[x+1][y])
		{
			T[x+1][y] = cango2({x, y}, { x +1,  y}, H- cT * 10);
			r(x+1, y, T[x+1][y]);
		}		
	}
	if ( y > 0)
	{
		if (cango2({x, y}, { x,  y-1}, H- cT * 10) < T[x][y-1])
		{
			T[x][y-1] = cango2({x, y}, { x,  y-1}, H- cT * 10);
			r(x, y-1, T[x][y-1]);
		}		
	}
	if ( y < C[0].size() -1)
	{
		if (cango2({x, y}, { x ,  y + 1}, H- cT * 10) < T[x][y+1])
		{
			T[x][y+1] = cango2({x, y}, { x ,  y+1}, H- cT * 10);
			r(x, y+1, T[x][y+1]);
		}		
	}
}

int main()
{
	int kases;
	cin >> kases;	
	for0(kase, kases)
	{
		int  N, M;
		
		cin >> H >> N >> M;
		C = vec2(int)(N, vec1(int)(M, 0));
		F = vec2(int)(N, vec1(int)(M, 0));
		T = vec2(double)(N, vec1(double)(M, 1000000));
		for0(n, N)
			for0(m, M)
			{
				cin >> C[n][m];
			}
		for0(n, N)
			for0(m, M)
			{
				cin >> F[n][m];
			}
		T[0][0] = 0;
		vector< loc > L;
		L.pb({0,0});
		while(!L.empty())
		{
			loc cur = L.back();
			L.pop_back();			
			if ( cur.x > 0 && cango(cur, {cur.x - 1, cur.y}, H)){
				T[cur.x - 1][ cur.y] != 0 &&T[cur.x - 1][ cur.y] = 0;
				L.pb({cur.x - 1, cur.y});
				}
			if ( cur.x < M-1 && cango(cur, {cur.x +1, cur.y}, H)){
				T[cur.x +1][ cur.y] != 0 &&T[cur.x +1][ cur.y] = 0;
				L.pb({cur.x+1, cur.y});
				}
			if (cur.y > 0 && cango(cur, {cur.x, cur.y -1}, H)){
				T[cur.x][ cur.y - 1] != 0 && T[cur.x][ cur.y - 1] = 0;
				L.pb({cur.x, cur.y - 1});
				}
			if ( cur.y < N-1 && cango(cur, {cur.x, cur.y + 1}, H)){
				T[cur.x][ cur.y +1] != 0 &&T[cur.x][ cur.y + 1] = 0;
				L.pb({cur.x, cur.y + 1});
				}
		}
		for0(n, N)
		{
			for0(m, M)
			{
				cout << T[n][m] << " ";
			}
			cout << endl;
		}
		L.clear();
		for0(n, N)
		{
			for0(m, M)
			{
				r(n,m, 0);
			}			
		}
		cout << T[N-1][M-1] << endl << endl;
	}
}

