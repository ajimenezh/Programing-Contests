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

	int a,b,x1,y1,x2,y2;
	cin>>a>>b>>x1>>y1>>x2>>y2;
	
	int u1 = x1+y1;
	int v1 = x1-y1;
	int u2 = x2+y2;
	int v2 = x2-y2;
	
	int t1 = 0;
	
	if (u1>=0 && u2<=0) {
		t1 += u1/(2*a);
		t1 += -u2/(2*a);
		t1++;
	}
	else if (u1<=0 && u2>=0) {
		t1 += -u1/(2*a);
		t1 += u2/(2*a);
		t1++;
	}
	else {
		t1 += max(u1,u2)/(2*a) - min(u1-1,u2-1)/(2*a);
	}
	
	int t2 = 0;
	
	if (v1>=0 && v2<=0) {
		t2 += v1/(2*b);
		t2 += -v2/(2*b);
		t2++;
	}
	else if (v1<=0 && v2>=0) {
		t2 += -v1/(2*b);
		t2 += v2/(2*b);
		t2++;
	}
	else {
		t2 += max(v1,v2)/(2*b) - min(v1-1,v2-1)/(2*b);
	}
	
	cout<<max(t1,t2)<<endl;

    return 0;

}
