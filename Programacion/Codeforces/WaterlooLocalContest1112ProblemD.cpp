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
string s;
int to[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>s;
		bool ok = 1;
		for (int j=0; j<s.length(); j++) s[j] = (s[j]>='A'&&s[j]<='Z'?to[s[j]-'A']:to[s[j]-'a']);
		for (int j=0; j<s.length()/2; j++) if (s[j]!=s[s.length()-j-1]) ok = 0;
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

    return 0;

}
