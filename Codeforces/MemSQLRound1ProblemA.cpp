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

pair<int,int> x[5][2];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int n;
	bool done = 0;
	cin>>n;
	for (int i=0; i<n; i++) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x[i][0] = make_pair(x1,y1);
		x[i][1] = make_pair(x2,y2);
		if (abs(x2-x1)==abs(y2-y1) && abs(x2-x1)!=0) done = 1;
	}
	
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) for (int k=0; k<n; k++) for (int t=0; t<n; t++) for (int p=0; p<n; p++) {
		if (p==i || p==j || p==k || p==t) continue;
		if (t==k || t==j || t==i) continue;
		if (k==j || k==i) continue;
		if (j==i) continue;
		for (int ii=0; ii<2; ii++) for (int jj=0; jj<2; jj++) {
			int xm1 = x[i][ii].first;
			int xm2 = x[k][jj].first;
			int ym1 = x[i][ii].second;
			int ym2 = x[k][jj].second;

			if (xm1>xm2 || ym1<ym2) continue; 
			if (abs(xm2-xm1)!=abs(ym2-ym1)) continue; 
			cout<<xm1<<" "<<ym1<<" "<<xm2<<" "<<ym2<<endl;

			bool bad = 0;
			for (int xx=0; xx<4; xx++) for (int yy=0; yy<4; yy++) {
				bool good = 0;
				if (4*xm1+1+(xm2-xm1)*xx>=4*x[i][0].first && 4*xm1+1+(xm2-xm1)*xx<=4*x[i][1].first && 4*ym1+1-(ym2-ym1)*yy<=4*x[i][0].second && 4*ym1+1-(ym2-ym1)*yy>=4*x[i][1].second)
					good = 1;
				if (4*xm1+1+(xm2-xm1)*xx>=4*x[j][0].first && 4*xm1+1+(xm2-xm1)*xx<=4*x[j][1].first && 4*ym1+1-(ym2-ym1)*yy<=4*x[j][0].second && 4*ym1+1-(ym2-ym1)*yy>=4*x[j][1].second)
					good = 1;
				if (4*xm1+1+(xm2-xm1)*xx>=4*x[k][0].first && 4*xm1+1+(xm2-xm1)*xx<=4*x[k][1].first && 4*ym1+1-(ym2-ym1)*yy<=4*x[k][0].second && 4*ym1+1-(ym2-ym1)*yy>=4*x[k][1].second)
					good = 1;
				if (4*xm1+1+(xm2-xm1)*xx>=4*x[t][0].first && 4*xm1+1+(xm2-xm1)*xx<=4*x[t][1].first && 4*ym1+1-(ym2-ym1)*yy<=4*x[t][0].second && 4*ym1+1-(ym2-ym1)*yy>=4*x[t][1].second)
					good = 1;
				if (4*xm1+1+(xm2-xm1)*xx>=4*x[p][0].first && 4*xm1+1+(xm2-xm1)*xx<=4*x[p][1].first && 4*ym1+1-(ym2-ym1)*yy<=4*x[p][0].second && 4*ym1+1-(ym2-ym1)*yy>=4*x[p][1].second)
					good = 1;
				if (good == 0) bad = 1;
			}
			if (!bad) done = 1;
		}
	}
			

	if (done) cout<<"YES";
	else cout<<"NO";

    return 0;

}
