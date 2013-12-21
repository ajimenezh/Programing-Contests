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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int gcd(int a, int b) {
    if (a<0) return gcd(-a,b);
    if (b<0) return gcd(a,-b);
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

unsigned long long code(int a, int b, int c) {
    a += 50000;
    b += 50000;
    c += 2000000000;
    unsigned long long tmp = c*2000000000LL;
    tmp += a * 100000;
	tmp += b;
	return tmp;
}

int n,m;
map<unsigned long long,vector<int> > p,py;
map<unsigned long long,bool> exist;
pair<int,pair<int,int> > v[1560];
pair<pair<int,int>,pair<int,int> > w[300010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        int a = -(y2-y1);
        int b = (x2-x1);
        int c = -a*x1 - b*y1;

        if (a<0) {
            a = -a;
            b = -b;
            c = -c;
        }
        if (a==0 && b<0) {
            b = -b;
            c = -c;
        }
        int g = a;
        g = gcd(a,gcd(b,c));
        a /= g;
        b /= g;
        c /= g;

        unsigned long long cod = code(a,b,c);

        exist[cod] = 1;

        w[i] = make_pair(make_pair(x1,y1),make_pair(x2,y2));

        //cout<<a<<" "<<b<<" "<<c<<endl;
    }

    for (int i=0; i<m; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[i] = make_pair(c,make_pair(a,b));
    }

    long long sum = 0;
    sort(v,v+m);
    for (int i=0; i<m; i++) {
        for (int j=i+1; j<m; j++) {
            if (v[i].first!=v[j].first) break;
            int x1 = v[i].second.first;
            int y1 = v[i].second.second;
            int x2 = v[j].second.first;
            int y2 = v[j].second.second;

            if ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)<=(long long)v[j].first*v[j].first*4) continue;

            int xm = x1+x2;
            int ym = y1+y2;

            int b = -(y2-y1);
            int a = -(x2-x1);
            int c = -a*xm - b*ym;
            a *= 2;
            b *= 2;

            if (a<0) {
                a = -a;
                b = -b;
                c = -c;
            }
            if (a==0 && b<0) {
                b = -b;
                c = -c;
            }
            int g = a;
            g = gcd(a,gcd(b,c));
            a /= g;
            b /= g;
            c /= g;

            unsigned long long cod = code(a,b,c);

            //cout<<a<<" "<<b<<" "<<c<<endl;

            if (exist[cod]) {
                p[cod].push_back(xm);
                py[cod].push_back(ym);
            }
        }
    }

    rep(it, p) {
        (*it).second.push_back(100000000);
        (*it).second.push_back(-100000000);
        sort((*it).second.begin(),(*it).second.end());
    }
    rep(it, py) {
        (*it).second.push_back(100000000);
        (*it).second.push_back(-100000000);
        sort((*it).second.begin(),(*it).second.end());
    }

    for (int i=0; i<n; i++) {
        int x1,y1,x2,y2;
        x1 = w[i].first.first;
        y1 = w[i].first.second;
        x2 = w[i].second.first;
        y2 = w[i].second.second;

        int a = -(y2-y1);
        int b = (x2-x1);
        int c = -a*x1 - b*y1;

        if (a<0) {
            a = -a;
            b = -b;
            c = -c;
        }
        if (a==0 && b<0) {
            b = -b;
            c = -c;
        }
        int g = a;
        g = gcd(a,gcd(b,c));
        a /= g;
        b /= g;
        c /= g;

        unsigned long long cod = code(a,b,c);

        if (x1!=x2) {

            int tmp = p[cod].size();
            int l = (upper_bound(p[cod].begin(),p[cod].end(),2*min(x1,x2)-1) - p[cod].begin());
            int r = tmp - (upper_bound(p[cod].begin(),p[cod].end(),2*max(x1,x2)) - p[cod].begin());

            sum += tmp - l - r;
        }
        else {
            int tmp = p[cod].size();
            int l = upper_bound(py[cod].begin(),py[cod].end(),2*min(y1,y2)-1) - py[cod].begin();
            int r = tmp - (upper_bound(py[cod].begin(),py[cod].end(),2*max(y1,y2)) - py[cod].begin());

            sum += tmp - l - r;
        }
    }

    cout<<sum<<endl;

    return 0;

}
