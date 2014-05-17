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


class Hotel {
	public:
	int marketCost(int minCustomers, vector <int> customers, vector <int> cost) ;
};

int dp[1010];
int n;
vector<int> c, cust;

int solve(int k) {
    if (k<=0) return 0;
    if (dp[k]>=0) return dp[k];

    int tmp = 10000000;
    for (int i=0; i<n; i++) tmp = min(tmp, solve(k-cust[i]) + c[i]);

    dp[k] = tmp;
    return tmp;
}

int Hotel::marketCost(int minCustomers, vector <int> customers, vector <int> cost) {
	n = cost.size();
	cust = customers;
	c = cost;
	for (int i=0; i<=minCustomers; i++) dp[i] = -1;
	return solve(minCustomers);
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
		cout << "Testing Hotel (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393675642;
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
		Hotel _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int minCustomers = 10;
				int customers[] = {1,2,3};
				int cost[] = {3,2,1};
				_expected = 4;
				_received = _obj.marketCost(minCustomers, vector <int>(customers, customers+sizeof(customers)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int))); break;
			}
			case 1:
			{
				int minCustomers = 10;
				int customers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				int cost[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				_expected = 10;
				_received = _obj.marketCost(minCustomers, vector <int>(customers, customers+sizeof(customers)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int))); break;
			}
			case 2:
			{
				int minCustomers = 12;
				int customers[] = {5, 1};
				int cost[] = {3, 1};
				_expected = 8;
				_received = _obj.marketCost(minCustomers, vector <int>(customers, customers+sizeof(customers)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int))); break;
			}
			case 3:
			{
				int minCustomers = 100;
				int customers[] = {9, 11, 4, 7, 2, 8};
				int cost[] = {4, 9, 3, 8, 1, 9};
				_expected = 45;
				_received = _obj.marketCost(minCustomers, vector <int>(customers, customers+sizeof(customers)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int))); break;
			}
			/*case 4:
			{
				int minCustomers = ;
				int customers[] = ;
				int cost[] = ;
				_expected = ;
				_received = _obj.marketCost(minCustomers, vector <int>(customers, customers+sizeof(customers)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int minCustomers = ;
				int customers[] = ;
				int cost[] = ;
				_expected = ;
				_received = _obj.marketCost(minCustomers, vector <int>(customers, customers+sizeof(customers)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int minCustomers = ;
				int customers[] = ;
				int cost[] = ;
				_expected = ;
				_received = _obj.marketCost(minCustomers, vector <int>(customers, customers+sizeof(customers)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int))); break;
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
