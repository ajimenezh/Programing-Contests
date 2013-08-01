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
int a[100010];
int b[100010];
int c[100010];
priority_queue<int> q1, q4;
priority_queue<pair<int,int> > q2,q3;
int last;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n;i++) scanf("%d",a+i);
	for (int i=0; i<n;i++) scanf("%d",b+i);
	for (int i=0; i<n; i++) c[a[i]] = i;
	
	for (int i=0; i<n; i++) {
		if (c[b[i]]<=i) {
			q1.push(-(i-c[b[i]]));
		}
		else {
			q2.push(make_pair(-(c[b[i]]-i),i));
			q3.push(make_pair(-(i),c[b[i]]));
		}
	}
	
	last = -1;
	for (int i=0; i<n; i++) {
		int t = n+10;
		if (!q1.empty()) t = min(t, -q1.top()-i);
		while (!q1.empty() && -q1.top()==i) {
			last = i;
			q1.pop();
		}
		if (!q2.empty() && q2.top().second-i>=0) t = min(t, -q2.top().first+i);
		while (!q2.empty() && q2.top().second-i>=0) {
			q2.pop();
		}
		while (!q3.empty() && -q3.top().first==i) {
			q4.push(-(q3.top().second+i));
			q3.pop();
		}
		if (!q4.empty()) t = min(t, -q4.top()-i);
		while (!q4.empty() && -q4.top()==i) {
			last = i;
			q4.pop();
		}
		if (last!=-1) t = min(t, i-last);
		if (last!=-1) t = min(t, n - (i-last));
		printf("%d\n",t);
	}

    return 0;

}
