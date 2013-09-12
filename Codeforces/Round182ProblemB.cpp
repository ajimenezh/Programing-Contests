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
int a[101];
int x[101], y[101];
int d;
int dist[101][101];
int c[101];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>d;
	for (int i=1; i<n-1; i++) cin>>a[i];
	for (int i=0; i<n; i++) cin>>x[i]>>y[i];
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) dist[i][j] = d*(abs(x[i]-x[j]) + abs(y[i]-y[j]));
	
	int lo = 0;
	int hi = 100000000;
	while (lo<hi) {
		int mi = (hi+lo)/2;
		c[0] = mi;
		for (int i=1; i<n; i++) c[i] = -1;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				for (int k=1; k<n; k++) if (j!=k) {
					if (c[j] - dist[j][k]>=0) {
						c[k] = max(c[k],c[j] - dist[j][k] + (k==n-1?0:a[k]));
					}
				}
			}
		}
		
		//cout<<lo<<" "<<hi<<" "<<c[n-1]<<endl;
		
		if (c[n-1]>=0) {
			hi = mi;
		}
		else {
			lo = mi+1;
		}
	}
	
	cout<<lo<<endl;
		

    return 0;

}
