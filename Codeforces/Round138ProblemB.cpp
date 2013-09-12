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

string s,t;
set<char> all;
int pos[200010];
int last[27],last2[27];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>s>>t;
	for (int i=0; i<(int)t.length(); i++) all.insert(t[i]);
	for (int i=0; i<(int)s.length(); i++) if (all.find(s[i])==all.end()) {
		cout<<"No"<<endl;
		return 0;
	}
	
	if (t.size()>s.size()) {
		cout<<"No"<<endl;
		return 0;
	}
	
	int i = s.size()-1;
	int j = t.size()-1;
	
	for (int i=0; i<26; i++) last[i] = -1;
	for (int i=0; i<26; i++) last2[i] = -1;
	
	while (i>=0) {
		if (j>=0 && s[i]==t[j]) {
			last[t[j]-'a'] = j;
			pos[i] = j;
			i--; j--;
		}
		else {
			if (last[s[i]-'a']==-1) {
				cout<<"No"<<endl;
				return 0;
			}
			pos[i] = last[s[i]-'a'];
			i--;
		}
	}
	//for (int i=0; i<s.length(); i++) cout<<pos[i]<<" "; cout<<endl;
	
	if (j!=-1) {
		cout<<"No"<<endl;
		return 0;
	}
	
	i = 0;
	j = 0;
	
	while (i<s.length()) {
		if (j<t.length() && s[i]==t[j]) {
			last2[s[i]-'a'] = j;
			if (j < pos[i]) {
				cout<<"No";
				return 0;
			}
			i++; j++;
		}
		else {
			if (last2[s[i]-'a']==-1 || last2[s[i]-'a']<pos[i]) {
				//cout<<last2[s[i]-'a']<<" "<<pos[i]<<" "<<i<<endl;
				cout<<"No"<<endl;
				return 0;
			}
			i++;
		}
	}
	
	if (j==t.length()) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

    return 0;

}
