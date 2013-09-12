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
pair<int,int> v[16010];

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.first!=b.first) return a.first<b.first;
	else return a.second>b.second;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		v[i] = make_pair(a,b);
	}
	
	sort(v,v+n,cmp);
	
	int ans = 0;
	int last = -1;
	
	for (int i=0; i<n; i++) {
		int j;
		int tmp = -1;
		for (j=i; j<n && v[j].first==v[i].first; j++) {
			if (v[j].second>=last) tmp = max(tmp,v[j].second);
			else ans++;
		}
		last = max(last,tmp);
		i = j-1;
	}
	
	cout<<ans;

    return 0;

}
