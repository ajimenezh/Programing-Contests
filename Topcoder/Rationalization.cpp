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


class Rationalization {
	public:
	int minTweaks(vector <int> weights, vector <string> scores, int desired) ;
};

vector<int> w;
int nw, n;
int m[10][10];
int result[10];
int Rationalization::minTweaks(vector <int> weights, vector <string> scores, int desired) {
    w = weights;
    nw = w.size();

    n = scores.size();

    for (int i=0; i<n; i++) {
        for (int j=0; j<nw; j++) {
            m[i][j] = scores[i][j]-'0';
        }
    }

    for (int i=0; i<(1<<nw); i++) {
        for (int i=0; i<n; i++) {
            result[i] = 0;
            for (int j=0; j<nw; j++) {

            }
        }
    }

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
		cout << "Testing Rationalization (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379269422;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Rationalization _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int weights[] = { 3, 2, 1, 1 };
				string scores[] = { "6354",
				                    "5532",
				                    "4626" };
				int desired = 2;
				_expected = 1;
				_received = _obj.minTweaks(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), vector <string>(scores, scores+sizeof(scores)/sizeof(string)), desired); break;
			}
			case 1:
			{
				int weights[] = { 3, 2, 1, 1 };
				string scores[] = { "6354",
				                    "5532",
				                    "4626" };
				int desired = 1;
				_expected = 2;
				_received = _obj.minTweaks(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), vector <string>(scores, scores+sizeof(scores)/sizeof(string)), desired); break;
			}
			case 2:
			{
				int weights[] = { 3, 2, 1 };
				string scores[] = { "555",
				                    "333" };
				int desired = 1;
				_expected = -1;
				_received = _obj.minTweaks(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), vector <string>(scores, scores+sizeof(scores)/sizeof(string)), desired); break;
			}
			case 3:
			{
				int weights[] = { 1, 2, 3, 3 };
				string scores[] = { "9234",
				                    "1334" };
				int desired = 1;
				_expected = 3;
				_received = _obj.minTweaks(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), vector <string>(scores, scores+sizeof(scores)/sizeof(string)), desired); break;
			}
			case 4:
			{
				int weights[] = { 8, 2 };
				string scores[] = { "55",
				                    "92" };
				int desired = 0;
				_expected = 6;
				_received = _obj.minTweaks(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), vector <string>(scores, scores+sizeof(scores)/sizeof(string)), desired); break;
			}
			case 5:
			{
				int weights[] = { 2, 8, 7, 3, 6, 5, 2, 4, 7, 2 };
				string scores[] = { "9197287893", "9492555365", "3459972761", "4886112198", "5963616776",
				                    "6325897129", "3248793133", "7984474438", "4518544769", "1592681682" };
				int desired = 5;
				_expected = 17;
				_received = _obj.minTweaks(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), vector <string>(scores, scores+sizeof(scores)/sizeof(string)), desired); break;
			}
			/*case 6:
			{
				int weights[] = ;
				string scores[] = ;
				int desired = ;
				_expected = ;
				_received = _obj.minTweaks(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), vector <string>(scores, scores+sizeof(scores)/sizeof(string)), desired); break;
			}*/
			/*case 7:
			{
				int weights[] = ;
				string scores[] = ;
				int desired = ;
				_expected = ;
				_received = _obj.minTweaks(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), vector <string>(scores, scores+sizeof(scores)/sizeof(string)), desired); break;
			}*/
			/*case 8:
			{
				int weights[] = ;
				string scores[] = ;
				int desired = ;
				_expected = ;
				_received = _obj.minTweaks(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), vector <string>(scores, scores+sizeof(scores)/sizeof(string)), desired); break;
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
