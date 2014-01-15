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


class EncodedSum {
	public:
	long long maximumSum(vector <string> numbers) ;
};

long long cnt[15];
long long p[15];
set<int> zeros;
int v[10];

long long EncodedSum::maximumSum(vector <string> numbers) {
	int n = numbers.size();
	p[0] = 1;
	for (int i=1; i<13; i++) p[i] = p[i-1]*10LL;
	for (int i=0; i<n; i++) {
        for (int j=0; j<numbers[i].length(); j++) {
            cnt[numbers[i][j]-'A'] += p[numbers[i].length()-1-j];
        }
        zeros.insert(numbers[i][0]-'A');
	}

	for (int i=0; i<10; i++) v[i] = i;

	long long sum = 0LL;
	do {
        bool good = 1;
        for (int i=0; i<10; i++) if (v[i]==0) {
            if (zeros.find(i)!=zeros.end()) good = 0;
            break;
        }
        if (!good) continue;
        long long tmp = 0;
        for (int i=0; i<10; i++) tmp += v[i]*cnt[i];
        sum = max(sum, tmp);
	} while(next_permutation(v,v+10));

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
		cout << "Testing EncodedSum (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388494458;
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
		EncodedSum _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string numbers[] = {"ABC",
				                    "BCA"};
				_expected = 1875LL;
				_received = _obj.maximumSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}
			case 1:
			{
				string numbers[] = {"ABCDEFGHIJ"};
				_expected = 9876543210LL;
				_received = _obj.maximumSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}
			case 2:
			{
				string numbers[] = {"ABCDEFGHIJ",
				                    "J"};
				_expected = 9876543202LL;
				_received = _obj.maximumSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}
			case 3:
			{
				string numbers[] = {"A",
				                    "BB",
				                    "CCC",
				                    "DDDD",
				                    "EEEEE",
				                    "FFFFFF",
				                    "GGGGGGG",
				                    "HHHHHHHH",
				                    "IIIIIIIII",
				                    "AJJJJJJJJJ"};
				_expected = 9973936905LL;
				_received = _obj.maximumSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}
			case 4:
			{
				string numbers[] = {"GHJIDDD",
				                    "AHHCCCA",
				                    "IIJCEJ",
				                    "F",
				                    "HDBIGFJAAJ"};
				_expected = 9888114550LL;
				_received = _obj.maximumSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}
			/*case 5:
			{
				string numbers[] = ;
				_expected = LL;
				_received = _obj.maximumSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string numbers[] = ;
				_expected = LL;
				_received = _obj.maximumSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string numbers[] = ;
				_expected = LL;
				_received = _obj.maximumSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string))); break;
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
