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

int n,m;
struct point{
	long long x,y;
	point(){}
	point (int x, int y):x(x),y(y){} 
};
point a[510];
point b[510];
int c[510][510];

point operator-(point &xx, point &yy) {
	return point(xx.x-yy.x,xx.y-yy.y);
}
long long vect(point xx, point yy) {
	return xx.x*yy.y - xx.y*yy.x;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) {
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		a[i] = point(xx,yy);
	}
	for (int i=0; i<m; i++) {
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		b[i] = point(xx,yy);
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (a[i].x>=a[j].x) continue;
			for (int k=0; k<m; k++) {
				if (b[k].x>=a[i].x && b[k].x<a[j].x && vect(a[j]-a[i],b[k]-a[i])>0) c[i][j]++;
				c[j][i] = -c[i][j];
			}
		}
	}
	
	int sum = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				if (c[i][j]+c[j][k]+c[k][i]==0) sum++;
			}
		}
	}
	
	cout<<sum<<endl;

    return 0;

}
