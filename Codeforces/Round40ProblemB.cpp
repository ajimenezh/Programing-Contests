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

int n,b;
int a[2010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>b;
    for (int i=0; i<n; i++) cin>>a[i];
    int best = b;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int k = b/a[i];
            int bb = b-k*a[i];
            int tmp = a[j]*k+bb;
            best = max(best, tmp);
        }
    }
    cout<<best<<endl;

    return 0;

}
