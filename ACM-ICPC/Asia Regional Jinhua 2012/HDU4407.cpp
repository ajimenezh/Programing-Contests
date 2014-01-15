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

int n,m;
pair<int,int> v[1010];

int gcd(int a, int b) {
    if (b>a) return  gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

long long solve(int x, int p) {
    if (x<1) return 0;
    vector<int> pr;

    for (int i=2; i*i<=p; i++) if (p%i==0) {
        pr.push_back(i);
        while (p%i==0) p /= i;
    }
    if (p!=1) pr.push_back(p);

    long long tot = 0;
    for (int i=1; i<(1<<pr.size()); i++) {
        int f = 1;
        if (__builtin_popcount(i)%2==0) f = -1;
        int k = 1;
        for (int j=0; j<pr.size(); j++) if ((1<<j)&i) k *= pr[j];
        int t = x / k;
        long long sum = (long long)(t+1)*t/2;
        sum *= k;
        tot += f*sum;
    }

    return (long long)x*(x+1)/2 - tot;

}

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        scanf("%d%d",&n,&m);
        int h = 0;
        for (int i=0; i<m; i++) {
            int t;
            scanf("%d",&t);
            if (t==1) {
                int x,y,p;
                scanf("%d%d%d",&x,&y,&p);

                long long tmp = solve(y,p) - solve(x-1,p);

                for (int j=0; j<h; j++) {
                    if (v[j].first>=x && v[j].first<=y) {
                        if (gcd(v[j].first,p)==1) {
                            tmp -= v[j].first;
                            if (gcd(v[j].second,p)==1) tmp += v[j].second;
                        }
                        else {
                            if (gcd(v[j].second,p)==1) tmp += v[j].second;
                        }
                    }
                }

                printf("%lld\n",tmp);
            }
            else {
                int x,c;
                scanf("%d%d",&x,&c);
                bool done = 0;
                for (int j=0; j<h; j++) if (v[j].first==x) {
                    v[j].second=c;
                    done = 1;
                    break;
                }
                if (!done) {
                    v[h++] = make_pair(x,c);
                }
            }
        }
    }

    return 0;

}
