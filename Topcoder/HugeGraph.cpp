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


class HugeGraph {
	public:
	long long countComponents(long long n, vector<long long> d) ;
};

long long HugeGraph::countComponents(long long n, vector<long long> d) {
		
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
		cout << "Testing HugeGraph (1500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1387134349;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HugeGraph _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 5LL;
				long long d[] = {2};
				_expected = 2LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}
			case 1:
			{
				long long n = 6LL;
				long long d[] = {2, 3};
				_expected = 1LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}
			case 2:
			{
				long long n = 10LL;
				long long d[] = {6, 8, 9};
				_expected = 3LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}
			case 3:
			{
				long long n = 100LL;
				long long d[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
				_expected = 10LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}
			case 4:
			{
				long long n = 33LL;
				long long d[] = {30, 29, 26, 15};
				_expected = 5LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}
			case 5:
			{
				long long n = 808LL;
				long long d[] = {195, 774, 788, 781, 723};
				_expected = 71LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}
			case 6:
			{
				long long n = 47933736652472LL;
				long long d[] = {47932970752927, 47933439462262, 2570167893116, 47933306684356, 47931823444952};
				_expected = 2566761627725LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}
			case 7:
			{
				long long n = 45466964736857613LL;
				long long d[] = {33250482667239488, 37822264384529608, 40095838646694298, 43479356281340667, 35203783529829951,
				                 40580747920061306, 43377164971019776, 39064579296221318, 40001593684678420, 33451277901601382,LL
				                 40995812050106167, 37014304154501058, 17759267713188789, 36704554868973353}LL;
				_expected = 3274732884432575LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}
			case 8:
			{
				long long n = 927386907126310589LL;
				long long d[] = {748147148561484840, 701393167746858761, 769696254000454180, 704972921953280463, 759946249333871738,
				                 884450289438010670, 746985782208205106, 774136608403627034, 340934288037171102, 842771692796482305,LL
				                 781200159564662404, 714890479593837724, 692135607544998078, 869198777483846839, 857427314409450650,LL
				                 769959320733418646, 834561823397164073, 859931184678488658, 772342405210344280, 884209280453229287,LL
				                 742707070877737742, 713634305824576668, 885018270712907537, 774793793947310152, 742703922481466469,LL
				                 903242244337866282, 891008000483677106, 811279910869615440, 741113236129095213, 739459726110363505,LL
				                 762358705144212813, 830373753788440496, 908779619221983459, 887664283422679667, 759617794878713552,LL
				                 910640611592949081, 783409949952075625, 863540471792847786, 927341859483997999, 836772868602095563,LL
				                 698935183681576178, 862350615052508395, 878270753526059153, 702073460709372995, 699733226194776258,LL
				                 695875778245571985, 827812810943605830, 873126653781760917, 889807390074772165, 897362441882835952}LL;
				_expected = 95415956985202718LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}
			/*case 9:
			{
				long long n = LL;
				long long d[] = ;
				_expected = LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}*/
			/*case 10:
			{
				long long n = LL;
				long long d[] = ;
				_expected = LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
			}*/
			/*case 11:
			{
				long long n = LL;
				long long d[] = ;
				_expected = LL;
				_received = _obj.countComponents(n, vector<long long>(d, d+sizeof(d)/sizeof(long long))); break;
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
