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

void swap(long long a, long long b) {a^=b;b^=a;a^=b;}
long long gcd(long long a, long long b) {if (a<b) swap(a,b); return (b==0?a:gcd(b,a%b));}

pair<long long, long long> divf(long long a, long long b) {
    long long g = gcd(a,b);
    return make_pair(a/g,b/g);
}

bool lessf(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first*b.second < a.second*b.first;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long t1,t2,x1,x2,t0;
    cin>>t1>>t2>>x1>>x2>>t0;

    pair<long long,long long> best = make_pair(1000000000,1);
    long long yy1 = x1, yy2 = x2;

    for (int k=1; k<=x1; k++) {
        if (t1*k-t0*k>0 && t0-t2<0) continue;
        if (t1*k-t0*k<0 && t0-t2>0) continue;
        if (t0-t2==0) continue;
        long long y2 = (abs(t1*k-t0*k)-1)/(abs(t0-t2))+1;
        if (abs(t1*k-t0*k)==0) y2 = 0;
        if (y2<0 || y2>x2) continue;
        pair<long long,long long> now = divf(t1*k+y2*t2,y2+k);
        if (lessf(now,best)) {
            best = now;
            yy1 = k;
            yy2 = y2;
        }
        else if (now==best && min(yy1,yy2) < min(y2,(long long)k) && yy2!=0 && y2!=0) {
            yy1 = k;
            yy2 = y2;
        }
        else if (now==best && y2==0 && yy2==0) {
            yy1 =max(yy1,(long long)k);
        }
        else if (now==best && y2!=0 && yy2==0) {
            if (yy1 < min(yy2,(long long)k)) {
                yy1 = k;
                yy2 = y2;
            }
        }
        else if (now==best && y2==0 && yy2!=0) {
            if (min(yy1,yy2) < k) {
                yy1 = k;
                yy2 = 0;
            }
        }
    }

    long long y2 = x2;
    pair<long long,long long> now = make_pair(t2,1);
    //cout<<best.first<<" "<<best.second<<endl;
    if (lessf(now,best) && t2>t0) {
        best = now;
        yy1 = 0;
        yy2 = y2;
    }
    else if (now == best && yy2!=0 && y2>min(yy1,yy2) && t2>t0) {
        yy2 = y2;
        yy1 = 0;
    }
    else if (now == best && yy2==0 && y2>yy1 && t2>t0) {
        yy2 = y2;
        yy1 = 0;
    }

    if (t2==t0 && t1!=t0) {
        cout<<0<<" "<<x2<<endl;
        return 0;
    }
    else if (t2==t0 && t1==t0) {
        cout<<x1<<" "<<x2<<endl;
        return 0;
    }

    //cout<<best.first<<" "<<best.second<<endl;
    cout<<yy1<<" "<<yy2<<endl;

    return 0;

}
