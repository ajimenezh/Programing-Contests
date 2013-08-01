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

#define MAXN 10000005

int f[MAXN], prime[MAXN];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tot = 0;
	int tmp;
	for (int i=2; i<MAXN; i++) f[i] = i;
	for (int p=2; p<MAXN; p++) {
		if (f[p]==p) prime[tot++] = p;
		for (int i=0; i<tot && prime[i]<=f[p]; i++) {
			tmp = prime[i]*p;
			if (tmp<MAXN) {
				f[tmp] = prime[i];
			}
			else break;
		}
	}
	

    return 0;

}
