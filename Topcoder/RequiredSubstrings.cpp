#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class RequiredSubstrings {
public:
	int solve(vector <string>, int, int);
};


int RequiredSubstrings::solve(vector <string> words, int C, int L) {
	int s=0;
	map<string,int> stateID;
	
	stateID[""] = s++;
	
	for (int i=0; i<words.size(); i++) {
		for (int j=1; j<words[i].length();j++) {
			string str = words[i].substr(i,j);
			if (stateID.find(str)==stateID.end()) 
				stateID[str] = s++;
		}
	}
	
	vector<int> nextState(s*26,0);
	for (map<string,int>::iterator it = stateID.begin(); it != stateID.end(); it++) {
		for (char c = 'a'; c<='z'; c++) {
			string str = (*it).first + c;
			
			while (stateID.find(str)==stateID.end()) str = str.substr(1,str.length()-1);
			nextState[26*(*it).second+ (c-'a')] = stateID[str];
		}
	}
	
	vector<int> stateAdds(s,0);
	for (map<string,int>::iterator it = stateID.begin(); it != stateID.end(); it++) {
		int added = 0;
		for (int j=0; j<words.size(); j++) {
			if ((*it).first.length() >= words[j].length() && (*it).first.substr((*it).first.length()-words[j].length(), words[j].length())==words[j]) {
				added = added | (1<<j);
			}
		}
		stateAdds[(*it).second] = added;
	}
	
	long long mod = 1000000009;
	vector<vector<long long> > count(2, vector<long long>(s<<6,0LL));
	count[0][0] = 1;
	for (int i=0; i<L; i++) {
		int cur = i%2;
		int next = 1- cur;
		
		for (int j=0; j<(s<<6); j++) count[next][j] = 0;
		
		for (int j=0; j<(s<<6); j++) {
			if (count[cur][j] > 0) {
				for (int c =0; c<26; c++) {
					int ns = nextState[26*(j>>6) + c];
					int np = (s & 63) | stateAdds[ns];
					count[next][(ns<<6)|np] += count[cur][s]%mod;
				}
			}
		}
	}
	
	long long res = 0;
    for (int i=0; i<(s<<6); i++) {
    	cout<<count[L%2][i]<<endl;
    	if (__builtin_popcount(s&63)==C) res += count[L%2][i];
    }
    res %= mod;
    return res;
}


//Powered by [KawigiEdit] 2.0!
