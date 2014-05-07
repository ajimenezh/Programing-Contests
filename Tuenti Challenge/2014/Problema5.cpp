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

char v[8][8][100];
int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {1,1,1,0,0,-1,-1,-1};

bool check(int x, int y) {
	
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			if (v[i][j][x]!=v[i][j][y]) return false;
		}
	}
	return true;
}

int main() {
	
	//freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
    
  for (int i=0; i<8; i++) {
		string s;
		cin>>s;
		for (int j=0; j<8; j++) v[i][j][0] = s[j];
	}
	
	int x = 1;
	while (true) {
		
		for (int i=0; i<8; i++) {
			for (int j=0; j<8; j++) {
				if (v[i][j][x-1]=='-') {
					int t = 0;
					for (int k=0; k<8; k++) {
						
						int xx = i + dx[k];
						int yy = j + dy[k];
						
						if (xx>=8 || xx<0 || yy>=8 || yy<0) continue;
						
						if (v[xx][yy][x-1]=='X') t++;
					}
					if (t==3) v[i][j][x] = 'X';
					else v[i][j][x] = '-';
				}
				else {
					int t = 0;
					for (int k=0; k<8; k++) {
						
						int xx = i + dx[k];
						int yy = j + dy[k];
						
						if (xx>=8 || xx<0 || yy>=8 || yy<0) continue;
						
						if (v[xx][yy][x-1]=='X') t++;
					}
					if (t==2 || t==3) v[i][j][x] = 'X';
					else v[i][j][x] = '-';
				}
			}
		}
		
		for (int i=0; i<x; i++) {
			if (check(i,x)) {
				cout<<i<<" "<<x-i<<endl;
				return 0;
			}
		}
		
		x++;
		
	}	
    
    return 0;
}
