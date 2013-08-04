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

long long n;
int bin[60];
int c;
long long dp[60][2][3];

long long solve(int i, int flag, int r) {
	if (i==c && r==0) return 1;
	if (i==c) return 0;
	if (dp[i][flag][r]!=-1) return dp[i][flag][r];
	
	long long tmp = 0;
	
	if (flag) {
		tmp = solve(i+1,1,(r+1)%3) + solve(i+1,1,r);
	}
	else {
		if (bin[i]==0) {
			tmp = solve(i+1,0,r);
		}
		else tmp = solve(i+1, 1, r) + solve(i+1, 0, (r+1)%3);
	}
	
	dp[i][flag][r] = tmp;
	
	return tmp;
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>n) {
		c = 0;
		long long t = n;
		while (t>0) {
			bin[c++] = t&1;
			t >>= 1LL;
		}
		reverse(bin,bin+c);
		for (int i=0; i<c; i++) for (int j=0; j<2; j++) for (int k=0; k<3; k++) {
			dp[i][j][k] = -1;
		}
		
		long long ans = solve(0,0,0) - 1;
		
		cout<<"Day "<<n<<": Level = ";
		cout<<ans<<endl;
	}
			
	
    return 0;

}
