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

int rev(int a) {
    int f = 1;
    while (f<=a) f*=10;
    f/=10;
    int b = 0;
    while (a>0) {
        b += (a%10)*f;
        f /= 10;
        a /= 10;
    }
    return b;
}

int maxy,maxx,w;
map<pair<int,int>,int > cnt;
map<pair<int,int>,int > cntx;
int gcd(int a, int b) {
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}
pair<int,int> fraction(int a, int b) {
    int g = gcd(a,b);
    return make_pair(a/g, b/g);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>maxx>>maxy>>w;

    for (int i=1; i<=maxy; i++) {
        pair<int,int> t = fraction(rev(i),i);
        if (cnt.find(t)!=cnt.end()) cnt[t]++;
        else cnt[t] = 1;
    }
    int y = maxy;
    int x = 0;
    int total = 0;
    long long best = 1LL<<60;
    int xf = -1;
    int yf = -1;
    while (true) {
        while (total<w && x<=maxx+1) {
            x++;
            total += cnt[fraction(x,rev(x))];
            //cout<<x<<" "<<fraction(x,rev(x)).first<<" "<<fraction(x,rev(x)).second<<endl;
            pair<int,int> t = fraction(x,rev(x));
            if (cntx.find(t)!=cntx.end()) cntx[t]++;
            else cntx[t] = 1;
        }
        if (x>maxx) break;
        //cout<<total<<" "<<x<<" "<<y<<endl;
        if ((long long)x*(long long)y<best) {
            best = (long long)x*(long long)y;
            xf = x; yf = y;
        }
        total -= cntx[fraction(rev(y),y)];
        cnt[fraction(rev(y),y)]--;
        y--;
        if (y<=0) break;
    }

    if (xf>0 && xf<=maxx && yf>0 && yf<=maxy) cout<<xf<<" "<<yf;
    else cout<<-1;

    return 0;

}
