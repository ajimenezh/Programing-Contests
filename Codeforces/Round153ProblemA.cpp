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
long long d;
long long p[100010];

int main() {

    cin>>n>>d;
    for (int i=0; i<n; i++) scanf("%I64d",&p[i]);

    long long sum = 0;
    int x = 0;
    int i = 0;
    int j = 0;

    for (int i=0; i<n; i++)
    {
        int k;
        for (k=j; k<i; k++) if (abs(p[i]-p[k])<=d) break;
        //cout<<k<<" "<<i<<endl;
        sum += (long long)(i-k)*(long long)(i-k-1LL)/2LL;
        j = k;

        //cout<<j<<" "<<sum<<endl;
    }

    cout<<sum<<endl;

	return 0;

}
