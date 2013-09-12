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

#define mod 1000000007

long long m;

long long fast_pow(long long a, int n) {
    if (n==0) return 1LL;
    if (n==1) return a;
    long long tmp = fast_pow(a,n/2);
    if (n%2==0) return tmp*tmp;
    return a*tmp*tmp;
}

long long number(int a, int j) {
    long long c = 0;

    long long n = m;
    long long f = 1;
    int t=0;
    while (n>0) {n /= 10; f *= 10; t++;}
    f /= 10;

    t--;

    n = m;

    j = min(t,j);
    if (t!=j) for (int i=j; i<t; i++) {
        n = n%f;
        f /= 10;
    }

    t = j;

    while (f>0) {
        int k = n/f;
        n = n - k*f;
        f /= 10;

        if (k<4) {if (t>=a) c += (k)*fast_pow(2,a)*fast_pow(8,t-a);}
        else if (k<7) {
            if (t>=a) c += (k-1)*fast_pow(2,a)*fast_pow(8,t-a);
            if (t>=a-1) c += fast_pow(2,a-1)*fast_pow(8,t-(a-1));
        }
        else {
            if (t>=a) c += (k-2)*fast_pow(2,a)*fast_pow(8,t-a);
            if (t>=a-1) c += 2*fast_pow(2,a-1)*fast_pow(8,t-(a-1));
        }
        t--;
    }

    return c;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>m;

    cout<<number(1,10);

    return 0;

}
