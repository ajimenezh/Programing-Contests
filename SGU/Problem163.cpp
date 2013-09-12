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
int fpow(int a, int b) {
	if (a<0) {
		if (b%2==0) return fpow(-a,b);
		else return -fpow(-a,b);
	}
	if (b==0) return 1;
	int tmp = fpow(a,b/2);
	if (b%2==0) return tmp*tmp;
	return a*tmp*tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int sum = 0;
	cin>>n;
	int p;
	cin>>p;
	for (int i=0; i<n; i++) {
		int a;
		cin>>a;
		int t = fpow(a,p);
		if (t>0) sum += t;
	}
	
	cout<<sum<<endl;

    return 0;

}
