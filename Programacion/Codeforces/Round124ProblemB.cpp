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

int vis[1510][1510];
bool done[1510][1510];
bool ady[1510][1510];
string s[1510];
int n,m;
bool good;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool dfs(int i, int j, int a, int b) {
	if (!ady[i][j]) return false;
	if (done[i][j] && vis[i][j]!=(a+256)*1024+(b+256)) {
		//cout<<a<<" "<<b<<" "<<endl;
		//cout<<i<<" "<<j<<endl;
		return true;
	}
	if (done[i][j]) return false;
	vis[i][j] = (a+256)*1024+(b+256);
	done[i][j] = 1;
	
	bool flag = 0;
	
	for (int k=0; k<4; k++) {
		int x = i+dx[k];
		int y = j+dy[k];
		
		if (x<0) flag |= dfs(n+x,y,a+1,b);
		else if (y<0) flag |= dfs(x,y+m,a,b+1);
		else if (x>=n) flag |= dfs(x-n,y,a-1,b);
		else if (y>=m) flag |= dfs(x,y-m,a,b-1);
		else flag |= dfs(x,y,a,b);
	}
	
	return flag;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) cin>>s[i];
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) ady[i][j] = s[i][j]!='#';
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
		if (s[i][j]=='S') {
			good = dfs(i,j,0,0);
			break;
		}
	}
	
	if (good) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
    return 0;

}
