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

long long gcd(long long a, long long b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

long long sqr(long long a) {return a*a;}

pair<long long, long long> f(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long num = (sqr(x2-x1)+sqr(y2-y1));
    long long den = 2LL*abs(x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2);
    den = sqr(den);
    long long g = gcd(num,den);
    num /= g;
    den /= g;
    num *= (sqr(x2-x3)+sqr(y2-y3));
    g = gcd(num,den);
    num /= g;
    den /= g;
    num *= (sqr(x3-x1)+sqr(y3-y1));
    g = gcd(num,den);
    num /= g;
    den /= g;
    return make_pair(num,den);
}

map<pair<long,long>,int> tot;

int main() {

    freopen("circles.in","r",stdin);
    freopen("circles.out","w",stdout);

    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int x1,x2,x3,y1,y2,y3;
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        tot[f(x1,y1,x2,y2,x3,y3)]++;
    }
    int res = 0;
    for (map<pair<long,long>,int>::iterator it = tot.begin(); it!=tot.end(); it++) {
        res = max(res,(*it).second);
    }
    cout<<res;

    return 0;

}
