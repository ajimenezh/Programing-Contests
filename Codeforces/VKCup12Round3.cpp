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

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) scanf("%d",v1+i);
	for (int i=0; i<m; i++) scanf("%d",v2+i);
	
	for (int i=0; i<m; i++) id[v2[i]] = i;
	
	for (int i=0; i<2*n; i++) w[i] = id[v1[i%n]];
	
	int minimo = -1;
	int c = 0;
	int last = -1;
	int res = 0;
	
	for (int i=0; i<2*n-1; i++) {
		
		if (last==-1) {
			if (w[i]<w[i+1]) {
				minimo = w[i];
				c = 1;
				last = w[i];
			}
			else if (w[i]<w[i+1]+n) {
				minimo = w[i]+n;
				c = 1;
				last = w[i]+n;
			}
		}
		else {
			if (last > w[i+1]+n || (w[i+1]+n>last && w[i+1]+n-minimo>=n) ) {
				res = max(res,c);
				last = -1;
				i--;
			}
			else {
				if (last < w[i+1]) {
					c++;
					last = w[i+1];
				}
				else {
					c++;
					last = w[i+1]+n;
				}
			}
		}
	}
	
	cout<<res<<endl;

    return 0;

}
