#include <iostream>
#include <string>
#include <cmath>
#include "stdio.h"
#include "string.h"
#define for1(a,b) for (int a = 0; a < b; a++) 
#define ld long long

using namespace std;

char isPali(double b)
{
	char a[100];
	sprintf(a, "%d", (int)b);
	
	for (int i = 0; i < strlen(a)/2; i++)
	{
		//cout << a[i] << endl;
		if (a[i] != a[strlen(a) - i])
			return 0;
	}
	cout << a << endl;
	return 1;
}

int main()
{
	for1(i,sqrt(1001))
	{	
		if (isPali(i) && isPali(pow(i,2)))
			cout << i << endl;
	}
}


