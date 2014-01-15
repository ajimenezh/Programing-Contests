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

int m,n;
vector<int> v;
int p[100];
int all[110];
int what[110];

bool cmp(int i, int j) {
	return abs(v[i]) < abs(v[j]);
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	while (tt--) {
		cin>>m>>n;
		bool done = 0;
		bool t1 = 0, t2 = 0;
		for (int i=0; i<n; i++) {
			int a;
			v.clear();
			for (int j=0; j<3; j++) {
				scanf("%d",&a);
				if (abs(a)==0) {
					t1 = 1;
					done = 1;
				}
				if (abs(a)>m) {
					t2 = 1;
					done = 1;
				}
				v.push_back(a);
			}
			cin>>a;
			for (int j=0; j<3; j++) p[j] = j;
			sort(p,p+3,cmp);
			for (int j=1; j<3; j++) if (abs(v[p[j]]) == abs(v[p[j-1]])) {
				done = 1;
			}
			if (done) continue;
			int mask = 0;
			for (int j=0; j<3; j++) if (v[p[j]]>0) mask |= (1<<(abs(v[p[j]])-1));
			all[i] = mask;
			mask = 0;
			for (int j=0; j<3; j++) mask |= (1<<(abs(v[p[j]])-1));
			what[i] = mask;
		}
		
		if (done) {
			if (t1) {
				cout<<"INVALID: NULL RING"<<endl;
			}
			else if (t2) {
				cout<<"INVALID: RING MISSING"<<endl;
			}
			else {
				cout<<"INVALID: RUNE CONTAINS A REPEATED RING"<<endl;
			}
			continue;
		}
		for (int i=0; i<(1<<m); i++) {
			bool good = 1;
			for (int j=0; j<n; j++) {
				if (((all[j]^i)&what[j])==what[j]) {
					good = 0;
					break;
				}
			}
			if (good) {
				done = 1;
				cout<<"RUNES SATISFIED!"<<endl;
				break;
			}
		}
		if (done) continue;
		cout<<"RUNES UNSATISFIABLE! TRY ANOTHER GATE!"<<endl;
	}
	
    return 0;

}
