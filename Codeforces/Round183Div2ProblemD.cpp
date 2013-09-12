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

long long n,m,x,y,a,b;

long long gcd(long long c1, long long c2) {
    if (c1<c2) return gcd(c2,c1);
    if (c2==0) return c1;
    return gcd(c2,c1%c2);
}
long long mcm(long long c1, long long c2) {
    return (c1*c2)/gcd(c1,c2);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>x>>y>>a>>b;

    long long ma,mb;

    if ((long long)n*(long long)b>(long long)a*(long long)m) {
        mb = ((long long)a*(long long)m) - ((long long)a*(long long)m)%mcm(a,b);
        mb /= a;
        ma = mb*a/b;
    }
    else if ((long long)n*(long long)b<(long long)a*(long long)m) {
        ma = ((long long)b*(long long)n) - ((long long)b*(long long)n)%mcm(a,b);
        ma /= b;
        mb = ma*b/a;
    }
    else {
        ma = n;
        mb = m;
    }

    //cout<<ma<<" "<<mb<<endl;

    ma *= 2LL;
    mb *= 2LL;
    x *= 2LL;
    y *= 2LL;

    long long cx;
    long long cy;

    if (x<=ma/2) {
        cx = ma/2;
    }
    else {
        if (x>(2LL*n-ma/2)) {
            cx = 2LL*n-ma/2;
        }
        else {
            cx = x;
        }
    }
    if (y<=mb/2) {
        cy = mb/2;
    }
    else {
        if (y>(2LL*m-mb/2)) {
            cy = 2LL*m-mb/2;
        }
        else {
            cy = y;
        }
    }

    //cout<<cx<<" "<<cy<<endl;

    if (cx%2==0 && cy%2==0) {
        cx /= 2;
        cy /= 2;
        cout<<cx-ma/4-(ma/2)%2<<" "<<cy-mb/4-(mb/2)%2<<" "<<cx+ma/4<<" "<<cy+mb/4<<endl;
    }
    else if (cx%2!=0 && cy%2==0) {
        cx /= 2;
        cy /= 2;
        cout<<cx-ma/4<<" "<<cy-mb/4-(mb/2)%2<<" "<<cx+ma/4+(ma/2)%2<<" "<<cy+mb/4<<endl;
    }
    else if (cx%2==0 && cy%2!=0) {
        cx /= 2;
        cy /= 2;
        cout<<cx-ma/4-(ma/2)%2<<" "<<cy-mb/4<<" "<<cx+ma/4<<" "<<cy+mb/4+(mb/2)%2<<endl;
    }
    else if (cx%2!=0 && cy%2!=0) {
        cx /= 2;
        cy /= 2;
        cout<<cx-ma/4<<" "<<cy-mb/4<<" "<<cx+ma/4+(ma/2)%2<<" "<<cy+mb/4+(mb/2)%2<<endl;
    }

    return 0;

}
