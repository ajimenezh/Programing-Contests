#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)


class PilingRectsDiv1 {
	public:
	long long getmax(int N, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC) ;
};

int X[200010];
int Y[200010];
int p[200010];

struct mycomp{
	bool operator() (int a, int b) {
		return X[a]<X[b];
	}
}comp;

long long PilingRectsDiv1::getmax(int N, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC) {

    for (int i=0; i<XS.size(); i++) {
        X[i] = XS[i];
        Y[i] = YS[i];
    }

    for (int i=XS.size(); i<2*N; i++) {
        X[i] = ((long long)X[i-1]*XA+XB)%XC+1;
        Y[i] = ((long long)Y[i-1]*YA+YB)%YC+1;
    }

    for (int i=0; i<2*N; i++) if (X[i]>Y[i]) swap(X[i], Y[i]);

    if (N==1) return (long long)X[0]*Y[0] + (long long)X[1]*Y[1];

    for (int i=0; i<2*N; i++) p[i] = i;

    sort(p,p+2*N, comp);

    set<pair<int,int> > s1, s2, s3, s4, s;

    for (int i=N+1; i<2*N; i++) s1.insert(make_pair(Y[p[i]], p[i]));
    for (int i=N+1; i<2*N; i++) s3.insert(make_pair(Y[p[i]], p[i]));
    for (int i=0; i<N; i++) s.insert(make_pair(Y[p[i]], p[i]));

    long long res = (long long)X[p[N]]*min(Y[p[N]], (*s1.begin()).first) + (long long)X[p[0]]*min(Y[p[0]], (*s.begin()).first);



    for (int i=N-1; i>0; i--) {

        s1.insert(make_pair(Y[p[i+1]], p[i+1]));
        s2.insert(*s1.begin());
        s1.erase(s1.begin());

        set<pair<int,int> >::iterator it = s3.end();
        it--;
        s4.insert(*it);
        s3.erase(it);

        s.erase(make_pair(Y[p[i]], p[i]));

        long long y0 = (*s.begin()).first;
        long long x0 = X[p[0]];
        long long x1 = X[p[i]];
        long long t0 = (*s3.begin()).first;
        long long t1 = (*s1.begin()).first;
        long long t2 = (*s4.begin()).first;
        res = max(res, x0*min(y0, t2) + x1*min((long long)Y[p[i]],t0));
        res = max(res, x0*min(y0, t0) + x1*min((long long)Y[p[i]],t1));
    }

    return res;
};

