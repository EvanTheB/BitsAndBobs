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

int main()
{
        int T; //17
        cin >> T;
        for0(t,T)
        {
                int N, C; //287, 82369
                cin >> N >> C;
                vector<int> weights(N);
                vector<int> values(N);
                for0(n, N)
                {
                        cin >> values[n] >> weights[n]; //287, 287
                }

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
                cout << sol[C] << endl;
        }

}

