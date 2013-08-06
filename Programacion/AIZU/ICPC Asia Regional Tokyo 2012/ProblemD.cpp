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

typedef vector<double> vec;
typedef vector<vec> mat;

const double eps = 1.0e-5;

int d;
double x[8];
int m;

vec gauss_jordan(const mat& A, const vec &v) {
	int n = A.size();
	mat B(n,vec(n+1));
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++) 
			B[i][j] = A[i][j]; 
	for (int i=0; i<n; i++) 
		B[i][n] = v[i];
	for (int i=0; i<n; i++) {
		int piv = -1;
		double tmp = -1;
		for (int j=i; j<n; j++) {
			if (tmp < abs(B[j][i])) {
				piv = j;
				tmp = abs(B[j][i]);
			}
		}
		if (piv==-1 || tmp<eps) return vec();
		swap(B[piv],B[i]);
		double divNum = B[i][i];
		for (int j=i; j<=n; j++) 
			B[i][j] /= divNum;
		for (int j=0; j<n; j++) {
			if (i==j) continue;
			double mulNum = B[j][i];
			for (int k=i; k<=n; k++)
				B[j][k] -= mulNum*B[i][k];
		}
	}
	vec res(n);
	for (int i=0; i<n; i++) {
		res[i] = B[i][n];
	}
	return res;
}

int solve() {
	for (int i=0; i<m; i++) {
		for (int j=i+1; j<m; j++) {
			mat A(d+1, vec(d+1,0.0));
			vector<int> v;
			for (int k=0; k<m; k++) {
				if (k==i || k==j) continue;
				v.push_back(k);
			}
			for (int k=0; k<v.size(); k++) {
				double cur = 1;
				for (int r=d; r>=0; r--) {
					A[k][r] = cur;
					cur *= v[k];
				}
			}
			vec c(d+1,0);
			for (int k=0; k<d+1; k++) {
				c[k] = x[v[k]];
			}
			vec ans = gauss_jordan(A,c);
			if (ans.size()>0) {
				
				double xx = 1;
				double y = 0.0;
				bool found = 0;
				for (int l=d; l>=0; l--) {
					y += ans[l]*xx;
					xx*=i;
				}
				if (abs(y-x[i])<eps) {
					found = 1; 
				}

				xx = 1;
				y = 0.0;
				for (int l=d; l>=0; l--) {
					y += ans[l]*xx;
					xx*=j;
				}

				if (abs(y-x[j])<eps) {
					if (found) continue;
					if (!found) return i;
				}
				else {
					if (found) return j;
				}
			}
		}
	}
	return -1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>d && d) {
		m = d+3;
		for (int i=0; i<m; i++) cin>>x[i];
		cout<<solve()<<endl;
	}
	
    return 0;

}
