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

int n,t;
int p[21][2];
int v[21][2];
int next[21][2];
int m;
int c[21][2];
int sg[21];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>t;
	
	for (int i=0; i<n; i++) scanf("%d",&p[i][0]);
	for (int i=0; i<n; i++) scanf("%d",&v[i][0]);
	for (int i=0; i<n; i++) {
		sg[i] = (v[i][0]<0?-1:1);
	}
	for (int i=0; i<n; i++) {
		if (v[i][0]<0) {
			p[m][1] = p[i][0];
			v[m++][1] = -v[i][0];
		}
		else {
			p[i-m][0] = p[i][0];
			v[i-1][0] = v[i][0];
		}
	}
	n -= m;
	
	for (int i=0; i<t; i++) {
		for (int j=0; j<n; j++) next[j][0] = (p[j][0] + v[j][0])%1000;
		for (int j=0; j<m; j++) next[j][1] = (p[j][1] - v[j][1] + 1000)%1000;
		
		for (int j=0; j<n; j++) {
			for (int k=0; k<m; k++) {
				
				int dist;
				if (p[j][0]<p[k][1]) dist = p[k][1] - p[j][0];
				else dist = 1000 - p[j][0] + p[k][1];
				
				int vel = v[j][0] + v[k][1];
				
				if (vel>=dist && dist!=0) {
					c[j][0]++;
					c[k][1]++;
				}
			}
		}
		
		for (int j=0; j<n; j++) p[j][0] = next[j][0];
		for (int j=0; j<m; j++) p[j][1] = next[j][1];
	}
	
	int k=0, j=0;
	for (int i=0; i<(n+m); i++) {
		if (sg[i]<0) cout<<c[k++][1]<<" ";
		else cout<<c[j++][0]<<" ";
	}

    return 0;

}
