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

int n;
int a[200010];
long long f[200010][2];
bool vis[200010][2];
bool vis2[200010][2];
bool st[200010];
int pre[200010][2];
int now;

long long rec(long long x, int p) {
    //cout<<x<<" "<<p<<endl;
    //cout<<vis2[x][p]<<endl;
    if (x<=0 || x>n) return 0;
    if (x==1) {
        return -1;
        if (p==0) {
            pre[x][p] = now;
            st[now] = true;
            return 0;
        }
        else return -1;
    }
    if (f[x][p]==-1 || vis2[x][p]) {f[x][p] = -1; return -1;}
    if (vis[x][p]) return f[x][p];

    vis[x][p] = 1;
    vis2[x][p] = 1;
    long long t;
    if (p) {
        t = rec(x + (long long)a[x],1-p);
        if (t>0) {
            pre[x][p] = pre[x + (long long)a[x]][1-p];
        }
    }
    else {
        t = rec(x - (long long)a[x],1-p);
        if (t>0) {
            pre[x][p] = pre[x - (long long)a[x]][1-p];
        }
    }

    if (t<0) f[x][p] = -1;
    else f[x][p] = t + (long long)a[x];

    vis2[x][p] = 0;
    return f[x][p];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n-1; i++) scanf("%d",&a[i+2]);
    for (int i=0; i<=n+1; i++) vis[i][0] = 0;
    for (int i=0; i<=n+1; i++) vis[i][1] = 0;
    for (int i=0; i<=n+1; i++) vis2[i][0] = 0;
    for (int i=0; i<=n+1; i++) vis2[i][1] = 0;
    for (int i=0; i<=n+1; i++) f[i][0] = -2;
    for (int i=0; i<=n+1; i++) f[i][1] = -2;
    for (int i=0; i<=n+1; i++) pre[i][0] = -1;
    for (int i=0; i<=n+1; i++) pre[i][1] = -1;
    for (int i=1; i<n; i++) if (!vis[i+1][0]) {
        now = i+1;
        rec(i+1,0);
        if (pre[i+1][0]>0) {
            st[now] = st[pre[i+1][0]];
        }
    }

    for (int i=1; i<n; i++) {
        if (f[i+1][0]>=0) printf("%I64d\n",(long long)i+f[i+1][0]);
        else printf("-1\n");
    }

//    for (int i=2; i<=n; i++) {
//        int y = i;
//        int j = i;
//        int c = -1;
//        int h = 0;
//        while (true) {
//            if (j<=0 || j>n) break;
//            y += a[j];
//            j = j + a[j]*c;
//            c = -c;
//            h++;
//            if (h>1000) {y = 0; break;}
//        }
//        cout<<y-1<<endl;
//    }

    return 0;

}
