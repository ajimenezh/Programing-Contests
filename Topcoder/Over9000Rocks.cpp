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


class Over9000Rocks {
	public:
	int countPossibilities(vector <int> lowerBound, vector <int> upperBound) ;
};

vector<pair<int,int> > intv;
vector<pair<int,int> > v;
int n;

int Over9000Rocks::countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
	n = lowerBound.size();
	for (int i=1; i<(1<<n); i++) {
        int l = 0;
        int h = 0;
        for (int j=0; j<n; j++) if ((1<<j)&i) {
            l += lowerBound[j];
            h += upperBound[j];
        }
        intv.push_back(make_pair(l,h));
	}
	sort(intv.begin(),intv.end());

	n = intv.size();
	for (int i=0; i<n;) {
        int j = i+1;
        int x = intv[i].first;
        int y = intv[i].second;
        while (j<n) {
            if (intv[j].first<=y) {
                if (intv[j].second>y) y = intv[j].second;
                j++;
            }
            else break;
        }
        if (x>9000) v.push_back(make_pair(x,y));
        else if (y>9000) v.push_back(make_pair(9001,y));
        i = j;
	}

	int sum = 0;

	for (int i=0; i<v.size(); i++) sum += v[i].second - v[i].first + 1;

	return sum;

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
		cout << "Testing Over9000Rocks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384111804;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Over9000Rocks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int lowerBound[] = {9000};
				int upperBound[] = {9001};
				_expected = 1;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 1:
			{
				int lowerBound[] = {9000, 1, 10};
				int upperBound[] = {9000, 2, 20};
				_expected = 15;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 2:
			{
				int lowerBound[] = {1001, 2001, 3001, 3001};
				int upperBound[] = {1003, 2003, 3003, 3003};
				_expected = 9;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 3:
			{
				int lowerBound[] = {9000,90000,1,10};
				int upperBound[] = {9000,90000,3,15};
				_expected = 38;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 4:
			{
				int lowerBound[] = {1,1,1,1,1,1};
				int upperBound[] = {3,4,5,6,7,8};
				_expected = 0;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			/*case 5:
			{
				int lowerBound[] = ;
				int upperBound[] = ;
				_expected = ;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int lowerBound[] = ;
				int upperBound[] = ;
				_expected = ;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int lowerBound[] = ;
				int upperBound[] = ;
				_expected = ;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
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

//END CUT HERE
