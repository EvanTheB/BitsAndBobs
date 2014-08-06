#include <iostream>
#include <cmath>
#include <vector>

#define SIZE 10000000
typedef unsigned long long ULL;



using namespace std;

vector<ULL> dp;

ULL f(const ULL i, const int count) {
    if (i == 1) return count;
    if (i <= SIZE && dp[i] != 0) {
        // System.out.println("using dp");
        return dp[i]+count;
    }
    int t;
   
    if (i%2 == 0)
        t= f(i/2, count+1);
    else
        t= f(3*i + 1, count+1);   
    if (i <= SIZE) dp[i] = t;
    return t;
}


int main() {
    dp = vector<ULL>(SIZE+1, 0);

    
    for (int i = 2; i <= SIZE; i++) {
        f(i, 1);
        
        if (i % (SIZE/10) == 0)
        std::cout << i << std::endl;
    }
    std::cout << "genned" << std::endl;
	
	int T;
	cin >> T;
    for (int t = 0; t < T; t++) {
        int I,J; cin>>I>>J;
        int i = min(I,J);
        int j = max(I,J);
       
        long sum = 0;
        for (long k = i; k < j; k++) {
            sum += dp[k];
            cout << dp[k] << endl;
        }
        cout << sum << endl;
    }
}


