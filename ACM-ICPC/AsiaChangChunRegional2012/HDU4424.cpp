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

int n;
pair<int,pair<int,int> > v[200100];
int par[200100];
long long sum[200100];
int rk[200100];

int get(int a) {
    if (a==par[a]) return a;
    par[a] = get(par[a]);
    return par[a];
}

void connect(pair<int,pair<int,int> > p) {
    int a = p.second.first;
    a = get(a);
    int b = p.second.second;
    b = get(b);
    long long c = p.first;

    long long s1 = sum[a] + (long long)c*rk[b];
    long long s2 = sum[b] + (long long)c*rk[a];

    if (s1>s2) {
        rk[a] += rk[b];
        par[b] = a;
        sum[a] = s1;
    }
    else {
        rk[b] += rk[a];
        par[a] = b;
        sum[b] = s2;
    }

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n-1; i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            v[i] = make_pair(c,make_pair(a-1,b-1));
        }
        sort(v,v+n-1);
        reverse(v,v+n-1);
        for (int i=0; i<n; i++) par[i] = i;
        for (int i=0; i<n; i++) sum[i] = 0;
        for (int i=0; i<n; i++) rk[i] = 1;
        for (int i=0; i<n-1; i++) connect(v[i]);
        cout<<sum[get(0)]<<endl;
    }

    return 0;

}
