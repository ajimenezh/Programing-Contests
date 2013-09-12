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

#define vll vector<long long>
#define vvll vector< vll >

int N,M,A,B,C,T;

int s[55];

vvll mul(vvll a, vvll b) {
	vvll c = vvll(N,vll(N,0)); 
	
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
		long long sum = 0;
		for (int k=0; k<N; k++) {
			sum += a[i][k]*b[k][j]%M;
			sum %= M;
		}
		c[i][j] = sum;
	}
	return c;
}

vvll mpow(vvll a, int e) {
	if (e==1) return a;
	
	vvll c = vvll(N,vll(N,0)); 
	for (int i=0; i<N; i++) {
		c[i][i] = 1;
	}
	
	if (e==0) return c;
	
	c = mpow(a,e>>1);
	c = mul(c,c);
	if (e%2==0) return c;
	return mul(a,c);
}
	

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>N>>M>>A>>B>>C>>T && N!=0) {
		for (int i=0; i<N; i++) cin>>s[i];
		
		vvll trans = vvll(N,vll(N,0));
		
		for (int i=0; i<N; i++) {
			trans[i][i] = B;
			if (i>0) trans[i][i-1] = A;
			if (i<N-1) trans[i][i+1] = C;
		}
		
		trans = mpow(trans,T);
		
		for (int i=0; i<N; i++) {
			long long sum = 0;
			for (int k=0; k<N; k++) {
				sum += (s[k]*trans[i][k])%M;
				sum %= M;
			}
			cout<<sum;
			if (i!=N-1) cout<<" ";
		}
		
		cout<<endl;
	}
	
    return 0;

}
