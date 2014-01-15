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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    while (scanf("%d",&n)!=EOF) {
        int a[5];
        for (int i=0; i<n; i++) scanf("%d",a+i);
        int best = 0;
        for (int i=0; i<(1<<n); i++) {
            if (__builtin_popcount(i)>3) continue;
            if (n+(3-__builtin_popcount(i))>5) continue;
            int p = __builtin_popcount(i);
            if (p==3) {
                int sum = 0;
                for (int j=0; j<n; j++) if ((1<<j)&i) sum += a[j];
                if (sum%1024!=0) continue;
            }
            int sum = 0;
            for (int j=0; j<n; j++) if (((1<<j)&i)==0) {
                sum += a[j];
            }
            if (sum%1024==0 && sum!=0) sum = 1024;
            else sum %= 1024;
            int rest = 5-n;
            rest -= (3-p);
            if (rest>0) sum = 1024;
            best = max(best, sum);
        }
        best %= 20121014;
        printf("%d\n",best);
    }

    return 0;

}
