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
#include <bitset>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

vector<bitset<626> > v(625);
int n,m,d;

bool inside(int x, int y) {
	if (x<0 || x>=n) return 0;
	if (y<0 || y>=m) return 0;
	return 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d%d",&m,&n,&d) && n!=0) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int k = i*m+j;
				v[k].reset();
				v[k][k] = 1;
				int b;
				cin>>b;
				v[k][n*m] = b;
				for (int h=0; h<=d; h++) {
					int x = i+h;
					int y = j+(d-h);
					if (inside(x,y)) v[k][x*m+y] = 1;
					x = i+h;
					y = j-(d-h);
					if (inside(x,y)) v[k][x*m+y] = 1;
					x = i-h;
					y = j+(d-h);
					if (inside(x,y)) v[k][x*m+y] = 1;
					x = i-h;
					y = j-(d-h);
					if (inside(x,y)) v[k][x*m+y] = 1;
				}
			}
		}
		
		int k = 0;
		for (int i=0 ;i<m*n; i++) {
			int j = k;
			while (j<m*n && !v[j][i]) j++;
			if (j==m*n) continue;
			swap(v[k],v[j]);
			for (int j=k+1; j<m*n; j++) if (v[j][i]) v[j] ^= v[k];
			k++;
		}
		int ans = 1;
		
		for (int j=0; j<m*n; j++) {
			if (v[j][m*n] && v[j].count()==1) ans = 0;
		}
		
		cout<<ans<<endl;
		
	}
					

    return 0;

}
