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

int good[] = {1,2,3,3,4,10};
int bad[] = {1,2,2,2,3,5,10};
int n;

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	int t = 1;
	while (n--) {
		int tot = 0;
		for (int i=0; i<6; i++) {
			int c;
			scanf("%d",&c);
			tot += good[i]*c;
		}
		for (int i=0; i<7; i++) {
			int c;
			scanf("%d",&c);
			tot -= bad[i]*c;
		}

		cout<<"Battle "<<t++<<": ";
		if (tot>0) {
			cout<<"Good triumphs over Evil"<<endl;
		}
		else if (tot<0) {
			cout<<"Evil eradicates all trace of Good"<<endl;
		}
		else {
			cout<<"No victor on this battle field"<<endl;
		}
	}
	
    return 0;

}
