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

const double pi = acos(-1.0);

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int w,h;
	while (cin>>h>>w && h!=0) {
		double v1 = 0.0;
		if (w-h > pi*h) {
			v1 = 1.0*h*pi*h*h/4.0;
		}
		double v3 = 0.0;
		if (w>2*(1.0*w/(2.0*pi+2.0)) && 2*(1.0*w/(2.0*pi+2.0))<=h) {
			v3 = (1.0*w/(2.0*pi+2.0))*(1.0*w/(2.0*pi+2.0))*pi*h;
		}
		v1 = max(v1,v3);
		double v2 = 0.0;
		if (w > 1.0*h/(pi)) {
			v2 = (w-1.0*h/(pi))*pi*(1.0*h/(2.0*pi))*(1.0*h/(2.0*pi));
		}
		
		printf("%.3lf\n",max(v1,v2));
	}
	
    return 0;

}
