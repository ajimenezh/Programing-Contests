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

#define INF 10000000000000000LL

int n, q;
int v[100010];
int c[100010];


long long sol[100010];

long long solve(int x, int y) {

    pair<long long,int> max1;
    pair<long long,int> max2;
    bool done = 0;

    for (int i=0; i<n; i++) sol[i+1] = -INF;

    long long ans = 0;
    for (int i=0; i<n; i++) {
        if (i==0) {
            long long val = (long long)y*v[i];
            max1 = make_pair(val, c[i]);
            sol[c[i]] = val;
            ans = max(ans,val);
        }
        else {
            long long cur;
            cur = sol[c[i]];
            cur = max(cur + (long long)x*v[i], (long long)y*v[i]);
            long long rest;
            if (max1.second==c[i]) {
                rest = max2.first;
            }
            else rest = max1.first;
            if (rest>-INF) rest =  rest + (long long)y*v[i];

            sol[c[i]] = max(sol[c[i]], max(rest,cur));

            long long val = max(rest,cur);

            if (val>max1.first) {
                if (max1.second!=c[i]) {
                    max2 = max1;
                    max1 = make_pair(val, c[i]);
                }
                else {
                    max1 = make_pair(val, c[i]);
                }
            }
            else if (val>max2.first) {
                if (max1.second!=c[i]) {
                    max2 = make_pair(val, c[i]);
                }
            }

            ans = max(ans,max(cur,rest));
        }
    }
    return max(ans,0LL);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>q;
    for (int i=0; i<n; i++) scanf("%d",v+i);
    for (int i=0; i<n; i++) scanf("%d",c+i);
    for (int i=0; i<q; i++) {
        int aa,bb;
        scanf("%d%d",&aa,&bb);
        cout<<solve(aa,bb)<<endl;
    }

    return 0;

}
