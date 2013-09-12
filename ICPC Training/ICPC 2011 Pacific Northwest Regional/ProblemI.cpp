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

map<char,int> id;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int to[8][4];
int m,n;
vector<int> e[400][8];

pair<int,int> dfs(int t, int p) {
	if (e[t][p].size()==0) return make_pair(t,p);
	for (int i=0; i<4; i++) {
		int x = t/m + dx[i];
		int y = t%m + dy[i];
		if (x<0 || x>=n || y<0 || y>=m) {
			if (to[e[t][p][0]][i]==-1) continue;
			return make_pair(t,e[t][p][0]);
		}
		if (to[e[t][p][0]][i]==-1) continue;
		return dfs(x*m+y,to[e[t][p][0]][i]);
		break;
	}
	return make_pair(t,p);
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	id['A'] = 0;
	id['B'] = 1;
	id['C'] = 2;
	id['D'] = 3;
	id['E'] = 4;
	id['F'] = 5;
	id['G'] = 6;
	id['H'] = 7;
	
	for (int i=0; i<8; i++) for (int j=0; j<4; j++) to[i][j] = -1;
	
	to[0][2] = 5;
	to[1][2] = 4;
	to[2][3] = 7;
	to[3][3] = 6;
	to[4][0] = 1;
	to[5][0] = 0;
	to[6][1] = 3;
	to[7][1] = 2;
	
	int cas = 1;
	while (cin>>n>>m && n!=0) {
		string s2;
		getline(cin,s2);
		for (int i=0; i<m*n; i++) for (int j=0; j<8; j++) e[i][j].clear();
		for (int i=0; i<=m*n; i++) {
			int t = 0;
			cin>>t;
			if (t==0) break;
			t--;
			string s;
			getline(cin,s);
			stringstream ss(s);
			while (ss>>s) {
				e[t][id[s[0]]].push_back(id[s[1]]);
				e[t][id[s[1]]].push_back(id[s[0]]);
			}
		}
		string s;
		getline(cin,s);
		cout<<"Board "<<cas++<<":"<<endl;
		getline(cin,s);
		stringstream ss(s);
		while (ss>>s) {
			int from = id[s[s.length()-1]];
			string str = s;
			s = s.substr(0,s.length()-1);
			int t = atoi(s.c_str()) - 1;
			pair<int,int> p = dfs(t, from);
			cout<<str<<" is connected to "<<p.first+1<<char(p.second+'A')<<endl;
		}
	}
			
	
    return 0;

}
