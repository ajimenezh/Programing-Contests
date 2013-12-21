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


const int mod = 1000000007;
int n,x;
int a[100010];

int fpow(int a, long long b) {
    if (b==0) return 1;
    int tmp = fpow(a,b/2);
    tmp = ((long long)tmp*tmp)%mod;
    if (b%2LL==0) return tmp;
    return ((long long)a*tmp)%mod;
}

map<long long,int> v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>x;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    long long sum = 0;
    for (int i=0; i<n; i++) sum = (sum+a[i]);
    for (int i=0; i<n; i++) v[sum-a[i]]++;
    int tot = 0;
    long long e = 0;
    while (true) {
        long long c = 0;
        if (v.size()==0 || (*v.begin()).first==0) break;
        c = (*v.begin()).first;
        int tot = (*v.begin()).second;
        e = c;
        if (tot%x==0) {
            v.erase(v.begin());
            v[c+1]+=tot/x;
        }
        else break;
    }
    int ans = fpow(x,e);
    cout<<ans<<endl;
    return 0;

}
