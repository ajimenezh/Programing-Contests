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

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	while (tt--) {
		int x,y;
		string z;
		cin>>x>>y>>z;
		long long t = 0;
		for (int i=0; i<z.length(); i++) {
			if (z[i]>='a' && z[i]<='z') z[i] = char(z[i]-'a'+'A');
			if (z[i]>='0' && z[i]<='9') t = t*x + (z[i]-'0');
			else t = t*x + (z[i]-'A'+10);
		}
		char buf[70];
		int c = 0;
		while (t>0) {
			int k = t%y;
			t /= y;
			if (k<10) buf[c++] = char(k+'0');
			else buf[c++] = char('A'+k-10);
		}
		if (c==0) cout<<"0";
		for (int i=c-1; i>=0; i--) printf("%c",buf[i]);
		cout<<endl;
	}

    return 0;

}
