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
int l[51000];
int pr[51000];
int p[51000];

bool cmp(int i, int j) {
    return (l[i]*pr[i]*(100-pr[j])>l[j]*pr[j]*(100-pr[i])) ;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d%d",l+i,pr+i);
        p[i] = i;
    }
    sort(p,p+n,cmp);

    long long sum = 0;
    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans += l[p[i]]*10000;
        ans += (long long)(100-pr[p[i]])*sum;
        sum += l[p[i]]*pr[p[i]];
    }

    printf("%.12f\n",(double)ans/10000.0);

    return 0;

}
