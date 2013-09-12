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

int n;
int dp[1000010];

int solve(int a) {
	if (a<0) return 1000000000;
	if (a==0) return 0;
	if (dp[a]) return dp[a];
	
	int b = a;
	int tmp = 1000000000;
	
	while (b>0) {
		if (b%10!=0) tmp = min(tmp, solve(a-b%10)+1);
		b /= 10;
	}
	
	dp[a] = tmp; cout<<a<<" "<<dp[a]<<endl;
	return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	if (n==0) cout<<0<<endl;
	else cout<<solve(n)<<endl;

    return 0;

}
