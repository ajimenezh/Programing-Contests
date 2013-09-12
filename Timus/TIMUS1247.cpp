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

int n,s;
int a[30010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>s;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) a[i]--;

    int sum = 0;
    int m = -10;
    for (int i=0; i<n; i++) {
        sum += a[i];
        m = max(sum,m);
        if (sum<0) sum = 0;
    }

    if (m<=s) cout<<"YES";
    else cout<<"NO";

    return 0;

}
