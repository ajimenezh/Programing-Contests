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
int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    sort(a,a+n);

    int lo = 0;
    int hi = n/2;
    while (lo<hi) {
        int mi = (lo+hi+1)/2;
        bool good = 1;
        for (int j=mi-1; j>=0; j--) {
            cout<<a[j]<<" "<<a[n-(mi-j)]<<endl;
            if (2*a[j]>a[n-(mi-j)]) {
                good = 0;
                break;
            }
        }
        cout<<lo<<" "<<hi<<" "<<mi<<" "<<good<<endl;
        if (good) {
            lo = mi;
        }
        else hi = mi-1;
    }

    cout<<(n-lo)<<endl;

    return 0;

}
