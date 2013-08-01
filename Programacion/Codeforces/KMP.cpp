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

#define MAXM 1010
#define MAXN 100010

int fail[MAXM];
int pref[MAXN];
int suf[MAXN];
int v[MAXN];
string s;
string p;

void kmp(string _p) {
	p = _p;
	int m = p.length();
	int cnt = fail[0] = -1;
	for (int i=1; i<=m; i++) {
		while (cnt>=0 && p[cnt] != p[i-1]) cnt = fail[cnt];
		fail[i] = ++cnt;
	}
}

void doit() {
	int m = s.length();
	for (int i=0, j=0; i<m; i++) {
		while (j>=0 && s[i]!=p[j]) j = fail[j];
		if (++j==m) {
			v[i] = m-1;
			j = fail[j];
		}
		else v[i] = j;
	}
}

int res = 0;
int sum[MAXM];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>s;
	int t = 0;
	cin>>t;
	while (t--) {
		string str;
		cin>>str;
		if (str.length()==1) continue;
		kmp(str);
		doit();
		for (int i=0; i<(int)s.length(); i++) pref[i] = v[i];
		reverse(str.begin(),str.end());
		kmp(str);
		reverse(s.begin(),s.end());
		doit();
		for (int i=0; i<(int)s.length(); i++) suf[i] = v[s.length()-i-1];
		reverse(s.begin(),s.end());
		for (int i=0; i<=(int)str.length(); i++) sum[i] = 0;
		for (int i=1; i<(int)s.length(); i++) sum[suf[i]]++;
		
		//cout<<t<<endl;
		//for (int i=0; i<(int)s.length(); i++) cout<<pref[i]<<" "; cout<<endl;
		//for (int i=0; i<(int)s.length(); i++) cout<<suf[i]<<" "; cout<<endl;
		
		for (int i=0; i<(int)s.length()-1; i++) {
			if (pref[i]>=1 && sum[str.length()-pref[i]]>0) {
				res++;
				break;
			}
			sum[suf[i+1]]--;
		}
	}
	
	cout<<res<<endl;

    return 0;

}
