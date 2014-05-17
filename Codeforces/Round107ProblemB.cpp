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

#define mod 1000000007
int main() {

    int n,m,k;
    cin>>n>>m>>k;
    long long res = 0;
    if (k==1)
    {
        res = 1;
        for (int i=0; i<n; i++) res = (res*m)%mod;
    }
    else if (k%2==1 && k<n)
    {
        res = m*m;
    }
    else if (k<n)
    {
        res = m;
    }
    else
    {
        res = 1;
        if (k==n) n = (n+1)/2;
        for (int i=0; i<n; i++) res = (res*m)%mod;
    }

    cout<<res<<endl;

	return 0;

}
