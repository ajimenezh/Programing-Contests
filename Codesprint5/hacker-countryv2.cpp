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
int d[505][505];
int len[505];
int dist[550];
bool vis[550];

int gcd(int a, int b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int q[510*510];
int in, fn;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) scanf("%d",&d[i][j]);
    }

    pair<int,int> p = make_pair(1000000,1);
    for (int i=0; i<n; i++) {
        in = 0; fn = 0;
        for (int j=i; j<=n; j++) {
            dist[j] = 100000000;
            len[j] = 1;
            vis[j] = 0;
        }
        dist[i] = 0;
        len[i] = 0;
        q[fn++] = i;
        while (in<fn) {
            int p = q[in++];
            vis[p] = 0;
            for (int j=i+1; j<n; j++) if (j!=p) {
                if ((dist[p] + d[p][j])*len[j] < dist[j]*(len[p]+1)) {
                    dist[j] =  dist[p] + d[p][j];
                    len[j] = len[p]+1;
                    if (!vis[j] && fn<(n-i)*(n-i)) {
                        vis[j] = 1;
                        q[fn++] = j;
                    }
                }
            }
            if (p!=i && (dist[p] + d[p][i])*len[n] < dist[n]*(len[p]+1)) {
                dist[n] =  dist[p] + d[p][i];
                len[n] = len[p]+1;
            }
        }

        if (dist[n]*p.second < p.first*len[n]) {
            p = make_pair(dist[n], len[n]);
            int g = gcd(p.first, p.second);
            p.first /= g;
            p.second /= g;
        }
    }

    cout<<p.first<<"/"<<p.second<<endl;

    return 0;

}

