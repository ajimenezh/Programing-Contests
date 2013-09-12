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

int n,w;
int t[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&n,&w)==2 && n!=0) {
		for (int i=0; i<110; i++) t[i] = 0;
		for (int i=0; i<n; i++) {
			int v;
			scanf("%d",&v);
			t[v/w]++;
		}
		int m = 0;
		int last = 100;
		while (t[last]==0) last--;
		for (int i=0; i<=last; i++) m = max(m,t[i]);
		double p = 0.0;
		for (int i=0; i<=last; i++) {
			if (last!=0) p += (double)t[i]/m*(double)(last-i)/last;
			else p += 1.0;
		}
		p += 0.01;
		printf("%.12lf\n",p);
	}

    return 0;

}
