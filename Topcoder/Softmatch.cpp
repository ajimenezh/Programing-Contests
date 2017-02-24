
#line 3 "Softmatch.cpp"
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

int dp[55][55][5];

class Softmatch {
	public:

    int n, m;
    vector<string> v;
    string s;

    bool same(char t, char x, char y) {
        if (t=='a') {
            if (x=='0' || x=='1') {
                return (y=='0' || y=='1');
            }
            else return (y=='2' || y=='3');
        }
        else {
            if (x=='0' || x=='2') {
                return (y=='0' || y=='2');
            }
            else return (y=='1' || y=='3');
        }
    }

    bool check(int i, int prv, int last, int k, bool flag) {

        if (prv < 0) return false;

        if (n - i < v[k].length()) return false;

        if (flag && v[k].length() < v[last].length() - (i - prv)) return false;
        if (!flag && v[k].length() > v[last].length() - (i - prv)) return false;

        for (int j=i-prv, t=0; j<v[last].length() && t<v[k].length(); j++, t++) {
            //cout<<"--"<<j<<" "<<t<<" "<<v[last][j]<<" "<<v[k][t]<<endl;
            if (!same(s[i+j], v[last][j], v[k][t])) {
                return false;
            }

        }

        return true;

    }

    int solve(int i, int prv, int last) {

        if (i == n) return 0;
        if (dp[i][prv][last] != -1) return dp[i][prv][last];

        int tmp;
        if (prv != 0 && prv-1 + v[last].length() < i+1) {

            int tot = 0;

            for (int k=0; k<m; k++) {

                if (check(i, prv-1, last, k, false)) tot++;

            }

            tmp = solve(i+1, prv, last) + tot;
        }
        else {

            int tot = 0;

            //cout<<i<<" "<<prv-1<<" "<<v[last].length()<<endl;

            for (int k=0; k<m; k++) {

                if (check(i, prv-1, last, k, false)) tot++;

            }

            //cout<<tot<<endl;

            tmp = solve(i+1, 0, last) + tot;
        }

        for (int j=0; j<m; j++) {

            if (prv == 0 || check(i, prv-1, last, j, true)) {

                int tot = 0;
                //cout<<"start"<<endl;
                for (int k=0; k<m; k++) {

                    if (check(i, i, j, k, false)) tot++;

                }

                //cout<<"---->"<<j<<" "<<tot<<endl;

                tmp = max(tmp, tot + solve(i+1, i+1, j));

            }

        }

        //cout<<i<<" "<<prv<<" "<<last<<" "<<tmp<<endl;

        dp[i][prv][last] = tmp;

        return tmp;

    }

	int count(string S, vector <string> patterns) {
		s = S;
		v = patterns;
		n = s.length();
		m = patterns.size();

		for (int i=0; i<n; i++) {
            for (int j=0; j<=n; j++) {
                for (int k=0; k<m; k++) {
                    dp[i][j][k] = -1;
                }
            }
		}

		int res = solve(0, 0, 0);

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
		cout << "Testing Softmatch (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487962721;
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
		Softmatch _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "aaa";
				string patterns[] = {"03","21"};
				_expected = 2;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 1:
			{
				string S = "aba";
				string patterns[] = {"03","11"};
				_expected = 3;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 2:
			{
				string S = "bba";
				string patterns[] = {"00","00"};
				_expected = 4;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 3:
			{
				string S = "bbbbbb";
				string patterns[] = {"1110","011","100"};
				_expected = 3;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 4:
			{
				string S = "abbaa";
				string patterns[] = {"123"};
				_expected = 2;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 5:
			{
				string S = "aababbaab";
				string patterns[] = {"012","332","101", "0313"};
				_expected = 7;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			/*case 6:
			{
				string S = ;
				string patterns[] = ;
				_expected = ;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string S = ;
				string patterns[] = ;
				_expected = ;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string S = ;
				string patterns[] = ;
				_expected = ;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
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
