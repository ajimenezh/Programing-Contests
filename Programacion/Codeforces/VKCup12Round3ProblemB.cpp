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
int v1[1000005];
int v2[1000005];
int id[1000005];
int w[1000005];
int x,y;
int q[2000005];
int res;

bool check(int a, int b, int c) {
	return ((b+m-a)%m>=(c+m-a)%m);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) scanf("%d",v1+i);
	for (int i=0; i<m; i++) scanf("%d",v2+i);
	
	for (int i=0; i<1000005; i++) id[i] = -1;
	for (int i=0; i<m; i++) id[v2[i]] = i;
	
	for (int i=0; i<2*n; i++) w[i] = id[v1[i%n]];
	
	x = -1;
	
	for (int i=0; i<2*n; i++) {
		if (w[i]==-1) {
			x = -1;
			y = i+1;
		}
		else {
			while (x>=y && check(w[y],w[x],w[i])) y++;
			x = i;
			res = max(res, x-y+1);
		}
	}

	cout<<res<<endl;

    return 0;

}
