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
map<string,set<string> > group;
vector<string> v;
map<string,bool> done;

set<string> solve(string m) {
	set<string> tmp = group[m];
	if (done[m]) return tmp;
	rep(it,group[m]) {
		if (group.find(*it)!=group.end()) {
			set<string> tmp2 = solve(*it);
			rep(it2,tmp2) tmp.insert(*it2);
			tmp.erase(*it);
		}
	}
	done[m] = 1;
	group[m] = tmp;
	return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		group.clear();
		v.clear();
		done.clear();
		for (int i=0; i<n; i++) {
			string s;
			cin>>s;
			for (int j=0; j<s.length(); j++) if (s[j]==':') {
				s[j] = ' ';
				break;
			}
			stringstream ss(s);
			string name;
			ss>>name;
			set<string> vs;
			ss>>s;
			for (int j=0; j<s.length(); j++) {
				if (s[j]=='.' || s[j]==',') s[j]=' ';
			}
			stringstream ss2(s);
			while (ss2>>s) {
				vs.insert(s);
			}
			group[name] = vs;
			v.push_back(name);
			done[name] = 0;
		}
		
		for (int i=0; i<n; i++) {
			group[v[i]] = solve(v[i]);
		}

		int ans = group[v[0]].size();
		
		cout<<ans<<endl;
		
	}

    return 0;

}
