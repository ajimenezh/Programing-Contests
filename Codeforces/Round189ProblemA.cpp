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

#define mod 1000000007LL

long long fastpow(long long a, int b) {
    if (b==0) return 1LL;
    long long tmp = fastpow(a,b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (tmp*a)%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    cin>>s;

    long long tot = 0;
    long long f = fastpow(2,s.length()-1);

    for (int i=s.length()-1; i>=0; i--) {
        if (s[s.length()-1-i]=='1') tot = (tot + (f*fastpow(2LL,i))%mod)%mod;
    }

    cout<<tot<<endl;

    return 0;

}
