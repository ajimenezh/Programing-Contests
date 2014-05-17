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


class TwinTowns {
	public:
	vector <int> optimalTwinTowns(vector <int> x, vector <int> y, int maxPartners, int minDistance) ;
};

pair<int,int> dp[2][1<<20];
int d[11][11];
int mp, md;
int n;


vector <int> TwinTowns::optimalTwinTowns(vector <int> x, vector <int> y, int maxPartners, int minDistance) {
	mp = maxPartners;
	md = minDistance;
	n = x.size();
	for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) d[i][j] = abs(x[i]-x[j]) + abs(y[i] - y[j]);

	pair<int,int> res = make_pair(0,0);
	for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int cur = (i*n + j)%2;
            int next = 1-cur;
            for (int k=0; k<(1<<(2*n)); k++) dp[next][k] = make_pair(0,0);
            for (int k=0; k<(1<<(2*n)); k++) {

                int h = (k&(1<<(2*i))) + (k&(1<<(2*i+1)));
                int r = (k&(1<<(2*j))) + (k&(1<<(2*j+1)));

                h >>= 2*i;
                r >>= 2*j;

                if (j>i && d[i][j]>=md && h<mp && r<mp) {
                    pair<int,int> tmp = dp[cur][k];
                    if (dp[next][k+(1<<(2*i))+(1<<(2*j))].first<tmp.first+1) {
                        dp[next][k+(1<<(2*i))+(1<<(2*j))] = make_pair(tmp.first+1, tmp.second+d[i][j]);
                    }
                    else if (dp[next][k+(1<<(2*i))+(1<<(2*j))].first==tmp.first+1) {
                        if (dp[next][k+(1<<(2*i))+(1<<(2*j))].second>tmp.second+d[i][j]) {
                            dp[next][k+(1<<(2*i))+(1<<(2*j))] = make_pair(tmp.first+1, tmp.second+d[i][j]);
                        }
                    }
                }

                pair<int,int> tmp = dp[cur][k];
                if (dp[next][k].first<tmp.first) {
                    dp[next][k] = tmp;
                }
                else if (dp[next][k].first==tmp.first) {
                    if (dp[next][k].second>tmp.second) {
                        dp[next][k] = tmp;
                    }
                }
            }
            for (int k=0; k<(1<<(2*n)); k++) {
                pair<int,int> tmp = dp[next][k];
                if (res.first<tmp.first) res = tmp;
                else if (res.first==tmp.first && res.second>tmp.second) res = tmp;
            }
        }
	}

	vector<int> v;
	v.push_back(res.first);
	v.push_back(res.second);
	return v;
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
		cout << "Testing TwinTowns (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396871064;
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
		TwinTowns _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0,0,10};
				int y[] = {0,10,4};
				int maxPartners = 1;
				int minDistance = 1;
				int __expected[] = {1, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.optimalTwinTowns(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), maxPartners, minDistance); break;
			}
			case 1:
			{
				int x[] = {0,0,10};
				int y[] = {0,10,4};
				int maxPartners = 1;
				int minDistance = 11;
				int __expected[] = {1, 14 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.optimalTwinTowns(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), maxPartners, minDistance); break;
			}
			case 2:
			{
				int x[] = {0,10,0,10};
				int y[] = {0,0,20,20};
				int maxPartners = 1;
				int minDistance = 1;
				int __expected[] = {2, 20 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.optimalTwinTowns(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), maxPartners, minDistance); break;
			}
			case 3:
			{
				int x[] = {0,10,0,10};
				int y[] = {0,0,20,20};
				int maxPartners = 2;
				int minDistance = 10;
				int __expected[] = {4, 60 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.optimalTwinTowns(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), maxPartners, minDistance); break;
			}
			case 4:
			{
				int x[] = {0,0,0,0,0,0,0,0,0,0};
				int y[] = {1,2,3,4,5,6,7,8,9,10};
				int maxPartners = 3;
				int minDistance = 6;
				int __expected[] = {6, 40 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.optimalTwinTowns(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), maxPartners, minDistance); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int maxPartners = ;
				int minDistance = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.optimalTwinTowns(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), maxPartners, minDistance); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int maxPartners = ;
				int minDistance = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.optimalTwinTowns(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), maxPartners, minDistance); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int maxPartners = ;
				int minDistance = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.optimalTwinTowns(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), maxPartners, minDistance); break;
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
