#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

long long dp[1500][22];
long long all[1500];

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	
	dp[0][0] = dp[1][1] = 1;
	all[0] = all[1] = 1;
	
	for (int i=2; i<1500; i++) {
		long long sum = 0;
		for (int j=0; j<22 ; j++) {
			long long s = 0;
			for (int k=0; k<i; k++) {
				s += dp[k][j-1]*dp[i-k-1][j-1];
				if (j>0) {
					s += dp[k][j-2]*dp[i-k-1][j-1];
					s += dp[k][j-1]*dp[i-k-1][j-2];
				}
				s %= 1000000000;
			}
			dp[i][j] = s;
			sum += s;
		}
		all[i] = sum;
	}
	
	int n;
	while (cin>>n) {
		
		long long t = all[n];
		
		t %= 1000000000;
		
		int d = 0;
		int tmp = t;
		while (tmp>0) {
			d++;
			tmp /= 10;
		}
		
		for (int i=0; i<(9-d); i++) cout<<"0";
		cout<<t;
		cout<<endl;
	}
	
    return 0;

}
