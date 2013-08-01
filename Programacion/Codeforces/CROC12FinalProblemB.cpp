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
int cnt[1000010];
int x[260];
int y[250];
int m;

long long det(int x1,int y1, int x2,int y2) {
	return (long long)x1*y2 - (long long)y1*x2;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	
	for (int i=0; i<m; i++) cin>>x[i]>>y[i];
	
	for (int i=1; i<=n; i++) cnt[i] = 1;
	
	for (int i=0; i<m; i++) for (int j=i+1; j<m; j++) {
		int t = 2;
		for (int k=j+1; k<m; k++) {
			if (det(x[i]-x[j],y[i]-y[j],x[i]-x[k],y[i]-y[k])==0) {
				t++;
			}
		}
		long long a = y[j]-y[i];
		a = -a;
		long long b = x[j]-x[i];
		long long c = (a*x[i]+b*y[i]);
		
		if (a==0) continue;

		if (c%a==0 && c/a>=1 && c/a<=n) cnt[c/a] = max(cnt[c/a],t);
	}
	
	long long sum = 0;
	
	for (int i=1; i<=n; i++) sum += cnt[i];
	
	cout<<sum<<endl;

    return 0;

}
