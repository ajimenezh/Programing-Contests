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

int n,k;
int v[1000010];

int main() {

    //freopen("C:\\Users\\Alex-User\\Documents\\Projects\\ICPC\\WorldFinals13\\icpc2013-data\\low\\secret\\low-055.in","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d%d",&n,&k)!=EOF) {
        for (int i=0; i<2*n*k; i++) scanf("%d",v+i);
        sort(v,v+2*n*k);
        int lo = v[1]-v[0];
        int hi = 1000000000;
        long long sum;
        while (lo<hi) {
            int mi = (lo+hi)>>1;
            int cnt = 1;
            int last = 1;
            bool good = 1;
            sum = 2*k-2;
            for (int i=3; i<2*n*k; i++) {
                if (v[i]-v[i-1]<=mi) {
                    cnt++;
                    last = i;
                    sum += 2*(k-1);
                    i++;
                }
                else {
                    if (sum==0 && cnt<n) {
                        good = 0;
                        break;
                    }
                    sum--;
                }
            }
            if (!good || cnt<n) lo = mi+1;
            else hi = mi;
        }
        printf("%d\n",lo);
    }

    return 0;

}
