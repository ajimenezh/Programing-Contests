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

struct point{
	double x,y,z;
	point(double x=0, double y=0,double z=0):x(x),y(y),z(z){}
};

point operator-(const point &a, const point &b) {
	return point(a.x-b.x, a.y-b.y, a.z-b.z);
}

point operator+(const point &a, const point &b) {
	return point(a.x+b.x, a.y+b.y, a.z+b.z);
}

point operator*(const point &a, const double &t) {
	return point(t*a.x, t*a.y, t*a.z);
}

double dot(const point &a, const point &b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

bool intersect(point a, point b, point c, double r) {
	point u = b-a; 
	point p0 = a-c;
	
	double A = dot(u,u);
	double B = 2*dot(u,p0);
	double C = dot(p0,p0) - r*r;
	
	double delta = B*B - 4*A*C;
	
	if (delta<0) return false;
	
	double t1 = (double)(-B + sqrt((double)delta)) / (2.0*A);
	double t2 = (double)(-B - sqrt((double)delta)) / (2.0*A);
	
	point p1 = a + u*t1;
	point p2 = a + u*t2;
	
	//cout<<dot(p1-a,b-a)<<" "<<dot(p2-a,b-a)<<endl;
	
	if (dot(p1-a,b-a) > 1.0e-6 && dot(p1-b,a-b) > 1.0e-6) return true;
	if (dot(p2-a,b-a) > 1.0e-6 && dot(p2-b,a-b) > 1.0e-6) return true;
	
	return false;
}

int N,M,R;
point ballc[2010];
int ballr[2010];
point light[20];
int intensity[20];
point target;

double totalIntensity(int i) {
	point u = (light[i]-target);
	double m = dot(u,u);
	return (double)intensity[i]/m;
}

double ans;
bool bad[2010][20];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>N>>M>>R && N) {
		for (int i=0; i<N; i++) {
			int x,y,z,r;
			scanf("%d%d%d%d",&x,&y,&z,&r);
			ballc[i] = point(x,y,z);
			ballr[i] = r;
		}
		for (int i=0; i<M; i++) {
			int x,y,z,r;
			scanf("%d%d%d%d",&x,&y,&z,&r);
			light[i] = point(x,y,z);
			intensity[i] = r;
		}
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		target = point(x,y,z);
		
		ans = 0.0;
		
		//cout<<intersect(target,light[1],ballc[7],ballr[7])<<endl;; break;
		
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				bad[i][j] = intersect(target,light[j],ballc[i],ballr[i]);
			}
		}
		
		for (int i=0; i<(1<<M); i++) {
			int tot = 0;
			for (int j=0; j<N; j++) {
				for (int k=0; k<M; k++) if (i&(1<<k)) {
					if (bad[j][k]) {
						tot++;
						break;
					}
				}
			}
			double tmp = 0.0;
			if (tot>R) continue;
			for (int k=0; k<M; k++) if (i&(1<<k)) tmp += totalIntensity(k);
			ans = max(ans,tmp);
		}
		
		printf("%.12lf\n",ans);
	}
	
    return 0;

}
