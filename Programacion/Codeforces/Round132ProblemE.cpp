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

int sgn[100];


long long solve(long long k) {
	if (k==0) return 0;
	long long sum = 0;
	
	for (int i=1; i<=60; i++) for (int j=2; j*i<=60; j++) if (sgn[j]==-1) {
		if ((1LL<<(i*j))<=k) {
			sum += -(1LL<<(i-1))*sgn[j];
			cout<<i<<" "<<j<<" "<<(1LL<<(i-1))<<" "<<sgn[j]<<endl;
		}
		else {
			if ((1LL<<(i*j))>(k<<1LL)) continue;
			cout<<i<<" "<<j<<" "<<sum<<endl;
			long long tmp = k;
			while ((1LL<<(i))<=tmp) tmp >>= 1LL;
			long long tmp2 = k;
			for (int p=0; p<j; p++) {
				tmp = min(tmp, tmp2%(1<<(long long)i));
				tmp2 >>= (long long)i;
			}
			cout<<tmp<<" "<<i<<" "<<(tmp - (1LL<<(i-1)) + 1)<<endl;
			sum += -abs(tmp - (1LL<<(i-1)) + 1)*sgn[j];
			cout<<sgn[i]<<endl;
		}
	}
	
	return sum;
} 

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	sgn[1] = 1;
	
	for (int i=1; i<100; i++) for (int j=2*i; j<100; j += i) sgn[j] = -sgn[i];
	
	long long a,b;
	cin>>a>>b;
	
	long long ans = solve(b) - solve(a-1);
	
	cout<<ans<<endl;

    return 0;

}
