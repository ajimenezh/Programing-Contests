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

string s1;
string s2;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>s1>>s2;
	
	int i = 0;
	while (true) {
		if (s1[i]=='A' && s2[i]=='B') {
			s1[i]='B';
			i++;
		}
		else if (s1[i]=='B' && s2[i]=='A') {
			s1[i]='A';
			i++;
		}
		else if (s1[i]=='A' && s2[i]=='A') {
			s1 = s1.substr(0,i+1) + "BA" + s1.substr(i+1,s1.length()-i-1);
			i++;
		}
		else if (s1[i]=='B' && s2[i]=='B') {
			s1 = s1.substr(0,i+1) + "AB" + s1.substr(i+1,s1.length()-i-1);
			i++;
		}
		if (i>=s2.length() || i>=s1.length()) break;
	}
	if (s1==s2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

    return 0;

}
