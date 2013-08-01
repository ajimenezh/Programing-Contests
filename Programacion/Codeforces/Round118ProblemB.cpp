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

int s;
int a,b,c;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>s;
	cin>>a>>b>>c;
	
	double x = 0, y = 0, z = 0;
	
	if (a==0 && b==0 && c==0) {
		cout<<x<<" "<<y<<" "<<z<<endl;
	}
	else {
		x = (double)s*a/(double)(a+b+c);
		y = (double)s*b/(double)(a+b+c);
		z = (double)s*c/(double)(a+b+c);
		
		printf("%.12f %.12f %.12f\n",x,y,z);
	}
		

    return 0;

}
