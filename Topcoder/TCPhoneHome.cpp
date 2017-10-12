
#line 3 "TCPhoneHome.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

struct Node {
    Node() {for (int i=0; i<10; i++) next[i] = NULL; val = 0; }
    int val;
    Node* next[10];
};

long long pw[18];

class PrefixTree {
public:

    PrefixTree() { root = new Node(); }

    void add(Node * nd, string & s, int i) {

        if (i == s.length()) {
            nd->val = -1;
            return;
        }

        if (nd->next[s[i]-'0'] == NULL) {
            nd->next[s[i]-'0'] = new Node();
        }

        add(nd->next[s[i]-'0'], s, i+1);
    }

    long long get(Node * nd, int n) {

        if (nd->val == -1) return 0;
        if (n == -1) return 0;

        long long tot = 0;

        for (int i=0; i<10; i++) {
            if (nd->next[i] == NULL) {
                tot += pw[n];
            }
            else {
                tot += get(nd->next[i], n-1);
            }
        }

        return tot;
    }

    Node * root;
};

class TCPhoneHome {
	public:
	long long validNumbers(int digits, vector <string> specialPrefixes) {

        pw[0] = 1;
		for (int i=1; i<18; i++) pw[i] = pw[i-1]*10;

		PrefixTree pt;

		for (int i=0; i<specialPrefixes.size(); i++) pt.add(pt.root, specialPrefixes[i], 0);

		long long res = pt.get(pt.root, digits-1);

		return res;
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
		cout << "Testing TCPhoneHome (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507815406;
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
		TCPhoneHome _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int digits = 17;
				string specialPrefixes[] = {};
				_expected = 1000000000000000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 1:
			{
				int digits = 10;
				string specialPrefixes[] = {"0", "1", "911"};
				_expected = 7990000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 2:
			{
				int digits = 8;
				string specialPrefixes[] = {"1", "12", "123"};
				_expected = 90000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 3:
			{
				int digits = 9;
				string specialPrefixes[] = {"12", "13", "14"};
				_expected = 970000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 4:
			{
				int digits = 3;
				string specialPrefixes[] = {"411"};
				_expected = 999LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			/*case 5:
			{
				int digits = ;
				string specialPrefixes[] = ;
				_expected = LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int digits = ;
				string specialPrefixes[] = ;
				_expected = LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int digits = ;
				string specialPrefixes[] = ;
				_expected = LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
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
