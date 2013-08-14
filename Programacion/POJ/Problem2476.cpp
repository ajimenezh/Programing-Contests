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
string name[1010];	
vector<int> e[1010];
bool done[1010], vis[1010];	

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>n && n!=0) {
		for (int i=0; i<n; i++) e[i].clear();
		for (int i=0; i<n; i++) {
			string s;
			cin>>s;
			name[i] = s;
		}
		for (int i=0; i<n-1; i++) {
			string s1,s2;
			cin>>s1>>s2;
			int a = distance(name,lower_bound(name,name+n,s1));
			int b = distance(name,lower_bound(name,name+n,s2));
			e[a].push_back(b);
			e[b].push_back(a);
		}
		
		for (int i=0; i<n; i++) vis[i] = 0;
		for (int j=0; j<n; j++) done[j] = 0;
		int r = n;
		int round = 1;
		while (r>1) {
			for (int i=0; i<n; i++) vis[i] = done[i];
			int wc = -1, el = 0;
			printf("Round #%d\n",round++);
			for (int i=0; i<n; i++) {
				if (vis[i]) continue;
				if (e[i].size()==1) {
					int opponent = e[i][0];
					if (vis[opponent]) {
						wc = i;
						vis[i] = 1;
						continue;
					}
					vis[i] = vis[opponent] = 1;
					printf("%s defeats %s\n",name[opponent].c_str(),name[i].c_str());
					done[i] = 1;
					el++;
					vector<int>::iterator it = lower_bound(e[opponent].begin(),e[opponent].end(),i);
					e[opponent].erase(it);
				}
			}
			if (r%2!=0) {
				for (int i=0; i<n && wc<0; i++) {
					if (!vis[i]) 
						wc = i;
				}
				printf("%s advances with wildcard\n",name[wc].c_str());
			}
			r = (r+1)/2;
		}
		for (int i=0; i<n; i++) {
			if (!done[i]) {
				printf("Winner: %s\n",name[i].c_str());
				break;
			}
		}
		cout<<endl;
		
	}
			
	
    return 0;

}
