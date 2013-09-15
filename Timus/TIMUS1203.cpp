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
pair<int,int> v[100010];
int s[30010];
void update(int i, int x) {
    for (;i<=30000; i+=i&-i) s[i] = max(s[i],x);
}
int get(int i) {
    if (i<1) return 0;
    int x = 0;
    for (;i>=1; i-=i&-i) x = max(x,s[i]);
    return x;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&v[i].first,&v[i].second);
    }
    sort(v,v+n);

    int ans = 0;
    for (int i=0; i<n; i++) {
        int tmp = get(v[i].first-1) + 1;
        ans = max(ans,tmp);
        update(v[i].second,tmp);
    }
    cout<<ans<<endl;

    return 0;

}
