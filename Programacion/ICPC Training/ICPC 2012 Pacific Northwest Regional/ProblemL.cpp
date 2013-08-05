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

string voc = "aiyeou";
string con = "bkxznhdcwgpvjqtsrlmf";

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	string s;
	while (getline(cin,s)) {
		
		string str;
		
		for (int i=0; i<s.length(); i++) {
			if (s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z');
			else {
				str += s[i];
				continue;
			}
			
			bool may = 0;
			if (s[i]>='A' && s[i]<='Z') {
				s[i] = char(s[i]-'A'+'a');
				may = 1;
			}
			bool exist = 0;
			for (int j=0; j<voc.size(); j++) if (s[i]==voc[j]) {
				exist = 1;
				str += voc[(j-3+voc.size())%voc.size()];
				if (may) {
					str[i] = char(str[i]+'A'-'a');
				}
				break;
			}
			if (exist) continue;
			for (int j=0; j<con.size(); j++) if (s[i]==con[j]) {
				exist = 1;
				str += con[(j-10+con.size())%con.size()];
				if (may) {
					str[i] = char(str[i]+'A'-'a');
				}
				break;
			}
		}
		cout<<str<<endl;
		
	}
	
    return 0;

}
