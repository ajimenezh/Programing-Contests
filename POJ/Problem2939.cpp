//Ulm Local 2006
//Problem: Flavius Josephus Reloaded
//
// Solution: Use Pollard's rho algorithm to find the cycle
//				The solution using a map is TL

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

int n,a,b;

int next(long long cur, long long a, long long b, long long n) {
	return (a*((cur*cur)%n)+b)%n;
}

int main() {
	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	while(scanf("%d",&n) && n != 0) {

		int p1 = 0, p2 = 0, len = 0;
		int cnt = 0;
		
		scanf("%d%d",&a,&b);

		do {
			p1 = next(p1,a,b,n); 
			p2 = next(next(p2,a,b,n),a,b,n); 
			++cnt;
		}while(p1 != p2);

		do {
			p2 = next(p2,a,b,n);
			++len;
		}while(p1 != p2);
		printf("%d\n",n-len);
	}
	return 0;
}
