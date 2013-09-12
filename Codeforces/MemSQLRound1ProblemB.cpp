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

long long n;
vector<int> v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	long long t = n;
	
	long long f = 1;
	for (int i=0; i<60; i++) { 
		long long lo = 1;
		long long hi = 1000000000LL;
		long long tot;
		while (lo+2<hi) {
			long long mi = (lo+hi)/2;
			if (mi%2==0) mi++;
			if ((f-1)*mi + mi*(mi-1)/2<t) {
				lo =mi+1;
			}
			else {
				hi =mi;
			}
		}
		for (long long l=max(lo-16,1LL); l<=lo+16; l++) {
			if (l%2==0) continue;
			long long c = l;
			if ((f-1)*c + c*(c-1)/2==t) {
				v.push_back(l*f);
				break;
			}
		}
		f *= 2;
	}
	
	
	if (v.size()==0) cout<<-1;
	else {
		for (int i=0; i<v.size(); i++) cout<<v[i]<<endl;
	}

    return 0;

}
