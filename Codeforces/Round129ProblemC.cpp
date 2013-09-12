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
string s1,s2;
double res;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    cin>>n>>s1>>s2;

	for (char c='A'; c<='Z'; c++) {
		long long l = 0, r = 0;
		for (int j=0; j<n; j++) if (s1[j]==c) r += n-j;

		for (int j=0; j<n; j++) {
			if (s1[j]==c) r -= n-j;
			if (s2[j]==c) {
				if (s1[j]==c) res += (double)(j+1)*(double)(n-j);
				res += l*(double)(n-j);
				res += (double)r*(j+1);
			}
			if (s1[j]==c) {
				l += j+1;
			}
		}
	}
	
	double tot = 0;
	for (int i=1; i<=n; i++) tot += (double)i*i;
	
	//cout<<res<<" "<<tot<<endl;
	
	double p = res / tot;
	
	printf("%.12f",p); 

    return 0;

}
