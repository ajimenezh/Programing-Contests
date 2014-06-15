#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)


class PairsOfStrings {
	public:
	int getNumber(int n, int k) ;
};

long long dp[1500];
int mod = 1000000007;

long long fpow(int a, int b) {
    if (b==0) return 1;
    long long tmp = fpow(a, b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

int PairsOfStrings::getNumber(int n, int k) {

    vector<int> divs;
    for (int i=1; i*i<=n; i++) {
        if (n%i==0) divs.push_back(i);
        if (n%i==0 && n/i!=i) divs.push_back(n/i);
    }
    sort(divs.begin(), divs.end());

   // cout<<divs.size()<<endl;

	long long sum = 0;
    for (int i=0; i<divs.size(); i++) {
    	//cout<<divs[i]<<endl;
        long long t = fpow(k, divs[i]);
        t %= mod;
       // cout<<t<<endl;
        for (int j=0; j<i; j++) if (divs[i]%divs[j]==0) {
            t -= dp[j];
            t %= mod;
            t = (t+mod)%mod;
        }

        dp[i] = t;
        t = (t*divs[i])%mod;
        sum = (sum+t)%mod;
    }

    return sum;

};

