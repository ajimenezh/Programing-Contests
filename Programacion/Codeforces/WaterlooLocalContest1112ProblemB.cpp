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

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	
	while (n--) {
		string s;
		cin>>s;
		
		for (int i=0; i<s.length(); i++) {
			for (int j=0; j<s.length()-1; j++) {
				if (s[j]==s[j+1]) {
					s = s.substr(0,j) + s.substr(j+2,s.length()-j-2);
					break;
				}
			}
		}
		
		bool done = 0;
		for (int i=0; i<s.length(); i++) {
			if (s[i]=='c') {
				bool ok = 0;
				for (int j=i+1; j<s.length(); j++) if (s[j]=='c') {
					if (j-i+1!=7) {
						ok = 1;
						done = 1;
						cout<<"open"<<endl;
						break;
					}
					else {
						ok = 1;
						if (i>0) {
							s = s.substr(0,i-1) + s.substr(j+1,s.length()-i+1-8);
						}
						else if (j<s.length()-1) {
							s = s.substr(0,i) + s.substr(j+2,s.length()-i-9);
						}
						else {
							cout<<"open"<<endl;
							done = 1;
							break;
						}
						break;
					}
				}
				if (!ok) {
					cout<<"open"<<endl;
					done = 1;
				}
				if (done) break;
			}
			if (done) break;
		}
		
		if (done) continue;
		
		for (int i=0; i<s.length(); i++) {
			for (int j=0; j<s.length()-1; j++) {
				if (s[j]==s[j+1]) {
					s = s.substr(0,j) + s.substr(j+2,s.length()-j-2);
					break;
				}
			}
		}
		
		if (s.length()==8 || s.length()==0) cout<<"closed"<<endl;
		else cout<<"open"<<endl;
	}
			

    return 0;

}
