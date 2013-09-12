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

	int n;
	while (scanf("%d",&n) && n!=0) { cout<<n<<endl;
		vector<int> v;
		map<int,int> m;
		for (int i=0; i<n; i++) {
			int a;
			cin>>a;
			m[a] = i;
		}
		for (int i=0; i<n; i++) {
			int a;
			cin>>a;
			v.push_back(m[a]);
		}
		if (n<=1) {
			cout<<"caught"<<endl;
		}
		else {
			bool bad = 0;
			for (int i=0; i<n-1; i++) {
				if (v[i+1]<v[i]) {
					bad = 1;
					break;
				}
			}
			if (bad) cout<<"escaped"<<endl;
			else cout<<"caught"<<endl;
		}
	}
	
	
    return 0;

}
