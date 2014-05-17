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
long long p[1000000];
long long v[1000000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d", v+i);

    p[0] = 0;
    for (int i=1; i<=n; i++) p[i] = i^p[i-1];

    long long all = 0;
    for (int i=1; i<=n; i++) {
        long long k = n%i;
        long long tmp = ((n/i)%2)*p[i-1];
        all ^= (p[k]^tmp);
    }
    for (int i=0; i<n; i++) all ^= v[i];

    cout<<all<<endl;

    return 0;

}
