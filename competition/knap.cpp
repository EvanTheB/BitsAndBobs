// use with ./a.out 1> input.txt 2> output.txt
//manual cases:
/* 1 tests basic solve, 2 tests for a 'greedy' solution, cram the best value/weight in

2	
2 20
5 3
1 1
2 20
3 12
2 9

**************OUT:

Case #1: 32
Case #2: 4

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "stdlib.h"


#define for0(a,b) for(int a = 0; a < b; a++)
#define rando(a) ( rand() % a + 1)

using namespace std;

vector<int> weights;
vector<int> values;

int gcd(int a, int b)
{
        if (b == 0)
                return a;
        else return gcd(b, a%b);
}

int solve(int N, int C)
{
        
        //gcd
        int div = weights[0];
        for(int n = 1; n < N; n++)
        {
                div = gcd(div, weights[n]);
        }
        div = gcd(div, C);
        C /= div;
        for0(n,N)
        {
           weights[n] /= div;
        }
		
        vector<int> sol(C+1, 0);
        for(int c = 1; c < C+1; c++)
        {
                int maxf = 0;
                for0(n,N)
                {
                        if (c - weights[n] < 0)
                                continue;
                        maxf = max(maxf, values[n] + sol[c - weights[n]]);
                }
                sol[c] = maxf;
        }
        return sol[C];
}

void gen(int N, int C)
{
        //N C
        cout << N << " " << C << endl;

        weights.clear();
        values.clear();
        weights.resize(N);
        values.resize(N);

        for0(n,N)
        {
                //V W

                weights[n] = rando(287);
                values[n] = rando(287);
                cout << values[n] << " " << weights[n] << endl;
        }
}

int main()
{
	cout << 14 << endl; //T
	for0(i,14)
	{
		gen(287, 287*287);
		cerr << "Case #" << i+1 << ": " << solve(287,287*287) << endl;
	}
}
