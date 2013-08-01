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

char c[1001][1001];
int vis[1001][1001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int n,m;
	cin>>n>>m;
	
	int k = 0;
	int t = 0;
	char lastl = 'A';
	char l = 'A';
	int tmp = 0;
	int last = 0;
	int j;
	bool est = 1;
	
	for (int i=0; i<n; i++) {
		//cout<<i<<" "<<last<<" "<<tmp<<endl;
		if (tmp==0) {
			t += k;
			k++;
			tmp = k;
			lastl = l;
			l = char(rand()%26+'A');
		}
		if (i%2==0) {
			for (j=last; j<m && tmp>0; j++, tmp--) {c[i][j] = l; vis[i][j] = k;}
			last = j;
			//cout<<last<<" "<<tmp<<" "<<j<<endl;
			if (j==m) {last = m-1; continue;}
			else i--;
		}
		else {
			for (j=last; j>=0 && tmp>0; j--, tmp--) {c[i][j] = l; vis[i][j] = k;}
			last = j;
			//cout<<last<<" "<<tmp<<endl;

			if (j==-1) {last = 0; continue;}
			else i--;
		}
	}
	
	if (l!='A') l = l-1;
	else l = 'Z';
	
	if (tmp>0) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) if (vis[i][j]==k) c[i][j] = lastl;
		}
		k--;
	}
	
	cout<<k<<endl;
	for (int i=0; i<n; i++) {for (int j=0; j<m; j++) cout<<c[i][j]; cout<<endl;}

    return 0;

}
