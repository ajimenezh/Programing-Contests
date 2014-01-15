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


class FloatingMedian {
	public:
	long long sumOfMedians(int seed, int mul, int add, int N, int K) ;
};

int v[250100];
multiset<int> lower, upper;

int get(multiset<int> &s) {
    multiset<int>::iterator it = s.end();
    it--;
    return (*it);
}

long long FloatingMedian::sumOfMedians(int seed, int mul, int add, int N, int K) {
    v[0] = seed;
    for (int i=1; i<N; i++){
        v[i] = ((long long)v[i-1]*mul + add)%65536;
    }
    int k = K/2;
    if (K%2!=0) k++;
    vector<int> tmp;
    for (int i=0; i<K; i++) tmp.push_back(v[i]);
    sort(tmp.begin(), tmp.end());
    for (int i=0; i<k; i++) lower.insert(tmp[i]);
    for (int i=k; i<K; i++) upper.insert(tmp[i]);
    long long sum = 0;
    for (int i=K; i<N; i++) {
        sum += get(lower);
        if (lower.find(v[i-K])!=lower.end()) {
            multiset<int>::iterator it = lower.find(v[i-K]);
            lower.erase(it);
        }
        else {
            multiset<int>::iterator it = upper.find(v[i-K]);
            upper.erase(it);
        }
        if (upper.size()==0 || v[i]<(*upper.begin())) {
            lower.insert(v[i]);
        }
        else {
            upper.insert(v[i]);
        }
        if (lower.size()!=k) {
            while (lower.size()>k) {
                multiset<int>::iterator it = lower.end();
                it--;
                lower.erase(it);
                upper.insert(*it);
            }
            while (lower.size()<k) {
                int t = (*upper.begin());
                upper.erase(upper.begin());
                lower.insert(t);
            }
        }
    }
    sum += get(lower);

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
		cout << "Testing FloatingMedian (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383296825;
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
		FloatingMedian _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int seed = 3;
				int mul = 1;
				int add = 1;
				int N = 10;
				int K = 3;
				_expected = 60LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			case 1:
			{
				int seed = 10;
				int mul = 0;
				int add = 13;
				int N = 5;
				int K = 2;
				_expected = 49LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			case 2:
			{
				int seed = 4123;
				int mul = 2341;
				int add = 1231;
				int N = 7;
				int K = 3;
				_expected = 102186LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			case 3:
			{
				int seed = 47;
				int mul = 5621;
				int add = 1;
				int N = 125000;
				int K = 1700;
				_expected = 4040137193LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			case 4:
			{
				int seed = 32321;
				int mul = 46543;
				int add = 32552;
				int N = 17;
				int K = 17;
				_expected = 25569LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			case 5:
			{
				int seed = 1;
				int mul = 2;
				int add = 0;
				int N = 30;
				int K = 23;
				_expected = 83LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			/*case 6:
			{
				int seed = ;
				int mul = ;
				int add = ;
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}*/
			/*case 7:
			{
				int seed = ;
				int mul = ;
				int add = ;
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
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
