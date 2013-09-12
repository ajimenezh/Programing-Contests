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
int a[12];
int b[12];
int dp[101][11][11][11][11];
int id[11];
int tmp[11];
bool cmp(int i, int j) {
	return a[i]>a[j];
}

int solve(int i, int x, int y, int w, int z) {
	if (i>=m) return 0;
	if (dp[i][x][y][w][z]) return dp[i][x][y][w][z];
	
	int xx = x;
	int yy = y;
	int ww = w;
	int zz = z;
	
	x = y;
	y = w;
	w = z;
	z = 0;
	
	int tmp = 1000000000;
	
	if (xx!=0 || yy!=0 || zz!=0 || ww!=0) tmp = 1+solve(i,x,y,w,z);
	
	for (int k=1; k<=n; k++) {
		if (k!=xx && k!=yy && k!=ww && k!=zz) {
			if (b[k]==1) {
				tmp = min(tmp, 1 + solve(i+a[k],k,x,y,w));
			}
			if (b[k]==2) {
				tmp = min(tmp, 1 + solve(i+a[k],x,k,y,w));
			}
			if (b[k]==3) {
				tmp = min(tmp, 1 + solve(i+a[k],x,y,k,w));
			}
			if (b[k]==4) {
				tmp = min(tmp, 1 + solve(i+a[k],x,y,w,k)); 
			}
		}
	}
	
	dp[i][x][y][w][z] = tmp;
	
	//cout<<i<<" "<<x<<" "<<y<<" "<<w<<" "<<z<<" "<<tmp<<endl;
	
	return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>m>>n;
	for (int i=1; i<=n; i++) scanf("%d%d",a+i,b+i);
	for (int i=1; i<=n; i++) id[i] = i;
	sort(id,id+n,cmp);
	for (int i=1; i<=n; i++) tmp[i] = a[id[i]];
	for (int i=1; i<=n; i++) a[i] = tmp[i];
	for (int i=1; i<=n; i++) tmp[i] = b[id[i]];
	for (int i=1; i<=n; i++) b[i] = tmp[i];
	
	cout<<solve(0,0,0,0,0);

    return 0;

}
