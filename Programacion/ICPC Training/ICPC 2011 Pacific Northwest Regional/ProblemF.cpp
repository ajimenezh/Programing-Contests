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
int m;
vector<int> v;

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	while (n--) {
		cin>>m;
		int a = 0;
		v.clear();
		for (int i=0; i<m; i++) {
			cin>>a;
			v.push_back(a);
		}
		int k = m;
		for (int i=0; i<m-1; i++) {
			bool good = 1;
			for (int j=0; j<m; j++) if (abs(v[j])>0) good = 0;
			if (good) {
				k = i+1;
				break; 
			}
			for (int j=m-1; j>i; j--) v[j] = v[j] - v[j-1];
			v[i] = 0;
		}
		if (v[m-1]==0) {
			for (int j=0; j<k-1; j++) cout<<"z";
			cout<<"ap!"<<endl;
			continue;
		}
		if (v[m-1]<0) {
			cout<<"*bunny*"<<endl;
		}
		else cout<<"*fizzle*"<<endl;
	}
	
    return 0;

}
