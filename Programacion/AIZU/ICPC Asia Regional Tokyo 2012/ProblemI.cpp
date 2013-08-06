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

int w,n;
int x[51000];
int dp[51000];

bool check(int m) {
	for (int i=0; i<=n; i++) dp[i] = 0;
	int a = 0, b = 0;
	int suma = 0, sumb = 0;
	int numa = 0, numb = 0;
	
	dp[0] = 1;
	
	for (int i=0; i<n; i++) {
		for (; a<n; a++) {
			suma += x[a];
			numa ++;
			if (w <= suma + (numa-1)*m) break;
		}
		for (; b<n; b++) {
			if (w < sumb + x[b] + numb) {
				break;
			}
			sumb += x[b];
			numb ++;
		}
		
		if (dp[i]) {
			for (int j=a+1; j<b+1; j++) dp[j] = 1;
			a = b;
			suma = sumb;
			numa = numb;
		}
		
		suma -= x[i];
		sumb -= x[i];
		numa--;
		numb--;
	}
	
	return dp[n];
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&w,&n) && w!=0) {
		for (int i=0; i<n; i++) scanf("%d",x+i);
		
		int lo = 1;
		int hi = w;
		while (lo<hi) {
			int mi = (lo+hi)>>1;
			if (check(mi)) hi = mi;
			else lo = mi+1;
		}
		
		cout<<lo<<endl;
	}
	
    return 0;

}
