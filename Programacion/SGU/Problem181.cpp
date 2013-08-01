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

int a,alp,bet,gam,m,k;
int id[1020];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>a>>alp>>bet>>gam>>m>>k;
	
	if (k==0) {
		cout<<a<<endl;
		return 0;
	}
	
	int x = a%m;
	id[x] = 1;
	
	if (k<=m) {
		for (int i=1; i<=k; i++) {
			x = ((x*x)%m*alp + x*bet + gam)%m;
		}
		cout<<x<<endl;
	}
	else {
		int last;
		int c = 1;
		for (int i=1; i<=m; i++) {
			x = ((x*x)%m*alp + x*bet + gam)%m;
			if (id[x]>0) {
				last = id[x]-1;
				break;
			}
			id[x] = i+1;
			c++;
		}
		k -= last;
		c -= last;
		k %= c;
		for (int i=1; i<=k; i++) {
			x = ((x*x)%m*alp + x*bet + gam)%m;
		}
		cout<<x<<endl;
	}

    return 0;

}
