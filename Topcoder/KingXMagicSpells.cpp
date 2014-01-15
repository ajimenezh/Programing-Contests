#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)


class KingXMagicSpells {
	public:
	double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) ;
};

double KingXMagicSpells::expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) {
	int n = ducks.size();
	double ans = 0;
	for (int i=0; i<31; i++) {
        vector<double> t1(n,0);
        for (int j=0; j<n; j++) t1[j] = (ducks[j]>>i)&1;

        for (int k=0; k<K; k++) {
            vector<double> tmp(n,0);
            for (int j=0; j<n; j++) {
                tmp[j] += 0.5*( (spellOne[j] & (1<<i)) ? 1.0-t1[j] : t1[j] );
                tmp[spellTwo[j]] += 0.5*t1[j];
            }
            for (int j=0; j<n; j++) t1[j] = tmp[j];
        }

        ans += (1<<i)*t1[0];
	}

	return ans;
};

//BEGIN CUT HERE
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
		cout << "Testing KingXMagicSpells (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384189545;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KingXMagicSpells _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int ducks[] = {5, 3, 7};
				int spellOne[] = {1, 7, 4};
				int spellTwo[] = {1, 0, 2};
				int K = 1;
				_expected = 3.5;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}
			case 1:
			{
				int ducks[] = {5, 8};
				int spellOne[] = {53, 7};
				int spellTwo[] = {1, 0};
				int K = 2;
				_expected = 21.5;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}
			case 2:
			{
				int ducks[] = {123, 456, 789, 1234, 56789};
				int spellOne[] = {0, 0, 0, 0, 0};
				int spellTwo[] = {0, 1, 2, 3, 4};
				int K = 50;
				_expected = 123.0;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}
			case 3:
			{
				int ducks[] = {83291232, 3124231, 192412, 3813249, 629231, 9998989};
				int spellOne[] = {58, 37, 44, 66, 72, 19};
				int spellTwo[] = {2, 0, 1, 5, 4, 3};
				int K = 11;
				_expected = 2.888186784716797E7;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}
			/*case 4:
			{
				int ducks[] = ;
				int spellOne[] = ;
				int spellTwo[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}*/
			/*case 5:
			{
				int ducks[] = ;
				int spellOne[] = ;
				int spellTwo[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int ducks[] = ;
				int spellOne[] = ;
				int spellTwo[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

//END CUT HERE
