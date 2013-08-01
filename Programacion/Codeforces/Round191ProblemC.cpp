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

const int mod = 1000000007;

string a;
long long k;
long long res;

long long fpow(long long a, long long b) {
	if (b==0) return 1;
	long long tmp = fpow(a,b/2);
	tmp = (tmp*tmp)%mod;
	if (b%2==0) return tmp;
	return (a*tmp)%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>a>>k;
	
	int n = a.length();
	
	for (int i=0; i<n; i++) {
		if (a[i]=='0' || a[i]=='5') {
			long long t = (fpow(2,i)*fpow(2,(k)*n))%mod;
			t = (t - fpow(2,i) + mod)%mod;
			t = (t*fpow((fpow(2,n)-1+mod)%mod,mod-2))%mod;
			res += t;
			res %= mod;
		}
	}
	
	cout<<res<<endl;

    return 0;

}
