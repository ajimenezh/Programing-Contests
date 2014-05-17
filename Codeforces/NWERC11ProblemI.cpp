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

#define EPS 0.0000001

int t;
int s,r,w,p;
int sx[250010],sy[250010];
int w1x[11], w2x[11], w1y[11], w2y[11];
int px[11000], py[11000];
set<pair<double,int> > st;

struct pt {
	double x, y ;
	pt (int a, int b) {
        x = a; y = b;
	}
	pt() {
        x = 0;
        y = 0;
	}
};

struct seg {
	pt p, q;
	int id;

	seg(pt a, pt b) {
        p = a; q = b;
	}

	seg() {
        p = pt(); q = pt();
	}

	double get_y(double x) {
		if ( abs(p.x - q.x) < EPS )  return p.y ;
		return p.y + (q.y - p.y)/(q.x - p.x)*(x - p.x);
	}
};

bool intersect1d(double l1, double r1, double l2, double r2) {
	if (l1 > r1)  return intersect1d(r1,l1,l2,r2);
	if (l2 > r2)  return intersect1d(l1,r1,r2,l2);
	return max(l1, l2) <= min(r1, r2) + EPS ;
}

int vec(pt a, pt b, pt c ) {
	double s = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	return abs(s) < EPS ? 0 : s>0 ? +1 : -1 ;
}

bool intersect(int a1, int a2, int a3) {

    seg a = seg(pt(px[a1],py[a1]), pt(sx[a1],sy[a2]));
    seg b = seg(pt(w1x[a3],w1y[a2]), pt(w2x[a3],w2y[a3]));

	return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x)
		&& intersect1d(a.p.y, a.q.y, b.p.y, b.q.y)
		&& vec(a.p, a.q, b.p)*vec( a.p, a.q, b.q) <= 0
		&& vec(b.p, b.q, a.p)*vec(b.p, b.q, a.q) <= 0 ;
}

double dist(int a, int b) {
    return sqrt(a*a+b*b);
}

bool check(int pr, int sen) {
    if (dist(px[pr]-sx[sen],py[pr]-sy[sen]) > (double)r + 0.000001) return false;
    int cnt = 0;
    for (int i=0; i<w; i++) if (intersect(pr,sen,i)) {
        cnt++;
    }
    cout<<cnt<<endl;
    if (dist(px[pr]-sx[sen],py[pr]-sy[sen]) > r + 0,0000001 - cnt) return false; cout<<r<<" "<<cnt<<" "<<dist(px[pr]-sx[sen],py[pr]-sy[sen])<<endl;
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        scanf("%d%d%d%d",&s,&r,&w,&p);
        for (int i=0; i<s; i++) {
            scanf("%d%d",sx+i,sy+i);
        }
        for (int i=0; i<w; i++) {
            scanf("%d%d%d%d",w1x+i,w1y+i,w2x+i,w2y+i);
        }
        for (int i=0; i<p; i++) {
            scanf("%d%d",px+i,py+i);
        }

        for (int i=0; i<s; i++) st.insert(make_pair(dist(sx[i],sy[i]),i));

        for (int i=0; i<p; i++) {
            double d = dist(px[i],py[i]);

            set<pair<double,int> >::iterator in = lower_bound(st.begin(),st.end(),make_pair(d-r,-1));
            set<pair<double,int> >::iterator fn = upper_bound(st.begin(),st.end(),make_pair(d+r,-1));

            if (fn!=st.end()) fn++;

            vector<pair<int,int> > loc;
            for (set<pair<double,int> >::iterator it = in; it!=fn; it++){
                if (check(i,(*it).second)) {
                    loc.push_back(make_pair(sx[(*it).second],sy[(*it).second]));

                    cout<<i<<" "<<(*it).second<<endl;
                }
            }
        }

    }
    return 0;

}
