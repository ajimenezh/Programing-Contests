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

int x[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        int n,c;
        scanf("%d%d",&n,&c);
        for (int i=0; i<n; i++) scanf("%d",x+i);
        c-=2;
        sort(x,x+n);
        int d = x[n-1] - x[0];
        int lo = 1;
        int hi = d;
        while (lo+1<hi) {
            int mi = (lo+hi)>>1;
            int last = x[0];
            int tmp = c;
            for (int i=1; i<n-1; i++) {
                if (x[i]-last>=mi) {
                    tmp--;
                    last = x[i];
                }
                if (tmp==0) break;
            }
            if (tmp==0 && x[n-1]-last>=mi) lo = mi;
            else hi = mi-1;
        }
        for (int k=lo+2; k>=lo; k--) {
            int last = x[0];
            int tmp = c;
            for (int i=1; i<n-1; i++) {
                if (x[i]-last>=k) {
                    tmp--;
                    last = x[i];
                }
                if (tmp==0) break;
            }
            if (tmp==0 && x[n-1]-last>=k) {
                cout<<k<<endl;
                break;
            }
        }
    }

    return 0;

}
