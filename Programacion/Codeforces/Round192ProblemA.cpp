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
string s[101];
vector<pii> v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) cin>>s[i];
	
	bool done = 1;
	for (int i=0; i<n; i++) {
		bool ok = 0;
		for (int j=0; j<n; j++) {
			if (s[i][j]!='E') {
				ok = 1;
				v.push_back(mp(i+1,j+1));
				break;
			}
		}
		if (!ok) {
			done = 0;
			break;
		}
	}
	if (done) {
		for (int i=0; i<n; i++) cout<<v[i].first<<" "<<v[i].second<<endl;
		return 0;
	}
	
	v.clear();
	done = 1;
	for (int i=0; i<n; i++) {
		bool ok = 0;
		for (int j=0; j<n; j++) {
			if (s[j][i]!='E') {
				ok = 1;
				v.push_back(mp(j+1,i+1));
				break;
			}
		}
		if (!ok) {
			done = 0;
			break;
		}
	}
	if (!done) cout<<-1<<endl;
	else {
		for (int i=0; i<n; i++) cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	

    return 0;

}
