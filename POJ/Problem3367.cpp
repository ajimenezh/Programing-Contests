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

pair<int,int> edge[20000];
int cnt;
char id[20000];
vector<int> e[20000];
pair<int,int> dist[20000];
pair<pair<int,int>,int > w[20000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int n;
	cin>>n;
	while (n--) {
		string s;
		cin>>s;
		
		vector<int> v;
		int i = 0;
		cnt = 0;
		int m = 0;
		while (i<s.length()) {
			if (s[i]>='A' && s[i]<='Z') {
				id[cnt] = s[i];
				int p = v.back();
				v.pop_back();
				int q = v.back();
				v.pop_back();
				edge[m++] = make_pair(p,cnt);
				edge[m++] = make_pair(q,cnt);
				v.push_back(cnt);
			}
			else {
				id[cnt] = s[i];
				v.push_back(cnt);
			}
			i++;
			cnt++;
		}
		for (int i=0; i<cnt; i++) e[i].clear();
		for (int i=0; i<m; i++) {
			e[edge[i].first].push_back(edge[i].second);
			e[edge[i].second].push_back(edge[i].first);
		}
		
		queue<int> q;
		q.push(cnt-1);
		int cur = cnt-1;
		int top = cur + 1;
		cnt = 0;
		for (int i=0; i<top; i++) dist[i] = mp(-1,-1);
		dist[cur] = mp(0,cnt);
		
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			
			for (int i=0; i<e[cur].size(); i++) {
				if (dist[e[cur][i]].first==-1) {
					dist[e[cur][i]] = make_pair(dist[cur].first+1,-cnt++);
					q.push(e[cur][i]);
				}
			}
		}

		for (int i=0; i<top; i++) w[i] = (make_pair(dist[i],i));
		sort(w,w+top);
		reverse(w,w+top);
		s = "";
		string tmp = "";
		for (int i=0; i<top; i++) {
			printf("%c",id[w[i].second]);
		}
		cout<<endl;
	}
	
    return 0;

}
