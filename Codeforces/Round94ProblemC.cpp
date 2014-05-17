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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define mod 1000000007

int n,m,k;

long long fast_pow(long long a, int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    long long tmp = fast_pow(a,b/2)%mod;
    if (b%2==0) return (tmp*tmp)%mod;
    return a*((tmp*tmp)%mod)%mod;
}

long long c(int a, int b) {
    long long num = 1;
    long long den = 1;

    if (b>a) return 0;
    if (b==a || b==0) return 1;


    for (int i=a; i>b; i--) num = (num*i)%mod;
    for (int i=1; i<=(a-b); i++) den = (den*i)%mod;

    //cout<<num<<" "<<den<<endl;

    num %= mod;
    den %=mod;

    return (num*fast_pow(den,mod-2))%mod;
}

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    cin>>n>>m>>k;

    long long res = c(n-1,2*k)*c(m-1,2*k)%mod;

    //cout<<c(n-1,2*k)<<" "<<c(m-1,2*k)<<endl;

    cout<<res;

	return 0;

}
