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
pair<int,int> v[110];

int calc(int a, int b) {
    if (a<b) return calc(b,a);
    if (a==b || b==0) return 0;
    return 1 + calc(b, a%b);
}

void solve() {
    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        v[i] = make_pair(a,b);
    }

    int k = 0;

    for (int i=0; i<n; i++) {
        int t = calc(v[i].first, v[i].second)%2;
        k = (k^t);
    }
    if (k==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        solve();
    }

    return 0;

}
