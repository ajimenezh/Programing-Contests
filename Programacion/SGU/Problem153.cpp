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

int t;
int n,k;
int p[10];
int dp[362880+5];

bool solve(int t) { 
	if (t<=0) return 1;
	if (dp[t]>=0) return dp[t];
	
	bool tmp = (1-solve(t-1));
	for (int i=0; i<k; i++) tmp |= (1-solve(t-p[i]));
	
	dp[t] = tmp; 
	return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>t;
	while (t--) {
		cin>>n>>k;
		for (int i=0; i<k; i++) cin>>p[i];
		for (int i=0; i<=362880; i++) dp[i] = -1;
		for (int i=0; i<=362880; i++) solve(i);
		
		int p = 362880;
		int in = 0;
		for (int ii=100; ii<300000; ii++) if (solve(ii)==1) {
			for (int i=1050; ; i++) {
				bool good = 1;
				for (int j=0; j<i; j++) if (solve(ii+i+j)!=solve(ii+j)) good = 0;
				if (good) {
					p = i;
					in = ii;
					ii = 1000000;
					break;
				}
			}
		}
		
		if ((n<in && !solve(n)) || (n>=in && !solve((n-in)%p))) {
			cout<<"SECOND PLAYER MUST WIN"<<endl;
		}
		else {
			cout<<"FIRST PLAYER MUST WIN"<<endl;
		}
	}

    return 0;

}
