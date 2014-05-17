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

class DoorsGame {
public:
	int determineOutcome(string, int);
};

int DoorsGame::determineOutcome(string doors, int trophy) {
	int color = 0;
	
	set<char> s;
	map<char,char> m;
	int k = 0;
	for (int i=0; i<doors.size(); i++) {
		if (s.find(doors[i])==s.end()) {
			s.insert(doors[i]);
			m[doors[i]]='A' + (k++);
		}
		doors[i] = m[doors[i]];
	}
	cout<<endl;
	
	int siz = s.size();
	
	for (int i=0; i<trophy; i++) {
		int a = doors[i] - 'A';
		color = color | (1<<a);
	}
	
	int n = __builtin_popcount(color);

	for (int i=0; i<n-1; i++) {

		bool exist = false;
		for (int j=0; j<siz; j++) {
			if ((color & (1<<j)) == 0) {
				color = color | (1<<j);
				exist = true;
				break;
			}
		}
		if (!exist) i++;
	}

	
	int color2 = 0;
	
	for (int i=doors.size()-1; i>=trophy; i--) {
		int a = doors[i] - 'A';
		color2 = color2 | (1<<a);
	}

	n = __builtin_popcount(color2);
	
	for (int i=0; i<n; i++) {
		
		bool exist = false;
		for (int j=0; j<siz; j++) {
			if ((color2 & (1<<j)) == 0) {
				color2 = color2 | (1<<j);
				exist = true;
				break;
			}
		}
		if (!exist) i++;
	}
	
	color = __builtin_popcount(color);
	color2 = __builtin_popcount(color2);
	
	cout<<color<<" "<<color2;
	
	if (color == color2) return 0;
	return color<color2 ? color : -color2;
	

}


//Powered by [KawigiEdit] 2.0!
