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
int t1,t2;

long long fpow(long long a, int b) {
    if (b==0) return 1;
    long long tmp = fpow(a,b/2);
    tmp = (tmp*tmp)%1000000007;
    if (b%2==0) return tmp;
    return (tmp*a)%1000000007;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        cin>>a;
        if (a==1) t1++;
        else t2++;
    }

    long long c1 = 1, c2 = 1;
    if (t1>0) c2 = 1;
    if (t1>1) {c2 = 2; c1 = 1;}
    for (int i=2; i<t1; i++) {
        long long tmp = (c2 + c1*i)%1000000007;
        c1 = c2;
        c2 = tmp;
    }

    for (int i=1; i<=n; i++) {
        c2 = (c2*i)%1000000007;
    }
    long long inv = 1;
    for (int i=1; i<=t1; i++) {
        inv = (inv*i)%1000000007;
    }
    c2 = (c2*fpow(inv,1000000005))%1000000007;

    cout<<c2<<endl;

    return 0;

}
