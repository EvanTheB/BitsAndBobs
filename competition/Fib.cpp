#include <iostream>
#include <vector>

typedef unsigned long long ull;

using namespace std;

vector<ull> fibs;
ull fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	fibs.resize(n-2, 0);
	if (fibs[n-3] != 0)
		return fibs[n-3];	
	int t = fib(n-1) + fib(n-2);
	fibs[n-3] = t;
	return t;
}

struct mat
{
	ull a,b,c,d;
	mat mul(mat A)
	{
		mat O;
		O.a = this->a;
		O.b = this->a;
		O.c = this->c;
		O.d = this->c;
	}
};

ull fib2(int n)
{
	mat I = {1,0,1,0};
	mat A = {1,1,1,0};
	
}

int main()
{
	while(!cin.eof())
	{
		int n;
		cin >> n;
		cout << n << ": " << fib(n) << endl;
	}
}
