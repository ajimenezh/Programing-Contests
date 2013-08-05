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

typedef long double Double;

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	for (int tt=1; tt<=t; tt++) {
		int n;
		cin>>n;
		
		Double xmin = 10000;
		Double xmax = -10000;
		Double ymin = 100000;
		Double ymax = -100000;
		
		for (int i=0; i<n; i++) {
			Double x,y;
			cin>>x>>y;
			xmin = min(x,xmin);
			xmax = max(xmax,x);
			ymin = min(ymin,y);
			ymax = max(ymax,y);
		}

		
		printf("Swarm %d Parallelogram Area: %.4f\n",tt,(double)((ymax-ymin)*(xmax-xmin)));
	}
	
    return 0;

}
