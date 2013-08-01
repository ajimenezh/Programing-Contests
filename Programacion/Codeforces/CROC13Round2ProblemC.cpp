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

#define eps 1.0e-6

long long n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	int res = 0;
	
	if (n%3!=0) {
		cout<<0<<endl;
		return 0;
	}
	
	n /= 3;
	
	for (int i=1; (long long)i*i<=n; i++) {
		for (int j=i; (long long)i*i*j+(long long)i*j*j<=n/(i+j); j++) {
			long long k = n - (long long)i*i*j - (long long)i*j*j;
			if (k%(i+j)!=0 || (i+j)%2!=0) continue;
			long long delta = (long long)(i+j)*(i+j)/4 + (long long)k/(i+j);
			if (abs(sqrt(delta)*sqrt(delta)-delta)>eps) continue;
			long long c = -(long long)(i+j)/2 + (long long)sqrt(delta);
			if (j==i && c==j) res++;
			if (j>i && c==j) res += 3;
			if (j>i && c>j) res += 6;
		}
	}
	if (n%8==0) res++;
	cout<<res<<endl;
			

    return 0;

}
