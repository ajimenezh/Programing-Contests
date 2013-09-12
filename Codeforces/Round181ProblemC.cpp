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

int a,b,n;
long long fa[1000010];

int next(int k) {
    vector<int> v;
    while (k>0) {v.push_back(k%10); k/=10;}
    int r = 1;
    for (int i=0; i<v.size(); i++) {
        if (r==1) {
            if (v[i]==a) {
                v[i] = b;
                r = 0;
            }
            else {
                v[i] = a;
            }
        }
    }
    if (r) v.push_back(a);
    int f = 1;
    k = 0;
    for (int i=0; i<v.size(); i++) {k += v[i]*f; f *= 10;}
    return k;
}

long long fast_pow(long long i, long long j) {
    if (j==0) return 1;
    if (j==1) return i;
    long long tmp = fast_pow(i,j/2)%1000000007LL;
    if (j%2==0) return (tmp*tmp)%1000000007LL;
    tmp = (tmp*tmp)%1000000007LL;
    return (i*tmp)%1000000007LL;
}

long long fact(int k) {
    return fa[k];
}

long long c (int c1,int c2) {
    return fact(c1)*(fast_pow(fact(c2)*fact(c1-c2)%1000000007LL,1000000007LL-2))%1000000007LL;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b>>n;
    int k = a;
    fa[0] = 1;
    for (int i=1; i<=n; i++) fa[i] = (fa[i-1]*(long long)i)%1000000007LL;
    long long res = 0;
    while (k<=9000000) {
        if ((k-b*n)%(a-b)==0 && (k-b*n)/(a-b)>=0 && (k-b*n)/(a-b)<=n) {
            res = (res + c(n,(k-b*n)/(a-b)))%1000000007LL;
            //cout<<k<<" "<<(k-b*n)/(a-b)<<endl;
            //cout<<res<<endl;
        }
        k = next(k);
        //cout<<k<<endl;
    }

    cout<<res<<endl;


    return 0;

}
