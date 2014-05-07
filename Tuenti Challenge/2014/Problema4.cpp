#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h> 
#include <set>
#include <fstream>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
using namespace std;

string in, fn;
vector<string> all;
map<string,int> dist;
queue<string> q;
map<string,string> pre;

bool check(string a, string b) {
	int t = 0;
	for (int i=0; i<a.length(); i++) {
		if (a[i]!=b[i]) t++;
		if (t>1) return false;
	}
	if (t>1) return false;
	return true;
}

int main() {
	
	//freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
    
  cin>>in>>fn;
  all.push_back(in);
  all.push_back(fn);
  string s;
  while (cin>>s) all.push_back(s);
  
  q.push(in);
  dist[in] = 1;
  
  while (!q.empty()) {
		
		s = q.front();
		q.pop();
		
		if (s==fn) break;
		
		for (int i=0; i<all.size(); i++) {
			if (check(all[i], s) && !dist[all[i]]) {
				dist[all[i]] = dist[s] + 1;
				pre[all[i]] = s;
				q.push(all[i]);
			}
		}
		
	}
	
	vector<string> v;
	
	s = fn;
	while (pre.find(s)!=pre.end()) {
		v.push_back(s);
		s = pre[s];
	}
	v.push_back(in);
    
    for (int i=v.size()-1; i>=0; i--) {
		cout<<v[i];
		if (i!=0) cout<<"->";
	}
	cout<<"\n";
    
    
}
