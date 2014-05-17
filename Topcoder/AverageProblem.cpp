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


class AverageProblem {
	public:
	int numberOfParticipants(vector <string> marks) ;
};

int a[2550];

int AverageProblem::numberOfParticipants(vector <string> marks) {
	int n = marks.size();
	int t = 0;
	for (int i=0; i<n; i++) {
        string s;
        stringstream ss(marks[i]);
        while (ss>>s) {
            int k = 0;
            if (s.length()==6) {
                k += 10000*(s[0]-'0');
                k += 1000*(s[1]-'0');
                k += 100*(s[3]-'0');
                k += 10*(s[4]-'0');
                k += (s[5]-'0');
            }
            else {
                k += 1000*(s[0]-'0');
                k += 100*(s[2]-'0');
                k += 10*(s[3]-'0');
                k += (s[4]-'0');
            }
            a[t++] = k;
        }
	}
	n = t;
	t = 1;
	while (true) {
        bool good = 1;
        for (int i=0; i<n; i++) {
            if ((t*a[i])%1000!=0) {
                int tmp = (a[i]*t - (t*a[i])%1000) + 1000;
                if (tmp >= (a[i] + 1)*t) {
                    good = 0;
                    break;
                }
            }
        }
        if (good) break;
        t++;
	}
	return t;
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
		cout << "Testing AverageProblem (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393592748;
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
		AverageProblem _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string marks[] = {"0.000"};
				_expected = 1;
				_received = _obj.numberOfParticipants(vector <string>(marks, marks+sizeof(marks)/sizeof(string))); break;
			}
			case 1:
			{
				string marks[] = {"0.500 0.250", "0.125"};
				_expected = 8;
				_received = _obj.numberOfParticipants(vector <string>(marks, marks+sizeof(marks)/sizeof(string))); break;
			}
			case 2:
			{
				string marks[] = {"0.500","0.300"};
				_expected = 10;
				_received = _obj.numberOfParticipants(vector <string>(marks, marks+sizeof(marks)/sizeof(string))); break;
			}
			case 3:
			{
				string marks[] = {"0.500","0.301"};
				_expected = 106;
				_received = _obj.numberOfParticipants(vector <string>(marks, marks+sizeof(marks)/sizeof(string))); break;
			}
			case 4:
			{
				string marks[] = {"10.000","2.000 5.000"};
				_expected = 1;
				_received = _obj.numberOfParticipants(vector <string>(marks, marks+sizeof(marks)/sizeof(string))); break;
			}
			/*case 5:
			{
				string marks[] = ;
				_expected = ;
				_received = _obj.numberOfParticipants(vector <string>(marks, marks+sizeof(marks)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string marks[] = ;
				_expected = ;
				_received = _obj.numberOfParticipants(vector <string>(marks, marks+sizeof(marks)/sizeof(string))); break;
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
