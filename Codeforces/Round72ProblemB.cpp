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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
long long k;
int a[100010];

long long solve(long long c) {
    long long tmp = 0;

    for (int i=0; i<n; i++) {
        tmp += min((long long)a[i],c);
    }

    return tmp;
}

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

   	cin>>n>>k;
   	for (int i=0; i<n; i++) scanf("%d",&a[i]);

   	long long lo = 0;
   	long long hi = 1000000000000000LL;

   	long long sum = 0;

   	for (int i=0; i<n; i++) sum += a[i];

   	if (sum<k) {cout<<-1; return 0;}

   	while (lo<hi) {
        long long mi = lo + (hi-lo)/2;
        long long k2 = solve(mi);
        long long k3 = solve(mi+1);
        //cout<<mi<<" "<<k2<<" "<<k3<<endl;
        if (k2<=k && k3>=k) {
            k -= k2;
            int last = -1;
            for (int i=0; i<n; i++) {
                if (a[i]>mi && k>0) k--;
                else {
                    if (a[i]>mi && k==0) cout<<i+1<<" ";
                    if (a[i]>mi && k==0 && last ==-1) last = i;
                }
            }
            if (last==-1) last = n;
            for (int i=0; i<last; i++) if (a[i]>mi+1) cout<<i+1<<" ";
            break;
        }
        if (k3<k) lo = mi;
        if (k2>k) hi = mi;
   	}


	return 0;

}
