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

int n,k;
int a[200010];
long long c1[200010];
long long c2[200010];
long long tot[200010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=1; i<n; i++) c1[i] = c1[i-1] + (long long)a[i-1]*(long long)(i-1);
    for (int i=0; i<n; i++) c2[i] = (long long)a[i]*(long long)i*(long long)(n-(i+1));
    for (int i=0; i<n; i++) tot[i] = c1[i] - c2[i];
    //for (int i=0; i<n; i++) cout<<tot[i]<<" "; cout<<endl;

    long long sum = 0;
    long long val = 0;

    int cnt = 0;

    for (int i=1; i<n; i++) {
        c1[i] = c1[i] - sum - val;
        c2[i] = c2[i] - (long long)cnt*(long long)a[i]*(long long)(n-(i+1));
        tot[i] = c1[i] - c2[i];
        //cout<<i<<" "<<tot[i]<<endl;
        if (tot[i]<k) {
            printf("%d\n",i+1);
            sum += (long long)a[i]*(long long)(i);
            cnt++;
        }
        else {
            val += (long long)cnt*(long long)a[i];
        }
    }


    return 0;

}
