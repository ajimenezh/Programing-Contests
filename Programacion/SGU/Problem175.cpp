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

int n,q;

int solve(int m, int c) {
	
	if (m==1) return c;
	
	int k = m/2;
	
	if (c>=k) {
		return solve(m-k, m-c-1);
	}
	else {
		return (m-k) + solve(k,k-c-1);
	}
} 

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>q;
	
	cout<<solve(n,q-1)+1;

    return 0;

}
