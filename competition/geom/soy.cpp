#include <cmath>
#include <iostream>

using namespace std;

#define PI 3.14159265359

int main()
{
	long double l,w,h,a;
	cout.precision(3);
	while((cin>>ws).good())
	{
		cin >> l >> w >> h >> a;
		double ex = l*tan(a*PI/180);
		
		if (ex > h)
		{
			cout << fixed << w*h*h*0.5*tan(PI/180 * (90-a)) << " mL" <<  endl;
		}
		else	cout << fixed << l*w*h - w * 0.5*l*l*tan(a*PI/180)<< " mL" << endl;
	}
}
