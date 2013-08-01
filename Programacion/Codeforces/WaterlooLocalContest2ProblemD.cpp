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

int n,w,z;
bool bad[2000][2000];
int sum[2000];

bool check(int t) {
	for (int i=0; i<n; i++) sum[i] = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<t; j++) sum[i] += bad[i][j];
	}
	int tot = 0;

	for (int i=0; i<n-t+1; i++) {
		if (i!=0) {
			for (int j=0; j<n; j++) {
				sum[j] -= bad[j][i-1];
				sum[j] += bad[j][i+t-1];
			}
		}
		tot = 0;
		for (int j=0; j<t; j++) tot += sum[j];
		for (int j=0; j<n-t+1; j++) {
			if (j!=0) {
				tot -= sum[j-1];
				tot += sum[j+t-1];
			}
			if (tot<=z) return true;
		}
	}
	return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	while (tt--) {
		cin>>n>>w>>z;
		for (int i=0; i<n; i++) for (int j=0; j<n; j++) bad[i][j] = 0;
		for (int i=0; i<w; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			a--; b--;
			if (bad[a][b]) w--;
			bad[a][b] = 1;
		}
		
		if (n*n==w) {
			cout<<0<<endl;
			continue;
		}
		int lo = 1;
		int hi = n;
		while (lo+1<hi) {
			int mi = (lo+hi)/2;
			bool f = check(mi);
			if (f) lo = mi;
			else hi = mi-1;
		}
		for (int i=hi; i>=lo; i--) {
			if (check(i)) {
				cout<<i*i<<endl;
				break;
			}
		}
	}

    return 0;

}
