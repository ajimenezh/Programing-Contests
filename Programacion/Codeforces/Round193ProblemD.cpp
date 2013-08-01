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
int a[1010][1010];
bool b[1010][1010];
int next[1010][1010];
bool vis[1010];
int nexth[1010][1010];

bool check(int mi) {
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) b[i][j] = (a[i][j]>=mi);
	
	for (int i=0; i<m; i++) next[0][i] = -1;
	for (int i=1; i<n; i++) for (int j=0; j<m; j++) {
		if (b[i-1][j]) next[i][j] = i-1;
		else next[i][j] = next[i-1][j];
	}
	for (int i=0; i<n; i++) vis[i] = 0;
	for (int i=0; i<n; i++) nexth[i][m-1] = m;
	for (int i=m-2; i>=0; i--) for (int j=0; j<n; j++) {
		if (b[j][i+1]) nexth[j][i] = i+1;
		else nexth[j][i] = nexth[j][i+1];
	}
	
	for (int i=1; i<n; i++) {
		for (int j=0; j<i; j++) vis[j] = 0;
		for (int j=0; j<m; j=nexth[i][j]) if (b[i][j]) {
			for (int k=next[i][j]; k>=0; k=next[k][j]) {
				
				if (vis[k]) return true;
				vis[k] = 1;
			}
		}
	}
	
	return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d",&a[i][j]);
	
	int lo = 0;
	int hi = 1000000000;
	
	while (lo<hi-1) {
		int mi = (lo+hi)>>1;
		
		if (check(mi)) {
			lo = mi;
		}
		else hi = mi-1;
	}
	while (check(lo)) lo++;
	cout<<lo-1<<endl; 
	
    return 0;

}
