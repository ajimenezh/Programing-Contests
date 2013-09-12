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

char mapa[35][35];
int n,m;
string dice[6] = {"rcgymb","crgbmy","bygrmc","ybgcmr","gmcyrb","mgcbry"};
char way[6];
map<string,int> id;
int dist[35][35][25][7];
string to[25];

string roll_down(string s) {
	string str = "";
	str += s[2];
	str += s[4];
	str += s[1];
	str += s[3];
	str += s[0];
	str += s[5];
	return str;
}
string roll_up(string s) {
	string str = "";
	str += s[4];
	str += s[2];
	str += s[0];
	str += s[3];
	str += s[1];
	str += s[5];
	return str;
}
string roll_right(string s) {
	string str = "";
	str += s[3];
	str += s[5];
	str += s[2];
	str += s[1];
	str += s[4];
	str += s[0];
	return str;
}
string roll_left(string s) {
	string str = "";
	str += s[5];
	str += s[3];
	str += s[2];
	str += s[0];
	str += s[4];
	str += s[1];
	return str;
}

int hash(string s) {
	return id[s];
}
string break_hash(int t) {
	return to[t];
}

pair<int,int> q[250000];
int in,fn;

int solve(string st, int x, int y) {
	in = 0;
	fn = 0;
	q[fn++] = make_pair(x*m+y,hash(st)*6);
	dist[x][y][hash(st)][0] = 0;
	int ans = 100000000;
	while (in<fn) {
		x = q[in].first/m;
		y = q[in].first%m;
		int t = q[in].second/6;
		int cur = q[in++].second%6;
		string s = break_hash(t); //cout<<x<<" "<<y<<" "<<cur<<" "<<s<<" "<<dist[x][y][t][cur]<<endl;
		
		string str;
		str = roll_down(s);
		int xx = x+1;
		int yy = y;
		if (xx<n && dist[xx][yy][hash(str)][cur]>1 + dist[x][y][t][cur]) {
			if (mapa[xx][yy]=='w') {
				dist[xx][yy][hash(str)][cur] = 1 + dist[x][y][t][cur];
				q[fn++] = make_pair(xx*m+yy,hash(str)*6+cur);
			}
		}
		if (xx<n && dist[xx][yy][hash(str)][cur+1]>1 + dist[x][y][t][cur]) {
			if (mapa[xx][yy]==str[0] && mapa[xx][yy]==way[cur]) {
				if (cur==5) {
					return dist[x][y][t][cur]; 
				}
				dist[xx][yy][hash(str)][cur+1] = 1 + dist[x][y][t][cur];
				q[fn++] = make_pair(xx*m+yy,hash(str)*6+cur+1);
			}
		}
		
		str = roll_up(s);
		xx = x-1;
		yy = y;
		if (xx>=0 && dist[xx][yy][hash(str)][cur]>1 + dist[x][y][t][cur]) {
			if (mapa[xx][yy]=='w') {
				dist[xx][yy][hash(str)][cur] = 1 + dist[x][y][t][cur];
				q[fn++] = make_pair(xx*m+yy,hash(str)*6+cur);
			}
		}	
		if (xx>=0 && dist[xx][yy][hash(str)][cur+1]>1 + dist[x][y][t][cur]) {
			if (mapa[xx][yy]==str[0] && mapa[xx][yy]==way[cur]) {
				if (cur==5) {
					return dist[x][y][t][cur]; 
				}
				dist[xx][yy][hash(str)][cur+1] = 1 + dist[x][y][t][cur];
				q[fn++] = make_pair(xx*m+yy,hash(str)*6+cur+1);
			}
		}
		
		str = roll_left(s);
		xx = x;
		yy = y-1;
		if (yy>=0 && dist[xx][yy][hash(str)][cur]>1 + dist[x][y][t][cur]) {
			if (mapa[xx][yy]=='w') {
				dist[xx][yy][hash(str)][cur] = 1 + dist[x][y][t][cur];
				q[fn++] = make_pair(xx*m+yy,hash(str)*6+cur);
			}
		}
		if (yy>=0 && dist[xx][yy][hash(str)][cur+1]>1 + dist[x][y][t][cur]) {
			if (mapa[xx][yy]==str[0] && mapa[xx][yy]==way[cur]) {
				if (cur==5) {
					return dist[x][y][t][cur]; 
				}
				dist[xx][yy][hash(str)][cur+1] = 1 + dist[x][y][t][cur];
				q[fn++] = make_pair(xx*m+yy,hash(str)*6+cur+1);
			}
		}
		
		str = roll_right(s); 
		xx = x;
		yy = y+1;
		if (yy<m && dist[xx][yy][hash(str)][cur]>1 + dist[x][y][t][cur]) {
			if (mapa[xx][yy]=='w') {
				dist[xx][yy][hash(str)][cur] = 1 + dist[x][y][t][cur];
				q[fn++] = make_pair(xx*m+yy,hash(str)*6+cur);
			}
		}	
		if (yy<m && dist[xx][yy][hash(str)][cur+1]>1 + dist[x][y][t][cur]) {
			if (mapa[xx][yy]==str[0] && mapa[xx][yy]==way[cur]) {
				if (cur==5) {
					return dist[x][y][t][cur]; 
				}
				dist[xx][yy][hash(str)][cur+1] = 1 + dist[x][y][t][cur];
				q[fn++] = make_pair(xx*m+yy,hash(str)*6+cur+1);
			}
		}
	}
	return ans;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    for (int i=0; i<6; i++) {
		for (int j=0; j<4; j++) {
			string s = dice[i];
			s = s.substr(0,2) + s.substr(2+j,4-j) + s.substr(2,j);
			id[s] = i*4+j;
			to[i*4+j] = s;
		}
	}

	while (scanf("%d%d",&m,&n) && n!=0) {
		for (int i=0; i<n; i++) scanf("%s",mapa+i);
		scanf("%s",way);
		
		int ans = 100000000;
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int k=0; k<25; k++) for (int t=0; t<7; t++) dist[i][j][k][t] = 100000000;	


		string s = "rcgymb";
		for (int x=0; x<n; x++) for (int y=0; y<m; y++) if (mapa[x][y]=='#') {
			mapa[x][y] = 'w';
			ans = min(ans,solve(s,x,y)+1);
		}

		if (ans<100000000) printf("%d\n",ans);
		else printf("unreachable\n");
	}

    return 0;

}
