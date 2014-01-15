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


class StrangeDictionary2 {
	public:
	vector <double> getProbabilities(vector <string> words) ;
};

double dp[1<<16][51];
int prev[55], match[55];
int n, m, l;
vector<string> w;

double solve(int mask, int k) {
    if (mask==(1<<k)) return 1.0;
    if ((mask & (1<<k))==0) return 0.0;
    if (dp[mask][k]>-0.5) return dp[mask][k];

    dp[mask][k] = 0;
    int d = 0;

    for (int i=0; i<l; i++) {
        if (prev[i]&mask) {
            d++;
            continue;
        }
        else if ((match[i]&mask)!=mask) {
            d++;
            dp[mask][k] += solve(match[i]&mask, k);
        }
    }

    dp[mask][k] /= d;
    return dp[mask][k];
}

double solve(int x) {
    for (int i=0; i<l; i++) prev[i] = 0;
    for (int j=0; j<l; j++) match[j] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<l; j++) {
            if (w[i][j] < w[x][j]) {
                prev[j] |= (1<<i);
            }
            else if (w[i][j] == w[x][j]) {
                match[j] |= (1<<i);
            }
         }
    }

    return solve((1<<n)-1, x);
}

vector <double> StrangeDictionary2::getProbabilities(vector <string> words) {
    n = words.size();
    m = n-1;
    w = words;
    l = words[0].length();

    vector<double> ans;

    for (int i=0; i<(1<<n); i++) for (int j=0; j<n; j++) dp[i][j] = -1;

    for (int i=0; i<n; i++) {
        ans.push_back(solve(i));
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
		cout << "Testing StrangeDictionary2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384076568;
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
		StrangeDictionary2 _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"hardesttestever"};
				double __expected[] = {1.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"ab", "ba"};
				double __expected[] = {0.5, 0.5 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"aza", "aab", "bba"};
				double __expected[] = {0.3333333333333333, 0.5, 0.16666666666666666 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"};
				double __expected[] = {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 4:
			{
				string words[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string words[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string words[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		bool _passed = _expected.size() == _received.size();
		for (unsigned i = 0; i < _received.size(); i++)
			_passed = _passed && (abs(_expected[i]-_received[i]) < 1e-9 || (_received[i] > min(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9)) && _received[i] < max(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9))));
		if (_passed)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
