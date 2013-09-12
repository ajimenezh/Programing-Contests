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
int next[200010];
int last[200010];
int id[200010];
bool done[2000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>q;
	int m = n;
	int i = 0;
	int t = 1;
	while (m>200000) {
		for (int j=0; j<q-1; j++) {
			i = (i+t+n)%n;
			if (done[i]) j--;
		}
		done[i] = 1;
		i = (i+1)%n;
		while (done[i]) i = (i+1)%n;
		if (i%2==0) t = 1;
		else t = -1;
		m--;
	}
	
	int cur = i;
	int c = 0;
	
	for (int i=0; i<n; i++) {
		if (!done[i]) {
			id[c++] = i;
		}
		if (i==cur) cur = c-1;
	}
	for (int i=0; i<m; i++) {
		next[i] = (i+1)%m;
		last[i] = (i-1+m)%m;
	}
	
	i = cur;
	while (m--) {
		if (t==1) {
			for (int j=0; j<q-1; j++) i = next[i];
		}
		else {
			for (int j=0; j<q-1; j++) i = last[i];
		}
		//cout<<i<<endl;
		next[last[i]] = next[i];
		last[next[i]] = last[i];
		done[i] = 1;
		i = next[i];
		if (id[i]%2==0) t = 1;
		else t = -1;
		//cout<<i<<endl;
	}
	
	cout<<id[i]+1<<endl;
		

    return 0;

}
