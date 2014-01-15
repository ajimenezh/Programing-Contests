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


class EllysNumbers {
	public:
	long long getSubsets(long long n, vector <string> special) ;
};

vector<int> v;
int m;
bool good[510];
vector<int> all[510];
map<int,int> id;
int mask[510];

long long dp[2][1<<16];

long long EllysNumbers::getSubsets(long long n, vector <string> special) {
    string s;
    for (int i=0; i<special.size(); i++) s += special[i];
    stringstream ss(s);
    while (ss>>s) {
        int a = atoi(s.c_str());
        v.push_back(a);
    }

    long long tmp = n;

    m = v.size();

    int cnt = 0;
    int ones = 0;
    for (int i=0; i<m; i++) {
        if (v[i]==1) {
            good[i] = 0;
            ones++;
            continue;
        }
        if (n%v[i]==0) {
            vector<int> p;
            int k = v[i];
            bool bad = 0;
            for (int j=2; j*j<=k; j++) if (k%j==0) {
                int t = 1;
                while (k%j==0) {
                    k /= j;
                    t *= j;
                }
                long long d = n / t;
                if (d%j==0 || n%t!=0) {
                    bad = 1;
                    break;
                }
                p.push_back(t);
                if (tmp%t==0) tmp /= t;
                if (id.find(t)==id.end()) id[t] = cnt++;
            }
            if (bad) continue;
            if (k!=1) {
                int t = k;
                long long d = n / t;
                if (d%t==0) {
                    bad = 1;
                }
                if (!bad) {
                    p.push_back(t);
                    if (tmp%t==0) tmp /= t;
                    if (id.find(t)==id.end()) id[t] = cnt++;
                }
            }
            if (bad) continue;
            all[i] = p;
            good[i] = 1;
        }
    }

    int top = (1<<cnt) - 1;

    for (int i=0; i<m; i++) if (good[i]) {
        int tmp = 0;
        for (int j=0; j<all[i].size(); j++) {
            int b = id[all[i][j]];
            tmp |= 1<<b;
        }
        mask[i] = tmp;
        //cout<<v[i]<<" "<<mask[i]<<endl;
    }

    if (tmp!=1) return 0;

    dp[0][0] = 1;

    for (int i=0; i<m; i++) {
        int next = 1-i%2;
        for (int j=0; j<=top; j++) dp[next][j] = 0;
        for (int j=0; j<=top; j++) {
            if (dp[i%2][j]==0) continue;
            dp[next][j] += dp[i%2][j];
            if (!good[i]) continue;
            if ((j&mask[i])==0) {
                dp[next][(mask[i]|j)] += dp[i%2][j];
            }
        }
    }

    return dp[m%2][top]*(1LL<<ones);

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
		cout << "Testing EllysNumbers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384345638;
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
		EllysNumbers _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 12LL;
				string special[] = {"4 2 5 6 3"};
				_expected = 1LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 1:
			{
				long long n = 42LL;
				string special[] = {"1 2 3 4 5 6 7 13 14 21 42"};
				_expected = 10LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 2:
			{
				long long n = 1337LL;
				string special[] = {"1 13 42 666 2674"};
				_expected = 0LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 3:
			{
				long long n = 1073741824LL;
				string special[] = {"1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 1",
				                    "6384 32768 65536 131072 262144 524288 1048576 2097",
				                    "152 4194304 8388608 16777216 33554432 67108864 134",
				                    "217728 268435456 536870912"};
				_expected = 0LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 4:
			{
				long long n = 7420738134810LL;
				string special[] = {"435 625199055 4199 33263 17 222870 284870433 72093",
				                    "2379 7 11 31 247110827 23 1771 81809 851968487 13 ",
				                    "476379795 1001 5 435274114 38264554 7429 239906525",
				                    " 3 227183706 887045414 606786670 3795 797605175 29",
				                    " 30 747186719 19 2 562347843 74 2294 588002688 743",
				                    "6429 703 591740547 36657492 37 444178205 1002001 2",
				                    "17626404"};
				_expected = 110LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			/*case 5:
			{
				long long n = LL;
				string special[] = ;
				_expected = LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				long long n = LL;
				string special[] = ;
				_expected = LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				long long n = LL;
				string special[] = ;
				_expected = LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
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
