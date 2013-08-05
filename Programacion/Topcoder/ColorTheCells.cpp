#line 2 "ColorTheCells.cpp"

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

vector<int> v;
int n;
vector<int> wait;
int state[8];

int solve(vector<int> &w) {
	int j = 0;
	int cur = 0;
	for (int i=0; i<n; i++) state[i] = 0;
	
	for (int i=0; i<n; i++) { 
		int k;
		if (i==n-1) {
			if (j>w[i]) k = w[i]+1;
			else if (j<w[i]) k = w[i]-1;
			else {
				if (w[i]==n-1) k = n-2;
				else if (w[i]==0) k = 1;
				else if (state[w[i]-1]<state[w[i]+1]) k = w[i]-1;
				else k = w[i]+1;
			}
			
			if (k==-1) k = 1;
			if (k==n) k = n-2;
			
			while (j!=k) {
				if (k<j) {
					int tmp = 1;
					tmp += state[j-1];
					cur += tmp;
					for (int s=0; s<n; s++) state[s] = max(0, state[s]-tmp);
					j--;
				}
				else {
					int tmp = 1;
					tmp += state[j+1];
					cur += tmp;
					for (int s=0; s<n; s++) state[s] = max(0, state[s]-tmp);
					j++;
				}
			}
			return cur+1;
		}
		else {
			if (w[i+1]>w[i]) k = w[i]+1;
			else k = w[i]-1;
			
			if (k==-1) k = 1;
			if (k==n) k = n-2;
			
			while (j!=k) {
				if (k<j) {
					int tmp = 1;
					tmp += state[j-1];
					cur += tmp;
					for (int s=0; s<n; s++) state[s] = max(0, state[s]-tmp);
					j--;
				}
				else {
					int tmp = 1;
					tmp += state[j+1];
					cur += tmp;
					for (int s=0; s<n; s++) state[s] = max(0, state[s]-tmp);
					j++;
				}
			}
			cur++;
			for (int s=0; s<n; s++) state[s] = max(0, state[s]-1);
			state[w[i]] = wait[w[i]];
		}
	}
}

class ColorTheCells {
	public:
	int minimalTime(vector <int> dryingTime) {
		n = dryingTime.size();
		for (int i=0; i<n; i++) v.push_back(i);
		int t = 1000000000;
		wait = dryingTime;
		do {
			t = min(t,solve(v));
		} while (next_permutation(v.begin(),v.end()));
		
		return t;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing ColorTheCells (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375727527;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ColorTheCells _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dryingTime[] = {2, 2, 3};
				_expected = 6;
				_received = _obj.minimalTime(vector <int>(dryingTime, dryingTime+sizeof(dryingTime)/sizeof(int))); break;
			}
			case 1:
			{
				int dryingTime[] = {1, 2, 100, 1};
				_expected = 7;
				_received = _obj.minimalTime(vector <int>(dryingTime, dryingTime+sizeof(dryingTime)/sizeof(int))); break;
			}
			case 2:
			{
				int dryingTime[] = {33, 58, 21, 44};
				_expected = 26;
				_received = _obj.minimalTime(vector <int>(dryingTime, dryingTime+sizeof(dryingTime)/sizeof(int))); break;
			}
			case 3:
			{
				int dryingTime[] = {35198, 26281, 72533, 91031, 44326, 43178, 85530};
				_expected = 26287;
				_received = _obj.minimalTime(vector <int>(dryingTime, dryingTime+sizeof(dryingTime)/sizeof(int))); break;
			}
			/*case 4:
			{
				int dryingTime[] = ;
				_expected = ;
				_received = _obj.minimalTime(vector <int>(dryingTime, dryingTime+sizeof(dryingTime)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int dryingTime[] = ;
				_expected = ;
				_received = _obj.minimalTime(vector <int>(dryingTime, dryingTime+sizeof(dryingTime)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int dryingTime[] = ;
				_expected = ;
				_received = _obj.minimalTime(vector <int>(dryingTime, dryingTime+sizeof(dryingTime)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
