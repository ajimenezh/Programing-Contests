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

int n,l;
int a[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>l;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    int best = 0;
    for (int i=l; i<101; i++) {
        int k = 0;
        for (int j=0; j<n; j++) {
            k += a[j]/i;
        }
        best = max(best, i*k);
    }

    cout<<best<<endl;

    return 0;

}
