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
int x[110], y[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		for (int i=0; i<n; i++) scanf("%d%d",x+i,y+i);
		int i = 0;
		int j = n-1;
		
		
		double len = 0;
		while (i!=j) {
			if (y[i+1]>y[j-1]) {
				len += sqrtl((x[j-1]-x[j])*(x[j-1]-x[j]) + (y[j-1]-y[j])*(y[j-1]-y[j]));
				double m = (double)(y[j-1]-y[j])/(y[i+1]-y[i-1]);
				double xx = x[i] + (double)(x[i+1]-x[i])*m;
				len += sqrtl((x-x[i])*(x-x[i]) + (y[j-1]-y[j])*(y[j-1]-y[j]));
			}
			else {
				
			}
		}
		
		printf("%.12lf\n",len);
	}
		
    return 0;

}
