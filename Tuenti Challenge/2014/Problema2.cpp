#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h> 
#include <set>
#include <fstream>
#include <vector>
using namespace std;

vector<int> vx,vy;
vector<bool> vis;
vector<vector<char> > mapa;
vector<bool> vert;

int main() {
	
  //freopen("students.txt","r",stdin);
  //freopen("output.txt","w",stdout);
    
  string s;
    
  getline(cin,s);

  int x = -1;
  for (int i=0; i<s.length(); i++) {
		if (s[i]=='#') {
			x = i;
			break;
		}
	}
	
	vx.resize(s.length());
	vy.resize(s.length());
	vis.resize(s.length());
	vert = vector<bool> (s.length(), 0);
	
	vx[x] = 0;
	vy[x] = 0;
	vis[x] = 1;
	x = (x+1)%s.length();
	
	bool hor = 1;
	int dir = 1;
	
	while (!vis[x]) {
		vis[x] = 1;
		
		int last = (x-1 + s.length())%s.length();
		
		if (s[x]=='-') {
			if (hor) {
				vx[x] = vx[last] + dir;
				vy[x] = vy[last];
			}
			else {
				vx[x] = vx[last];
				vy[x] = vy[last] + dir;
				vert[x] = 1;
			}
		}
		else if (s[x]=='/') {
			if (hor) {
				vx[x] = vx[last] + dir;
				vy[x] = vy[last];
				
				dir = -dir;
				hor = 0;
			}
			else {
				vx[x] = vx[last];
				vy[x] = vy[last] + dir;
				
				dir = -dir;
				hor = 1;
			}
		}
		else if (s[x]=='\\') {
			if (hor) {
				vx[x] = vx[last] + dir;
				vy[x] = vy[last];
				
				hor = 0;
			}
			else {
				vx[x] = vx[last];
				vy[x] = vy[last] + dir;
				
				hor = 1;
			}
		}
		
		x = (x+1)%s.length();
	}
	
	int mx = 0;
	for (int i=0; i<s.length(); i++) mx = min(mx, vx[i]);
	int my = 0;
	for (int i=0; i<s.length(); i++) my = min(my, vy[i]);
	
	for (int i=0; i<s.length(); i++) {
		vx[i] -= mx;
		vy[i] -= my;
	}
	
	mx = 0;
	my = 0;
	for (int i=0; i<s.length(); i++) mx = max(mx, vx[i]);
	for (int i=0; i<s.length(); i++) my = max(my, vy[i]);
	
	mapa = vector<vector<char> > (my+1, vector<char> (mx+1, ' '));
	
	for (int i=0; i<s.length(); i++) {
		if (!vert[i]) mapa[vy[i]][vx[i]] = s[i];
		else mapa[vy[i]][vx[i]] = '|';
	}
	
	for (int i=0; i<my+1; i++) {
		for (int j=0; j<mx+1; j++) cout<<mapa[i][j];
		cout<<"\n";
	}
	
	return 0;
}
