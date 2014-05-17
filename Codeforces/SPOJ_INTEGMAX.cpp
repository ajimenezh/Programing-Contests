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

int n;
int x[10001];
int y[10001];
int intv[10010];
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=-1) {
        for (int i=0; i<n; i++) scanf("%d",x+i);
        for (int j=0; j<n; j++) scanf("%d",y+j);
        sort(y,y+n);
        reverse(y,y+n);
        for (int i=1; i<n-1; i++) intv[i-1] = x[i]-x[i-1] + x[i+1] - x[i];
        intv[n-2] = x[1]-x[0],0;
        intv[n-1] = x[n-1]-x[n-2];
        sort(intv,intv+n);
        reverse(intv,intv+n);
        long long area = 0;
        for (int i=0; i<n; i++) area += y[i]*intv[i];
        if (area%2LL==0) printf("%I64d.0\n",area/2LL);
        else printf("%I64d.5\n",area/2LL);
    }

    return 0;

}
