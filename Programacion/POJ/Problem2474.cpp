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
int a[10];
int ans;
vector<int> res;
int p[10];

int solve(int k, vector<int> v) {
	if (v.size()>=ans) return 1000;
	if (k==n) {
		if (ans>v.size()) {
			ans = v.size();
			res = v;
		}
	}
	
	int tmp = 100;
	
	for (int i=0; i<v.size(); i++) {
		for (int j=i+1; j<v.size(); j++) {
			if (a[p[k]]==v[j]-v[i]) {
				tmp = min(tmp, solve(k+1,v));
			}
		}
	}
	
	for (int i=0; i<v.size(); i++) {
		vector<int> w = v;
		w.push_back(v[i]+a[p[k]]);
		sort(w.begin(),w.end());
		tmp = min(tmp,1+solve(k+1,w));
	}
	for (int i=0; i<v.size(); i++) {
		vector<int> w = v;
		w.push_back(v[i]-a[p[k]]);
		sort(w.begin(),w.end());
		tmp = min(tmp,1+solve(k+1,w));
	}
	
	return tmp;
}
	

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	for (int tt=1; tt<=t; tt++) {
		cin>>n;
		for (int i=0; i<n; i++) cin>>a[i];
		
		ans = 1000;
		for (int i=0; i<n; i++) p[i] = i;
		solve(0,vector<int>(1,0));
		for (int i=0; i<10; i++) {
			random_shuffle(p,p+n);
			solve(0,vector<int>(1,0));
		}
		cout<<"Scenario #"<<tt<<endl;
		cout<<ans<<": ";
		if (res[0]<0) for (int i=res.size()-1; i>=0; i--) res[i] -= res[0];
		for (int i=0; i<res.size(); i++) cout<<res[i]<<" ";
		cout<<endl;
	}
	
    return 0;

}
