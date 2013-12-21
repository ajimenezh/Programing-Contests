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

long long fpow(long long a, int b, int m) {
    if (b==0) return 1;
    long long tmp = fpow(a,b/2, m);
    tmp = (tmp*tmp%m);
    if (b%2==0) return tmp;
    return (a*tmp)%m;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    long long ans = fpow(3,n,m);
    ans--;
    if (ans<0) ans += m;
    cout<<ans<<endl;

    return 0;

}
