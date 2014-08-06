#include <iostream>
#include <cfloat>
#include <cstdio>
using namespace std;

int main()

{
	float f = 1.0;
	double d = 1.0;
	long double ld = 1.0;
	printf("%.10f\n", f);
	cout.precision(30);
	cout << f << endl << f+FLT_EPSILON << endl 
		<< d << endl << d+DBL_EPSILON << endl
		<< ld << endl << ld+LDBL_EPSILON << endl;
	cout << sizeof f << " " << sizeof d << " " << sizeof ld << endl;
	cout << FLT_MANT_DIG << " " << DBL_MANT_DIG << " " << LDBL_MANT_DIG << endl;
	cout << FLT_MIN_10_EXP << " " << DBL_MIN_10_EXP << " " << LDBL_MIN_10_EXP << endl;
	cout << FLT_MAX_10_EXP << " " << DBL_MAX_10_EXP << " " << LDBL_MAX_10_EXP << endl;

/*	for(int i = 0; i < 2000; i++)
		cout << (f *=10) << " " 
			<< (d*=10) << " " 
			<< (ld*=10) << endl;*/
}
