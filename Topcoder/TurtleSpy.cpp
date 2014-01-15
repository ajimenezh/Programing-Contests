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


class TurtleSpy {
	public:
	double maxDistance(vector <string> commands) ;
};

vector<int> v;
bool dp[50][36010];
bool ang[360];
const double pi = acos(-1.0);

double TurtleSpy::maxDistance(vector <string> commands) {
	int fr = 0, bw = 0;
	for (int i=0; i<commands.size(); i++) {
        if (commands[i][0]=='f') {
            string s = commands[i];
            s = s.substr(8,s.length()-8);
            fr += atoi(s.c_str());
        }
        else if (commands[i][0]=='b') {
            string s = commands[i];
            s = s.substr(9,s.length()-9);
            bw += atoi(s.c_str());
        }
        else if (commands[i][0]=='l') {
            string s = commands[i];
            s = s.substr(5,s.length()-5);
            v.push_back(atoi(s.c_str()));
        }
        else if (commands[i][0]=='r') {
            string s = commands[i];
            s = s.substr(6,s.length()-6);
            v.push_back(-atoi(s.c_str()));
        }
	}

	int n = v.size();
	int m = 360*50;
	dp[0][m] = 1;

	for (int i=0; i<n; i++) {
        for (int j=-360*n; j<=360*n; j++) if (dp[i][j+m]) {
            if (j+v[i]<-360*n || j+v[i]>360*n) continue;
            dp[i+1][j+v[i]+m] = 1;
            dp[i+1][j+m] = 1;
        }
	}
	for (int j=-360*n; j<=360*n; j++) if (dp[n][j+m]) {
        int tmp = (j%360 + 360)%360;
        ang[tmp] = 1;
	}

	double ans = 0;
	for (int j=0; j<360; j++) if (ang[j]) {
        double x = fr - bw*cos(1.0*j*pi/180.0);
        double y = -bw*sin(1.0*j*pi/180.0);
        double tmp = sqrt(x*x + y*y);
        ans = max(ans, tmp);
        x = bw - fr*cos(1.0*j*pi/180.0);
        y = -fr*sin(1.0*j*pi/180.0);
        tmp = sqrt(x*x + y*y);
        ans = max(ans, tmp);
	}

	return ans;

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
		cout << "Testing TurtleSpy (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384186789;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TurtleSpy _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string commands[] = {"forward 100", "backward 100", "left 90" };
				_expected = 141.4213562373095;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 1:
			{
				string commands[] = {"left 45", "forward 100", "right 45", "forward 100"};
				_expected = 200.0;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 2:
			{
				string commands[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" };
				_expected = 40.58520737741619;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			/*case 3:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
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

//END CUT HERE
