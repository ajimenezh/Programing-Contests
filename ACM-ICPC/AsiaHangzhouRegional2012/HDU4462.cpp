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
int k;
int x[11], y[11], r[11];
long long mask[11][51];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        cin>>k;
        for (int i=0; i<k; i++) {
            scanf("%d%d",x+i,y+i);
            x[i]--; y[i]--;
        }
        for (int i=0; i<k; i++) {
            scanf("%d",r+i);
        }

        for (int i=0; i<k; i++) {
            for (int j=0; j<n; j++) mask[i][j] = 0;
        }

        for (int i=0; i<k; i++) {
            for (int ii=0; ii<n; ii++) {
                for (int jj=0; jj<n; jj++) {
                    int d = abs(ii-x[i]) + abs(jj-y[i]);
                    if (d<=r[i]) {
                        mask[i][ii] |= (1LL<<jj);
                    }
                }
            }
        }

        int best = 100;
        for (int i=0; i<(1<<k); i++) {
            bool good = 1;
            for (int j=0; j<n; j++) {
                long long cur = 0;
                for (int t=0; t<k; t++) {
                    if (x[t]==j) {
                        cur |= 1LL<<y[t];
                    }
                }
                for (int t=0; t<k; t++) if (i&(1<<t)){
                    cur |= mask[t][j];
                }
                if (cur!=(1LL<<n)-1LL) {
                    good = 0;
                    break;
                }
            }
            if (good) best = min(best, __builtin_popcount(i));
        }
        if (best==100) best = -1;
        printf("%d\n",best);
    }

    return 0;

}
