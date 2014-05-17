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
long long j;
pair<long long, long long> m0;
pii a[100010];

int main() {

    cin>>n>>j;
    cin>>m0.first>>m0.second;
    fo(i,n)
    {
        int x,y;
        cin>>x>>y;
        a[i] = mp(x,y);
    }

    j = j%(long long)(2*n);
    for (int i=0; i<j; i++) {
        m0.first = 2LL*a[i%n].first - m0.first;
        m0.second = 2LL*a[i%n].second - m0.second;
    }


    cout<<m0.first<<" "<<m0.second<<endl;

	return 0;

}
