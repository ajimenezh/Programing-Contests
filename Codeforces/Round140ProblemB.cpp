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

int n,q,k;
long long now;
long long a[100010];
long long dp[100010];
long long sum[100010];

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%I64d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    for (int i=n-1; i>=0; i--) i==n-1 ? sum[i] = a[i] : sum[i] = a[i] + sum[i+1];
    //for (int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
    //for (int i=0; i<n; i++) cout<<sum[i]<<" "; cout<<endl;
    cin>>q;

    for (int i=0; i<100010; i++) dp[i] = -1;

    for (int qq=0; qq<q; qq++)
    {
        scanf("%d",&k);
        if (dp[k]!=-1) {printf("%I64d ",dp[k]); continue;}
        long long s = 0;
        int c = 1;
        long long f = 1;
        now = k;
        int i;
        while(true) {
            if (f+now<n) {
                //cout<<f<<" "<<f+now<<endl;
                s += c*(sum[f] - sum[f+now]);
            }
            else {
                if (f>=n) break;
                //cout<<f<<endl;
                s += c*(sum[f]);
                break;
            }
            c++;
            f = f + now;
            now = now*k;
        }
        dp[k] = s;
        printf("%I64d ",s);
    }

    cout<<endl;

	return 0;

}
