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

#define INF 100000000

int n;
map<pair<int,int>,int> dp;
map<pair<int,int>,bool> vis;
map<pair<int,int>,bool> now;
map<pair<int,int>,int> next;
char buf[25][25];
int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};
int ans;

int make(pair<int,int> p) {
	if (next.find(p)!=next.end()) return next[p];
	int mask = p.first;
	int pos = p.second;
	mask |= (1<<pos);
	int newmask = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int k = i*n+j;
			int t = 0;
			if (j>0) {
				t += (mask&(1<<(k-1)))>0;
				if (i>0) t += (mask&(1<<(k-1-n)))>0;
				if (i<n-1) t += (mask&(1<<(k-1+n)))>0;
			}
			if (j<n-1) {
				t += (mask&(1<<(k+1)))>0;
				if (i>0) t += (mask&(1<<(k+1-n)))>0;
				if (i<n-1) t += (mask&(1<<(k+1+n)))>0;
			}
			if (i>0) t += (mask&(1<<(k-n)))>0;
			if (i<n-1) t += (mask&(1<<(k+n)))>0;
			if ((mask&(1<<k)) && k!=pos) {
				if (t==2 || t==3) {
					newmask |= (1<<k);
				}
			}
			else {
				if (t==3 && k!=pos) {
					newmask |= (1<<k);
				}
			}
		}
	}
	next[p] = newmask;
	return newmask;
}

void print(int m) {
	for (int i=0; i<n;  i++) {
		for (int j=0; j<n; j++) {
			int k = i*n+j;
			if (m&(1<<k)) cout<<'#';
			else cout<<'.';
		}
		cout<<endl;
	}
}

int solve(int x, int y, int mask) {
	//cout<<x<<" "<<y<<" "<<mask<<endl;
	//print(mask);
	//cout<<endl;
	
	if (mask==0) return 0;
	
	queue<pair<int,int> > q;
	q.push(make_pair(mask,x*n+y));
	q.push(make_pair(-1,-1));
	set<pair<int,int> > vis;
	vis.insert(make_pair(mask,x*n+y));
	int t = 1;
	
	while (q.size()>1) {
		mask = q.front().first;
		x = q.front().second/n;
		y = q.front().second%n;
		q.pop();
		if (mask==-1) {
			t++;
			q.push(make_pair(-1,-1));
		}
			
		for (int k=0; k<8; k++) {
			int u = x + dx[k];
			int v = y + dy[k];
			if (u<0 || u>=n) continue;
			if (v<0 || v>=n) continue;
			if (mask&(1<<(u*n+v))) continue;
		
			int m = make(make_pair(mask,u*n+v));
			
			if (m==0) {
				return t;
			}
			
			if (vis.insert(make_pair(m,u*n+v)).second) q.push(make_pair(m,u*n+v));
			
		}
	}
	return -1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		for (int i=0; i<n; i++) scanf("%s",buf+i);
		//for (int i=0; i<n; i++) cout<<buf[i]<<endl;
		int x,y;
		int mask = 0;
		for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
			if (buf[i][j]=='#') mask |= (1<<(i*n+j));
			if (buf[i][j]=='@') {
				x = i;
				y = j;
			}
		}
		now.clear();
		vis.clear();
		dp.clear();
		ans = INF;
		ans = solve(x,y,mask);
		if (ans >= INF) printf("-1\n");
		else printf("%d\n",ans);
	}

    return 0;

}
