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

int a[101];
int n,m;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    cin>>m;
    for (int i=0; i<m; i++) {
        int k,t;
        cin>>k>>t;
        k--;
        if (k==0) {
            a[k+1] += a[k]-t;
        }
        else if (k==n-1) {
            a[k-1] += t-1;
        }
        else {
            a[k+1] += a[k]-t;
            a[k-1] += t-1;
        }
        a[k] = 0;
    }

    for (int i=0; i<n; i++) cout<<a[i]<<endl;

    return 0;

}
