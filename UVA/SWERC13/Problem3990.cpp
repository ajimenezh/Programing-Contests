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


int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	int k = 1;
	while (tt--) {
		string s;
		cin>>s;
		int c0=0, c1=0, c2=0;
		for (int i=0; i<s.length(); i++) {
			if (s[i]=='0') c0++;
			else if (s[i]=='1') c1++;
			else c2++;
		}
		string w;
		cin>>w;
		for (int i=0; i<w.length(); i++) {
			if (w[i]=='0') c0--;
			else if (w[i]=='1') c1--;
		}
		if (c0+c2<0) {
			printf("Case %d: -1\n",k++);
		}
		else {
			int c = 0;
			for (int i=0; i<s.length(); i++) {
				if (s[i]=='?' && w[i]=='0') {
					s[i]='0';
					c0++;
					c++;
				}
				else if (s[i]=='?' && c1==0) {
					s[i]='0';
					c0++;
					c++;
				}
				else if (s[i]=='?' && w[i]=='1' && c1<0) {
					s[i]='1';
					c1++;
					c++;
				}
			}
			for (int i=0; i<s.length(); i++) {
				if (s[i]=='0' && w[i]=='1' && c1<0) {
					c++;
					c1++;
					s[i]=='1';
				}
			}
			c0 = -c0;
			for (int i=0; i<s.length(); i++) {
				if (s[i]=='1' && w[i]=='0') c0++;
				if (s[i]=='0' && w[i]=='1') c0++;
			}
			printf("Case %d: %d\n",k++,c + c0/2);
		}
	}

    return 0;

}
