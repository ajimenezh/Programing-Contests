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


class ReverseResources {
	public:
	int findDecompositions(string str, vector <string> resources) ;
};

const int mod = 1000000007;
int dp[35][35];
vector<string> v;
string s;
int n;
int m;
int mem[35][35][55][55];

int solve(int, int);

int rec(int in, int len, int k, int i) {
    int tot = 0;
    if (mem[in][len][k][i]>=0) return mem[in][len][k][i];
    if (i==v[k].length()) {
        if (len==0) return 1;
        return 0;
    }
    if (v[k][i]=='%') {
        for (int j=in; j<in+len; j++) {
            tot += (rec(j,len-(j-in), k, i+2)*solve(in,j-in))%mod;
            tot %= mod;
        }
    }
    else {
        int t = in;
        int p = i;
        bool good = 1;
        bool found = 0;
        while (t<in+len && p<v[k].length()) {
            if (v[k][p]=='%') {
                found = 1;
                break;
            }
            else {
                if (v[k][p]!=s[t]) {
                    good = 0;
                    break;
                }
            }
            t++; p++;
        }
        if (good) {
            if (found) {
                tot += rec(t, len-(t-in), k, p-1);
            }
            else tot++;
            tot %= mod;
        }
    }
    mem[in][len][k][i] = tot;
    return tot;
}

int solve(int i, int j) {
    if (i>=j) return 0;
    if (dp[i][j]>=0) return dp[i][j];

    int tmp = 0;
    for (int k=0; k<n; k++) {
        if (s.substr(i,j)==v[k]) tmp++;
        else {
            tmp += rec(i,j,k,0);
        }
    }
    dp[i][j] = tmp;
    return tmp;
}

int ReverseResources::findDecompositions(string str, vector <string> resources) {
	s = str;
	v = resources;
	n = v.size();
	m = s.length();
	for (int i=0; i<m; i++) for (int j=0; j<=m; j++) {
        dp[i][j] = -1;
        for (int k=0; k<n; k++) for (int p=0; p<=50; p++) mem[i][j][k][p] = -1;
	}
	return solve(0,m);
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
		cout << "Testing ReverseResources (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389186627;
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
		ReverseResources _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string str = "Error in module foo, code 123.";
				string resources[] = {"foo", "123", "Error in module %s.", "%s, code %s"};
				_expected = 1;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
			}
			case 1:
			{
				string str = "The fox jumped over the dog.";
				string resources[] = {"The fox %s over the dog.",
				                      "lazy",
				                      "brown",
				                      "jump%s",
				                      "s",
				                      "ed",
				                      "The %s",
				                      "fox %s",
				                      "%s over %s",
				                      "the dog."};
				_expected = 5;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
			}
			case 2:
			{
				string str = "abcde";
				string resources[] = {"%sc%s", "b", "de", "a%s"};
				_expected = 2;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
			}
			case 3:
			{
				string str = "abcde";
				string resources[] = {"%se", "a%s", "%sb%s", "%sc%s", "%sd%s"};
				_expected = 0;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
			}
			case 4:
			{
				string str = "aaaaa";
				string resources[] = {"a","%s%s"};
				_expected = 14;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
			}
			case 5:
			{
				string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
				string resources[] = {"a","aa","%s%s","%sa","a%s","aaa","aa%s","a%sa",
				                     "a%s%s","%saa","%sa%s","%s%sa","%s%s%s","aaaa",
				                     "aaa%s","aa%sa","aa%s%s","a%saa","a%sa%s","a%s%sa",
				                     "a%s%s%s","%saaa","%saa%s","%sa%sa","%sa%s%s",
				                     "%s%saa","%s%sa%s","%s%s%sa","%s%s%s%s","aaaaa",
				                     "aaaa%s","aaa%sa","aaa%s%s","aa%saa","aa%sa%s",
				                     "aa%s%sa","aa%s%s%s","a%saaa","a%saa%s","a%sa%sa",
				                     "a%sa%s%s","a%s%saa","a%s%sa%s","a%s%s%sa",
				                     "a%s%s%s%s","%saaaa","%saaa%s","%saa%sa","%saa%s%s"};
				_expected = 879704799;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
			}
			case 6:
			{
				string str = "aa";
				string resources[] = {"a", "a", "%s%s", "%s%s"};
				_expected = 8;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
			}
			/*case 7:
			{
				string str = ;
				string resources[] = ;
				_expected = ;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string str = ;
				string resources[] = ;
				_expected = ;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string str = ;
				string resources[] = ;
				_expected = ;
				_received = _obj.findDecompositions(str, vector <string>(resources, resources+sizeof(resources)/sizeof(string))); break;
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
