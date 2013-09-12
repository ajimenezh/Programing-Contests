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
string s;
unsigned int hash[500010];
bool vis[1<<19];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>s;
	for (int i=1; i<=n; i++) hash[i] = (hash[i-1]<<1) + (s[i-1]-'a');
	
	int len = 1;
	while (true) {
		for (int i=0; i<(1<<(len-1)); i++) vis[i] = 0;
		
		for (int i=1; i+len-1<=n; i++) {
			unsigned int t = hash[i+len-1] - (hash[i-1]<<(len));
			vis[t] = 1;
		}
		
		bool done = 0;
		for (int i=0; i<(1<<len); i++) if (!vis[i]) {
			cout<<len<<endl;
			int t = i;
			string str;
			for (int j=0; j<len; j++) {
				if (t&1) str = "b" + str;
				else str = "a" + str;
				t >>= 1;
			}
			cout<<str<<endl;
			done = 1;
			break;
		}
		if (done) break;
		len++;
	}

    return 0;

}
