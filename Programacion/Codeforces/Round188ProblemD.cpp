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

int n;
bool is[300000];
int q[300000];
map<int,int> mem;
int gn[31] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

int solve(int m) {
	if (m==0) return 0;
	if (mem[m]) return mem[m];
	
	bool v[33];
	for (int i=0; i<30; i++) v[i] = 0;
	
	for (int i=2; i<30; i++) if ((1<<(i-1))&m) {
		int m2 = m;
		
		for (int j=i; j<30; j+=i) if ((1<<(j-1))&m2) m2 -= (1<<(j-1));
		
		v[solve(m2)] = 1;
	}
	
	for (int i=1; i<30; i++) if (!v[i]) {
		mem[m] = i;
		return i;
	}
	
	return 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	int c = 0;
	int k = 0;
	for (int i=2; (long long)i*i<=n; i++) is[i] = 1;
	for (int i=2; (long long)i*i<=n; i++) if (is[i]) {
		int t = 0;
		for (long long j=i; j<=n; j*=i) {
			c++; t++;
			if (j*j<=n) is[j] = 0;
		}
		q[k++] = t;
	}
	q[k++] = (n-c)%2; 
	
	//for (int i=1; i<30; i++) gn[i] = solve((1<<i)-1);
	
	//for (int i=1; i<30; i++) cout<<gn[i]<<" "; cout<<endl;
	
	int now = 0;
	
	for (int i=0; i<k; i++) now ^= gn[q[i]];
	
	now?printf("Vasya"):printf("Petya");

    return 0;

}
