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
int c1[1000010];
int c2[1000010];
int sum[1000010];
int l[1000010];
pair<int,int> v1[1000010];
pair<int,int> v2[1000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n; 
	int m = 0;
	for (int i=0; i<n; i++) {
		string s;
		cin>>s; 
		for (int j=0; j<s.length(); j++) {
			if (s[j]=='S') c1[j]++;
			else c2[j]++;
		}
		m = max(m,(int)s.length());
		l[s.length()-1]++;
	}
	for (int i=0; i<m; i++) {
		v1[i] = make_pair(c1[i],i);
		v2[i] = make_pair(c2[i],i);
	}
	
	sort(v1,v1+m);
	sort(v2,v2+m);
	
	int last = m;
	int now = 0;
	int t = 0;
	
	for (int i=0; i<m; i++) {
		cout<<v1[i].first<<" "<<v1[i].second<<" "<<l[v1[i].second]<<endl;
		if (v1[i].first>now && v1[i].second<last) {
			int tmp = min(l[v1[i].second],v1[i].first - now);
			now += tmp;
			if (tmp>0) last = v1[i].second;
			l[v1[i].second] -= tmp;
			t += tmp;
		}
	}
	
	now = 0;
	last = m;
	for (int i=0; i<n; i++) {
		cout<<v2[i].first<<" "<<v2[i].second<<" "<<l[v2[i].second]<<endl;
		if (v2[i].first>now && v2[i].second<last) {
			int tmp = min(l[v2[i].second],v2[i].first - now);
			now += tmp;
			last = v2[i].second;
			l[v2[i].second] -= tmp;
			t += tmp;
		}
	}
	
	cout<<t<<endl;

    return 0;

}
