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

/* Translation matrix
 * 		1 0 0 x
 * 		0 1 0 y
 * 		0 0 1 z
 * 		0 0 0 1
 * 
 * Scale matrix
 * 		x 0 0 0
 * 		0 y 0 0
 * 		0 0 z 0
 * 		0 0 0 1
 * 
 * Rotation matrix around vector (a,b,c) an angle x; (a,b,c) with |v|=1 
 * 		cos(x)+a*a(1-cos(x))	a*b*(1-cos(x))-c*sin(x)		a*c*(1-cos(x))+b*sin(x)
 * 		a*b*(1-cos(x))+c*sin(x)	cos(x)+b*b(1-cos(x))		b*c*(1-cos(x))-a*sin(x)
 * 		a*c*(1-cos(x))-b*sin(x)	b*c*(1-cos(x))+a*sin(x)		cos(x)+c*c(1-cos(x))
 * 
 */
 
 const double eps = 1.0e-9;
  
  
struct matrix{
	vector<double> v[4];
	matrix() {
		for (int i=0; i<4; i++) v[i] = vector<double> (4,0.0);
		for (int i=0; i<4; i++) v[i][i] = 1.0;
	}
	vector<double> & operator[](int index) {
		return v[index];
	}
};

matrix operator*(matrix a, matrix b) {
	matrix c;
	for (int i=0; i<4; i++) for (int j=0; j<4; j++) {
		c[i][j] = 0.0;
		for (int k=0; k<4; k++) c[i][j] += a[i][k]*b[k][j];
	}
	return c;
}

int n;

matrix fpow(matrix c, int a) {
	if (a==0) return matrix();
	if (a==1) return c;
	matrix t = fpow(c,a/2);
	t = t*t;
	if (a%2==0) return t;
	return t*c;
}

matrix dfs() {
	string s;
	matrix m;
	while (true) {
		cin>>s;
		if (s[0]=='e') return m;
		if (s[0]=='t') {
			double a,b,c;
			scanf("%lf%lf%lf",&a,&b,&c);
			matrix tmp;
			tmp[0][3] = a;
			tmp[1][3] = b;
			tmp[2][3] = c;
			m = tmp*m;
		}
		if (s[0]=='s') {
			double a,b,c;
			scanf("%lf%lf%lf",&a,&b,&c);
			matrix tmp;
			tmp[0][0] = a;
			tmp[1][1] = b;
			tmp[2][2] = c;
			m = tmp*m;
		}
		if (s[0]=='r') {
			if (s=="repeat") {
				int k;
				scanf("%d",&k);
				matrix t = dfs();
				t = fpow(t,k);
				m = t*m;
			}
			else {
				double a,b,c,x;
				scanf("%lf%lf%lf%lf",&a,&b,&c,&x);
				double mod = 0;
				mod = sqrtl(a*a+b*b+c*c);
				a /= mod;
				b /= mod;
				c /= mod;
				x = (x/180.0)*acosl(-1.0);
				matrix tmp;
				tmp[0][0] = cosl(x)+a*a*(1-cosl(x));
				tmp[0][1] = a*b*(1-cosl(x))-c*sinl(x);
				tmp[0][2] = a*c*(1-cosl(x))+b*sinl(x);
				tmp[1][0] = a*b*(1-cosl(x))+c*sinl(x);
				tmp[1][1] = cosl(x)+b*b*(1-cosl(x));
				tmp[1][2] = b*c*(1-cosl(x))-a*sinl(x);
				tmp[2][0] = a*c*(1-cosl(x))-b*sinl(x);
				tmp[2][1] = b*c*(1-cosl(x))+a*sinl(x);
				tmp[2][2] = cosl(x)+c*c*(1-cos(x));
				m = tmp*m;
			}
		}
	}
	return m;
}

double absf(double a) {
	if (a<0.0) return -a;
	return a;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		matrix t = dfs();
		for (int i=0; i<n; i++) {
			double x,y,z;
			scanf("%lf%lf%lf",&x,&y,&z);
			double xx = t[0][0]*x + t[0][1]*y + t[0][2]*z + t[0][3];
			double yy = t[1][0]*x + t[1][1]*y + t[1][2]*z + t[1][3];
			double zz = t[2][0]*x + t[2][1]*y + t[2][2]*z + t[2][3];
			printf("%.2lf %.2lf %.2lf\n",absf(xx+eps),absf(xx+eps),absf(xx+eps));
		}
		cout<<endl;
	}

    return 0;

}
