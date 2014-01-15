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


class MonsterFarm {
	public:
	int numMonsters(vector <string> transforms) ;
};

const int mod = 1000000007;

bool path[51][51];
int deg[51];
int g[51][51];
long long tot[55][55];

int MonsterFarm::numMonsters(vector <string> transforms) {
    int n = transforms.size();

    for (int i=0; i<n; i++) {
        stringstream ss(transforms[i]);
        string s;
        while (ss>>s) {
            int a = atoi(s.c_str());
            a--;
            path[i][a] = 1;
            deg[i]++;
            g[i][a]++;
        }
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }

    for (int i=0; i<n; i++) {
        if (path[0][i] && deg[i]>=2 && path[i][i]) {
            return -1;
        }
    }

    tot[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (tot[i][j]==0) continue;

            for (int k=0; k<n; k++) {
                tot[i+1][k] = (tot[i+1][k] + tot[i][j]*g[j][k])%mod;
            }
        }
    }

    long long sum = 0;

    for (int i=0; i<n; i++) sum = (sum + tot[n][i])%mod;

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
		cout << "Testing MonsterFarm (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384447067;
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
		MonsterFarm _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string transforms[] = {"1"};
				_expected = 1;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 1:
			{
				string transforms[] = {"1 1"};
				_expected = -1;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 2:
			{
				string transforms[] = {"2", "3", "1"};
				_expected = 1;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 3:
			{
				string transforms[] = {"1", "3 4", "2", "2"};
				_expected = 1;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 4:
			{
				string transforms[] = {"2 2", "3", "4 4 4", "5", "6", "7 7 7 7", "7"};
				_expected = 24;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 5:
			{
				string transforms[] = {"2 3","5 7","2 4","5","6","4","7"};
				_expected = 5;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			/*case 6:
			{
				string transforms[] = ;
				_expected = ;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string transforms[] = ;
				_expected = ;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string transforms[] = ;
				_expected = ;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
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
