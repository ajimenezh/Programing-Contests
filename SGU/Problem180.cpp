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
int a[70000];
int v[70000];
map<int,int> m;
int x[70000];
int c;

void update(int y) {
	for (int i=y; i<=c; i += i & -i) x[i]++;
}

int get(int y) {
	int t = 0;
	for (int i=y; i>0; i-= i & -i) t += x[i];
	return t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	for (int i=0; i<n; i++) v[i] = a[i];
	sort(v,v+n);
	c = 1;
	for (int i=0; i<n; i++) {
		if (i==0 || v[i]!=v[i-1]) m[v[i]] = c++;
	}
	c++;
	for (int i=0; i<=c; i++) x[i] = 0;
	for (int i=0; i<n; i++) a[i] = m[a[i]];
	
	long long t = 0;
	for (int i=0; i<n; i++) {
		t += i-get(a[i]);
		update(a[i]);
	}
	
	cout<<t<<endl;

    return 0;

}
