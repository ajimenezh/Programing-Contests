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


class PowerPlants {
	public:
	int minCost(vector <string> connectionCost, string plantList, int numPlants) ;
};

int cost[20][20];
int n;
int dp[1<<16];
int m;

int solve(int mask) {
    if (__builtin_popcount(mask)>=m) return 0;
    if (dp[mask]>=0) return dp[mask];

    int tmp = 100000000;
    for (int i=0; i<n; i++) if ((1<<i)&mask) {
        for (int j=0; j<n; j++) if (((1<<j)&mask)==0) {
            tmp = min(tmp, cost[i][j] + solve(mask | (1<<j)));
        }
    }

    tmp = min(tmp, 100000000);
    dp[mask] = tmp;
    return tmp;
}

int PowerPlants::minCost(vector <string> connectionCost, string plantList, int numPlants) {
	m = numPlants;
	n = plantList.length();
	for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (connectionCost[i][j]>='0' && connectionCost[i][j]<='9') {
                cost[i][j] = connectionCost[i][j] - '0';
            }
            else cost[i][j] = connectionCost[i][j] - 'A' + 10;
        }
	}
	for (int i=0; i<(1<<n); i++) dp[i] = -1;
	int mask = 0;
	for (int i=0; i<n; i++) if (plantList[i]=='Y') mask |= (1<<i);
	int res = solve(mask);
	if (res==100000000) return -1;
	return res;
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
		cout << "Testing PowerPlants (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394025096;
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
		PowerPlants _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string connectionCost[] = {"024",
				                           "203",
				                           "430"};
				string plantList = "YNN";
				int numPlants = 3;
				_expected = 5;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 1:
			{
				string connectionCost[] = {"0AB",
				                           "A0C",
				                           "CD0"};
				string plantList = "YNN";
				int numPlants = 3;
				_expected = 21;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 2:
			{
				string connectionCost[] = {"1ABCD",
				                           "35HF8",
				                           "FDM31",
				                           "AME93",
				                           "01390"};
				string plantList = "NYNNN";
				int numPlants = 5;
				_expected = 14;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 3:
			{
				string connectionCost[] = {"012",
				                           "123",
				                           "234"};
				string plantList = "NNY";
				int numPlants = 2;
				_expected = 2;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 4:
			{
				string connectionCost[] = {"1309328",
				                           "DS2389U",
				                           "92EJFAN",
				                           "928FJNS",
				                           "FJS0DJF",
				                           "9FWJW0E",
				                           "23JFNFS"};
				string plantList = "YYNYYNY";
				int numPlants = 4;
				_expected = 0;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 5:
			{
				string connectionCost[] = {"01","20"};
				string plantList = "YN";
				int numPlants = 2;
				_expected = 1;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			/*case 6:
			{
				string connectionCost[] = ;
				string plantList = ;
				int numPlants = ;
				_expected = ;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}*/
			/*case 7:
			{
				string connectionCost[] = ;
				string plantList = ;
				int numPlants = ;
				_expected = ;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}*/
			/*case 8:
			{
				string connectionCost[] = ;
				string plantList = ;
				int numPlants = ;
				_expected = ;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
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
