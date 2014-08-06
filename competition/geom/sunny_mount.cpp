#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define for0(n,N) for (int n = 0; n < N; n++)
#define debug(a) do{cout << a << endl;} while(0)
using namespace std;

double dist(int x, int y, int h)
{
	return sqrt(x*x + y*y) * (y-h) / y;
}

int main()
{
	int C;
	cin >> C;
	for0(c,C)
	{
		int N;
		cin >> N;
		vector<pair<int, int> > peak(N, make_pair(0,0));
		for0(n,N)
		{
			cin >> peak[n].first >> peak[n].second;
		}
		sort(peak.begin(), peak.end());
		int H = 0;
		int cur = N-2;
		double D = 0.0;
		while (cur >= 0)
		{
			if (peak[cur].second < H)
			{
				cur--;
				continue;
			}
			D += dist(peak[cur+1].first - peak[cur].first,
					peak[cur].second - peak[cur+1].second,
					H-peak[cur+1].second);

			H = peak[cur].second;
			cur--;
		}
		cout.precision(2);
		cout << fixed << D << endl;
	}

}
