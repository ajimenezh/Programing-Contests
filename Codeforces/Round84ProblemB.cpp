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

int pl,pr,vl,vr,k;
int ln[1100];
int m;

int next(int a) {
	stringstream ss;
	ss<<a;
	string s = ss.str();
	int r = 1;
	for (int i=s.length()-1; i>=0; i--) {
		if (s[i]=='4') {
			s[i] = '7';
			r = 0;
			break;
		}
		else {
			s[i] = '4';
		}
	}
	if (r==1) s = '4' + s;
	return atoi(s.c_str());
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>pl>>pr>>vl>>vr>>k;
	
	int cur = 4;
	ln[m++] = 0;
	while (cur<=max(pr,vr)) {
		ln[m++] = cur;
		cur = next(cur);
	}
	ln[m++] = cur;
	
	long long res = 0;
	
	for (int i=1; i<m; i++) {
		if (i+k-1>=m) continue;
		
		int l1,l2,r1,r2;
		if (ln[i]>=pl && ln[i+k-1]<=vr) {
			l1 = ln[i-1];
			l2 = min(ln[i],pr);
			l1 = max(l1+1,pl);

			r1 = max(ln[i+k-1],vl);
			r2 = ln[i+k-1+1];
			r2 = min(r2-1,vr);
			
			//cout<<i<<" "<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
			
			if (l2>=l1 && r2>=r1) res += (long long)(l2-l1+1)*(long long)(r2-r1+1);
		}
		
		if (ln[i]>=vl && ln[i+k-1]<=pr) {
			l1 = ln[i-1];
			l2 = min(ln[i],pr);
			l1 = max(l1+1,vl);

			r1 = max(ln[i+k-1],pl);
			r2 = ln[i+k-1+1];
			r2 = min(r2-1,pr);
			
			if (l2>=l1 && r2>=r1) res += (long long)(l2-l1+1)*(long long)(r2-r1+1);
		}
	}
		

	double p = (double) res / (double) ( (long long)(pr-pl+1)*(long long)(vr-vl+1));
	
	printf("%.12f\n",p);

    return 0;

}
