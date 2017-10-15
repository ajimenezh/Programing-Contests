
#line 3 "LR.cpp"
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

class LR {
	public:
	string construct(vector<long long> s, vector<long long> t) {


		for (int i=0; i<=100; i++) {
            for (int j=0; j+i<=100; j++) {

                vector<long long> s2 = s;
                bool good = true;

                for (int k=0; k<i; k++) {

                    vector<long long> s3 = s2;

                    for (int idx = 0; idx<s.size(); idx++) {
                        s2[idx] += s3[(idx+1)%s.size()];
                        if (s2[idx] > t[idx]) good = false;
                    }

                }

                for (int k=0; k<j; k++) {

                    vector<long long> s3 = s2;

                    for (int idx = 0; idx<s.size(); idx++) {
                        s2[idx] += s3[(idx-1+s.size())%s.size()];
                        if (s2[idx] > t[idx]) good = false;
                    }

                }

                for (int idx=0; idx<s.size(); idx++) {
                    if (s2[idx] != t[idx]) good = false;
                }

                //cout<<i<<" "<<j<<endl;
                //for (int idx=0; idx<s.size(); idx++) cout<<s2[idx]<<" "; cout<<endl;

                if (good) {
                    string s;
                    for (int k=0; k<i; k++) s += "R";
                    for (int k=0; k<j; k++) s += "L";
                    return s;
                }

            }
		}

		return "No solution";

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
		cout << "Testing LR (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1508077181;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LR _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long s[] = {0,1,0,0,0};
				long long t[] = {0,1,2,1,0};
				_expected = "LL";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 1:
			{
				long long s[] = {0,0,0,1};
				long long t[] = {0,1,0,0};
				_expected = "No solution";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 2:
			{
				long long s[] = {1,2,3,4,5,6,7,8,9,10};
				long long t[] = {12,24,56,95,12,78,0,100,54,88};
				_expected = "No solution";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 3:
			{
				long long s[] = {1,0,0};
				long long t[] = {11,11,10};
				_expected = "RRRRR";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 4:
			{
				long long s[] = {1,1};
				long long t[] = {562949953421312,562949953421312};
				_expected = "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 5:
			{
				long long s[] = {0,0,0,0,0};
				long long t[] = {0,0,0,1,0};
				_expected = "No solution";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 6:
			{
				long long s[] = {123,456};
				long long t[] = {123,456};
				_expected = "";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			/*case 7:
			{
				long long s[] = ;
				long long t[] = ;
				_expected = ;
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}*/
			/*case 8:
			{
				long long s[] = ;
				long long t[] = ;
				_expected = ;
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}*/
			/*case 9:
			{
				long long s[] = ;
				long long t[] = ;
				_expected = ;
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
