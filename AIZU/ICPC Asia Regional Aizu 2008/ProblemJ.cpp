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
int x[12], y[12];

struct segment{
	int a,b,c;
	int mask;
	int beg, last;
	segment(){};
}sg[110];

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		int t = 0;
		for (int i=0; i<n; i++) scanf("%d%d",x+i,y+i);
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				int a = -(y[i]-y[j]);
				int b = x[i]-x[j];
				int c = -x[i]*a - y[i]*b;
				int mask = 0;
				for (int k=0; k<n; k++) if (((x[k]>=x[i] && x[k]<=x[j]) || (x[k]<=x[i] && x[k]>=x[j])) && a*x[k]+b*y[k]+c==0) mask |= (1<<k);
				sg[t].a = a;
				sg[t].b = b;
				sg[t].c = c;
				sg[t].mask = mask;
				sg[t].beg = i;
				sg[t].last = j;
				t++;
			}
		}
		
		int turns = 0;
		double len = 0;
		priority_queue<pair<pair<int,double>,pair<int,int> > > q;
		for (int i=0; i<t; i++) q.push(mp(mp(0.0,0.0),mp(i,sg[i].mask)));
		
		while (!q.empty()) {
			int _turns = -q.top().first.first;
			double _len = -q.top().first.second;
			int s = q.top().second.first;
			int mask = q.top().second.second;
			q.pop();
			
			if (mask==(1<<n)-1) {
				turns = _turns;
				len = _len;
				len += dist(x[sg[s].beg],y[sg[s].beg],x[sg[s].last],y[sg[s].last]);
				break;
			}
			
			for (int i=0; i<t; i++) {
				if ((sg[s].last==sg[i].beg || sg[s].beg==sg[i].last || sg[s].last==sg[i].last || sg[s].beg==sg[i].beg) && __builtin_popcount(sg[s].mask&sg[i].mask)==1) {
					double d = dist(x[sg[s].beg],y[sg[s].beg],x[sg[s].last],y[sg[s].last]);
					q.push(mp(mp(-_turns-1,-_len-d),mp(i,mask|sg[i].mask)));
				}
				else {
					if ((sg[s].mask&sg[i].mask)==0) {
						double xx,yy;
						if (sg[i].b*sg[s].a-sg[s].b*sg[i].a==0) continue;
						yy = (double)(-sg[i].c*sg[s].a+sg[i].a*sg[s].c) / (sg[i].b*sg[s].a-sg[s].b*sg[i].a);
						if (sg[i].a!=0) xx = (double)(-sg[i].b*yy-sg[i].c)/sg[i].a;
						else xx = x[sg[i].beg];
						double d = max(dist(x[sg[s].beg],y[sg[s].beg],xx,yy),dist(x[sg[s].last],y[sg[s].last],xx,yy));
						if ((xx>=x[sg[s].beg] && xx<=x[sg[s].last]) || (xx<=x[sg[s].beg] && xx>=x[sg[s].last])) continue;
						if ((xx>=x[sg[i].beg] && xx<=x[sg[i].last]) || (xx<=x[sg[i].beg] && xx>=x[sg[i].last])) continue;
						d += min(dist(x[sg[i].beg],y[sg[i].beg],xx,yy),dist(x[sg[i].last],y[sg[i].last],xx,yy));
						//cout<<xx<<" "<<yy<<" "<<d<<endl;
						//cout<<x[sg[i].beg]<<" "<<y[sg[i].beg]<<" "<<x[sg[i].last]<<" "<<y[sg[i].last]<<endl;
						q.push(mp(mp(-_turns-1,-_len-d),mp(i,mask|sg[i].mask)));
					}
				}
			}
		}
		printf("%d %.8lf\n",turns,len);
	}
	

    return 0;

}
