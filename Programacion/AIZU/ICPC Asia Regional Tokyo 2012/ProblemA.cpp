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

set<pair<int,int> > s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	while (t--) {
		int n,m;
		cin>>n>>m;
		
		int k = n*n + m*m;
		
		int c = 0;
		s.clear();
		for (int i=0; i*i<=k; i++) {
			for (int j=0; i*i+j*j<=k; j++) {
				if (i*i+j*j<=1) continue;
				
				for (int x=-1; x<2; x+=2) for (int y=-1; y<=1; y+=2) {
					
					if (s.find(mp(x*i,y*j))!=s.end()) continue;
					s.insert(mp(x*i,y*j));
				
					int mod = i*i + j*j;
					int real = x*n*i - y*m*j;
					int im = x*n*j + y*m*i;
					
					if (real%mod==0 && im%mod==0) {
						c++;
						//cout<<x*i<<" "<<y*j<<endl;
					}
				}
			}
		}
		
		if (c>4) cout<<"C"<<endl;
		else cout<<"P"<<endl;
	}
	
    return 0;

}
