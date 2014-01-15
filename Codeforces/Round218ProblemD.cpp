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

int a[200010];
int next[200010];
int c[200010];
int q[200010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",c+i);
    for (int i=0; i<n; i++) next[i] = i+1;
    c[n] = 1200000000;
    int m;
    cin>>m;
    for (int i=0; i<m; i++) {
        int t;
        scanf("%d",&t);
        if (t==2) {
            int y;
            scanf("%d",&y);
            cout<<a[y-1]<<"\n";
        }
        else {
            int p,x;
            scanf("%d%d",&p,&x);
            p--;
            int in = 0, fn = 0;
            while (x>0) {
                q[fn++] = p;
                if (a[p]==c[p]) p = next[p];
                else {
                    int tmp = min(x, c[p]-a[p]);
                    a[p] += tmp;
                    x -= tmp;
                    if (x) p = next[p];
                }
            }
            while (in<fn) {
                if (q[in]!=p) next[q[in]] = p;
                in++;
            }
        }
        a[n] = 0;
        //for (int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
    }

    return 0;

}
