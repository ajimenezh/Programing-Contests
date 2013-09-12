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
int a[1010][1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		for (int i=0; i<n; i++) 
			for (int j=0; j<n; j++)
				scanf("%d",&a[i][j]);
		
		bool bad = 0;
		for (int i=0; i<min(1000000,n*n*10); i++) {
			int x = rand()%n;
			int y = rand()%n;
			int xx = rand()%n;
			int yy = rand()%n;
			
			if (a[x][y] + a[xx][yy] != a[x][yy] + a[xx][y]) {
				bad = 1;
				break;
			}
		}
		
		if (!bad) {
			cout<<"homogeneous"<<endl;
		}
		else cout<<"not homogeneous"<<endl;
	}
	
    return 0;

}
