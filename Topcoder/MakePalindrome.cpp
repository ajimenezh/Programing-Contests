
#line 3 "MakePalindrome.cpp"
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

class MakePalindrome {
	public:
	vector <string> constructMinimal(string card) {

		int cnt[26];
		for (int i=0; i<26; i++) cnt[i] = 0;
		for (int i=0; i<card.size(); i++) cnt[card[i]-'a']++;
		vector<string> s;
		string str;
		for (int i=0; i<26; i++) {
            for (int j=0; j<cnt[i]/2; j++) str += char('a'+i);
            cnt[i] = cnt[i]%2;
		}

		for (int i=0; i<26; i++) if (cnt[i] > 0) {
            string rev = str;
            reverse(rev.begin(), rev.end());
            char c = char('a'+i);
            s.push_back(str + string(1, c) + rev);
            cnt[i] = 0;
            break;
		}

		for (int i=0; i<26; i++) if (cnt[i] > 0) {
            s.push_back("" + string(1, char(i+'a')));
		}

		return s;

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
		cout << "Testing MakePalindrome (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1508067098;
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
		MakePalindrome _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string card = "abbaa";
				string __expected[] = {"ababa" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.constructMinimal(card); break;
			}
			case 1:
			{
				string card = "abc";
				string __expected[] = {"a", "b", "c" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.constructMinimal(card); break;
			}
			case 2:
			{
				string card = "aaabbbccc";
				string __expected[] = {"aba", "bcb", "cac" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.constructMinimal(card); break;
			}
			case 3:
			{
				string card = "topcoder";
				string __expected[] = {"oco", "d", "e", "p", "r", "t" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.constructMinimal(card); break;
			}
			case 4:
			{
				string card = "z";
				string __expected[] = {"z" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.constructMinimal(card); break;
			}
			/*case 5:
			{
				string card = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.constructMinimal(card); break;
			}*/
			/*case 6:
			{
				string card = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.constructMinimal(card); break;
			}*/
			/*case 7:
			{
				string card = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.constructMinimal(card); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
