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

class SyllableSorting {
public:
	vector <string> sortWords(vector <string>);
};

char vocal[]={'a','e','i','o','u'};
vector<string> vs[51];
vector<string> vssort[51];
int n;

bool lessthan (int a,int b) {
	int i;
	
	for (i=0; i<min(vssort[a].size(),vssort[b].size()); i++) {

		
		if (vssort[a][i]<vssort[b][i]) return true;
		if (vssort[a][i]>vssort[b][i]) return false;
	}
	
	if (vssort[a].size()==vssort[b].size()) {
		for (i=0; i<min(vssort[a].size(),vssort[b].size()); i++) {
			if (vs[a][i]<vs[b][i]) return true;
			if (vs[a][i]>vs[b][i]) return false;
		}
	}
	else return vssort[a].size()>vssort[b].size();
}

bool voc(char a) {
	for (int i=0; i<5; i++) if (a==vocal[i]) return true;
	return false;
}
	

vector <string> SyllableSorting::sortWords(vector <string> words) {
	
	n = words.size();
	for (int i=0; i<n; i++) {
		string s = words[i];

		int pos = 0;
		
		while (pos<s.length()) {
			string temp;
			while (pos<s.length() && !voc(s[pos])) {temp += s[pos++];}
			while (pos<s.length() && voc(s[pos])) {temp += s[pos++];}
		
			vs[i].push_back(temp);

			
		}
	}
	
	for (int i=0; i<n; i++) {
		vssort[i] = vs[i];
		sort(vssort[i].begin(),vssort[i].end());
	}
	
	vector<bool> vis(n,0);
	vector<string> sol;
	
	for (int i=0; i<n; i++) {
		int ind = -1;
		vector<string> temp;
		
		for (int j=0; j<n; j++) if (!vis[j]) {
			
			if (ind==-1) ind = j;
			else {
				if (lessthan(j,ind)) {
					ind = j;
				}
			}
		}
		
		vis[ind] = 1;
		sol.push_back(words[ind]);
	}
	
	return sol;
		
}


//Powered by [KawigiEdit] 2.0!
