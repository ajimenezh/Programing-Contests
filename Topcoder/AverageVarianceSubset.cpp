
#line 3 "AverageVarianceSubset.cpp"
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

vector<int> s;
long long c[55][55];
double ss[55][55], sq[55][55];

double f1(int l, int r) {

    double sum = 0;
    for (int i=l; i<r; i++) {

        for (int k=1; k<r-l+1; k++) {

            sum += 1.0*s[i]*s[i]/k*c[r-l-1][k-1];

        }

    }

    return sum;

}

double f2(int l, int r) {

    for (int i=0; i<=50; i++) {
        for (int j=0; j<=50; j++) {
            ss[i][j] = 0;
            sq[i][j] = 0;
        }
    }

    for (int i=l; i<r; i++) {
        for (int k=1; k<r-l+1; k++) if (k <= i+1-l) {

            ss[i][k] = 1.0*s[i]*c[i-l][k-1];
            if (i-1 >= 0) {
                ss[i][k] += ss[i-1][k] + ss[i-1][k-1];
            }

            sq[i][k] = 1.0*s[i]*s[i]*c[i-l][k-1];
            if (i-1 >= 0) {
                sq[i][k] += sq[i-1][k] + sq[i-1][k-1] + 2.0*ss[i-1][k-1]*s[i];
            }

        }
    }

    double tot = 0;
    for (int k=1; k<r-l+1; k++) tot += sq[r-1][k]/(k*k);

    return tot;

}

class AverageVarianceSubset {
	public:
	double average(vector <int> _s, int R) {

		s = _s;
		sort(s.begin(), s.end());

		for (int i=0; i<=50; i++) {
            c[i][0] = 1;
            c[i][i] = 1;
            for (int j=1; j<i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
		}

		int oldr = -1;
		int r = 0;

		double num = 0;
		double sum = 0;

		for (int i=0; i<s.size(); i++) {

            while (r < s.size() && s[r]-s[i] <= R) r++;

            num += (1<<(r-i))-1;
            sum += f1(i, r) - f2(i, r);



            if (oldr > i) {
                num -= (1<<(oldr-i))-1;
                sum -= f1(i, oldr) - f2(i, oldr);
            }

            oldr = r;
		}

		return sum / num;

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
		cout << "Testing AverageVarianceSubset (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1508068346;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AverageVarianceSubset _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s[] = {1,2,3};
				int R = 1;
				_expected = 0.1;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}
			case 1:
			{
				int s[] = {1,2,3};
				int R = 3;
				_expected = 0.3095238095238096;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}
			case 2:
			{
				int s[] = {5,1,3,2};
				int R = 1000000000;
				_expected = 1.2476851851851847;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}
			case 3:
			{
				int s[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111};
				int R = 123456;
				_expected = 1.1349430459217174E9;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}
			case 4:
			{
				int s[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111};
				int R = 999999999;
				_expected = 9.989198236452121E14;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}
			case 5:
			{
				int s[] = {1,1000000000};
				int R = 1000000000;
				_expected = 8.3333333166666672E16;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}
			case 6:
			{
				int s[] = {1,1000000000};
				int R = 1;
				_expected = 0.0;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}
			/*case 7:
			{
				int s[] = ;
				int R = ;
				_expected = ;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}*/
			/*case 8:
			{
				int s[] = ;
				int R = ;
				_expected = ;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}*/
			/*case 9:
			{
				int s[] = ;
				int R = ;
				_expected = ;
				_received = _obj.average(vector <int>(s, s+sizeof(s)/sizeof(int)), R); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
