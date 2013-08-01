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

string s;
int n;
int m;
int w[51];
int v[160];
int kmax;
long long dp[160][160][21];

long long solve(int i, int j, int k) {
	if (i>=j) return 0;
	if (dp[i][j][k]>=0) return dp[i][j][k];
	
	long long tmp = 0;
	tmp = max(solve(i+1,j,k),tmp);
	tmp = max(solve(i,j-1,k),tmp);
	
	if (v[i]+v[j]==3) {
		if (v[i]%3==0) {
			if (k>0) {
				tmp = max(tmp, 1+solve(i+1,j-1,k-1));
			}
		}
		else tmp = max(tmp, 1+solve(i+1,j-1,k));
	}
	
	for (int t=i; t<j; t++) for (int p=0; p<=k; p++) tmp = max(tmp, solve(i,t,p) + solve(t+1,j,k-p));
		
	dp[i][j][k] = tmp;
	return tmp;
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int num = 1;
	int tt;
	cin>>tt;
	while (tt--) {
	
		cin>>s; 
		cin>>kmax;
		vector<pair<int,int> > pars;
		for (int i=0; i<s.length(); i++) {
			int j = i;
			i++;
			while (s[i]>='0' && s[i]<='9') i++;
			int t1;
			if (s[j]=='A') t1 = 1;
			else if (s[j]=='U') t1 = 2;
			else if (s[j]=='C') t1 = 0;
			else t1 = 3;
			string str = s.substr(j+1,i-j-1);
			pars.push_back(make_pair(t1,atoi(str.c_str()))); 
			i--;
		}
		int k = 0;
		for (int i=1; i<pars.size()-1; i++) {
			for (int j=0; j<pars[i].second; j++) w[k++] = pars[i].first;
		}
		m = k;
		long long ans = 0;
		if (pars[0].first+pars[pars.size()-1].first==3) {
			int p;
			int tmp = min(pars[0].second, pars[pars.size()-1].second);
			if (pars[0].first==2) {
				tmp = min(tmp,kmax);
				kmax -= tmp;
			}
			if (pars[0].second>pars[pars.size()-1].second) {
				p = pars[0].second-tmp;
				p = min(p,50);
				m += p;
				for (int j=0; j<p; j++) v[j] = pars[0].first;
				for (int j=0; j<k; j++) v[p+j] = w[j];
			}
			else {
				p = pars[pars.size()-1].second-tmp;
				p = min(50,p);
				m += p;
				for (int j=0; j<k; j++) v[j] = w[j];
				for (int j=0; j<p; j++) v[k+j] = pars[pars.size()-1].first;
			}
			for (int i=0; i<=m; i++) for (int j=0; j<=m; j++) for (int k=0; k<=kmax; k++) dp[i][j][k] = -1;
			ans = solve(0,m-1,kmax) + tmp;
			
			//for (int i=0; i<m; i++) cout<<v[i]<<" "; cout<<endl;
		}
		else {
			int t1 = min(50,pars[0].second);
			int t2 = min(50,pars[pars.size()-1].second);
			for (int j=0; j<t1; j++) v[j] = pars[0].first;
			for (int j=0; j<k; j++) v[j+t1] = w[j];
			for (int j=0; j<t2; j++) v[t1+k+j] = pars[pars.size()-1].first;
			m = k + t1 + t2;
			for (int i=0; i<=m; i++) for (int j=0; j<=m; j++) for (int k=0; k<=kmax; k++) dp[i][j][k] = -1;
			ans = max(solve(0,m-1,kmax),ans);
		}
	
		printf("Case %d: ",num++);
		cout<<ans<<endl;
	}

    return 0;

}
