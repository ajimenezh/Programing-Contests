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


class StrIIRec {
	public:
	string recovstr(int n, int minInv, string minStr) ;
};

bool vis[21];

string StrIIRec::recovstr(int n, int minInv, string minStr) {
	int sum = 0;
	string str;
	bool done = 0;
	string m = minStr;
	for (int j=0; j<m.length(); j++) vis[m[j]-'a'] = 1;
	for (int j=0; j<n; j++) if (!vis[j]) m += char(j+'a');
	for (int j=0; j<n; j++) vis[j] = 0;

	for (int i=0; i<n; i++) {
        if (done) {
            for (int j=0; j<n; j++) if (!vis[j]) {
                int c = 0;
                for (int k=0; k<j; k++) if (!vis[k]) c++;
                if (sum+c+(n-1-i)*(n-2-i)/2>=minInv) {
                    str += char('a'+j);
                    vis[j] = 1;
                    sum += c;
                    break;
                }
            }
        }
        else {
            for (int j=m[i]-'a'; j<n; j++) if (!vis[j]) {
                int c = 0;
                for (int k=0; k<j; k++) if (!vis[k]) c++;
                if (sum+c+(n-1-i)*(n-2-i)/2>=minInv) {
                    str += char('a'+j);
                    vis[j] = 1;
                    sum += c;
                    if (j!=m[i]-'a') done = 1;
                    break;
                }
            }
        }
	}
	if (str==minStr) {
        next_permutation(str.begin(),str.end());
	}

	return str;
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
		cout << "Testing StrIIRec (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383687664;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		StrIIRec _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int minInv = 1;
				string minStr = "ab";
				_expected = "ba";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 1:
			{
				int n = 9;
				int minInv = 1;
				string minStr = "efcdgab";
				_expected = "efcdgabhi";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 2:
			{
				int n = 11;
				int minInv = 55;
				string minStr = "debgikjfc";
				_expected = "kjihgfedcba";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 3:
			{
				int n = 15;
				int minInv = 0;
				string minStr = "e";
				_expected = "eabcdfghijklmno";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 4:
			{
				int n = 9;
				int minInv = 20;
				string minStr = "fcdebiha";
				_expected = "fcdehigba";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			/*case 5:
			{
				int n = ;
				int minInv = ;
				string minStr = ;
				_expected = ;
				_received = _obj.recovstr(n, minInv, minStr); break;
			}*/
			/*case 6:
			{
				int n = ;
				int minInv = ;
				string minStr = ;
				_expected = ;
				_received = _obj.recovstr(n, minInv, minStr); break;
			}*/
			/*case 7:
			{
				int n = ;
				int minInv = ;
				string minStr = ;
				_expected = ;
				_received = _obj.recovstr(n, minInv, minStr); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
