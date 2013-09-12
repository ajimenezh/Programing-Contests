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
int t;
int a[1001][1001];
int b[1001][1001];
bool vis[1001][1001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d",&a[i][j]);
	
	int t = 1000000;
	
	for (int j=m-1; j>=0; j--) {
		for (int i=n-(m-j); i<n; i++) {
			if (i>=n || i<0 || j+(n-i)-1>=m || j+(n-i)-1<0) continue;
			if (vis[i][j-i]) continue;
			t = min(t,a[i][j+(n-i)-1]);
			b[i][j+(n-i)-1] = t;
			vis[i][j+(n-i)-1] = 1;
		}
	}
	
	for (int j=max(n,m)-2; j>=0; j--) {
		for (int i=0; i<=j; i++) { 
			if (i>=n || i<0 || j-i>=m || j-i<0) continue;
			if (vis[i][j-i]) continue;
			t = min(t,a[i][j-i]);
			b[i][j-i] = t;
			vis[i][j-1] = 1;
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("%d ",b[i][j]);
		}
		cout<<endl;
	}

    return 0;

}
