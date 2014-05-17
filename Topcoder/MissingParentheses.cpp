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

class MissingParentheses {
public:
	int countCorrections(string);
};

int MissingParentheses::countCorrections(string par) {
	int t = 0;
	int l = 0;
	for (int i=0; i<par.length(); i++) {
		if (par[i]=='(') t++;
		else t--;
		
		if (t<0) {
			l++;
			t = 0;
		}
	}
	
	return abs(t) + l;
}


//Powered by [KawigiEdit] 2.0!
