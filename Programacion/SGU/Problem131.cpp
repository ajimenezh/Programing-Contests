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

int n,m;
long long dp1[1<<10];
long long dp2[1<<10];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	
	dp1[0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (int k=0; k<(1<<(m+1)); k++) dp2[k] = dp1[k];
			for (int k=0; k<(1<<(m+1)); k++) dp1[k] = 0;
			
			for (int k=0; k<(1<<(m+1)); k++) {
				
				long long v = dp2[k]; 
				//cout<<i<<" "<<j<<" "<<k<<" "<<v<<endl;
				
				int t = k;
				
				if (j==0) t = t<<1;
				
				if (t>=(1<<(m+1))) continue;
				
				int right = 1<<(j+2);
				int up = 1<<(j+1);
				int down = 1<<j;
				
				if (up&t) {
					dp1[t & ~(1<<(j+1))] += v;
					continue;
				}
				
				if (!(down&t)) {
					dp1[t | down] += v;
					dp1[t | down | up] += v;
					
					if (j>0 && !((1<<(j-1))&t)) dp1[t | down | (1<<(j-1))] += v;
				}
				if (j<m-1 && !(right&t)) {
					dp1[t | right] += v;
					dp1[t | right | up] += v;
				}
				if (j<m-1 && !(down&t) && !(right&t)) dp1[t | right | down] += v;
			}
		}
	}
				
	cout<<dp1[0]<<endl;

    return 0;

}
