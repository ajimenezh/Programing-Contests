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


class TVWatching {
	public:
	int mostMinutes(vector <string> programs) ;
};

vector<int> start, finish;
int n;
int dp[51][51];
int p[51];

int solve(int i, int last) {
    if (i==n) return 0;
    if (dp[i][last]>=0) return dp[i][last];

    int tmp = solve(i+1,last);
    for (int j=i; j<n; j++) {
        if (last==0) tmp = max(tmp, (finish[p[j]]-start[p[j]]) + solve(j+1,j+1));
        else {
            if (start[p[j]]>=finish[p[last-1]]) {
                tmp = max(tmp, (finish[p[j]]-start[p[j]]) + solve(j+1,j+1));
            }
        }
    }

    dp[i][last] = tmp;

    return tmp;
}

bool cmp(int i, int j) {
    if (start[i]==start[j]) return finish[i]>finish[j];
    else return start[i]<start[j];
}

int TVWatching::mostMinutes(vector <string> programs) {
	n = programs.size();
	for (int i=0; i<n; i++) {
        int h1 = (programs[i][0]-'0')*10 + (programs[i][1]-'0');
        int m1 = (programs[i][3]-'0')*10 + (programs[i][4]-'0');

        if (programs[i][5]=='P') {
            if (h1!=12) h1 += 12;
        }
        else {
            if (h1==12) h1 -= 12;
        }

        int h2 = (programs[i][10]-'0')*10 + (programs[i][11]-'0');
        int m2 = (programs[i][13]-'0')*10 + (programs[i][14]-'0');

        if (programs[i][15]=='P') {
            if (h2!=12) h2 += 12;
        }
        else {
            if (h2==12) h2 -= 12;
        }

        int d1 = h1*60 + m1;
        int d2 = h2*60 + m2;

        if (d2<=d1) d2 += 24*60;

        start.push_back(d1);
        finish.push_back(d2);
	}
	for (int i=0; i<n; i++) p[i] = i;
	sort(p,p+n,cmp);
	for (int i=0; i<n; i++) cout<<p[i]<<" "; cout<<endl;

	for (int i=0; i<n; i++) for (int j=0; j<n; j++) dp[i][j] = -1;

	return solve(0,0);
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
		cout << "Testing TVWatching (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379966698;
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
		TVWatching _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string programs[] = {"09:00AM - 12:00PM", "02:00PM - 07:00PM", "09:00PM - 02:00AM"};
				_expected = 780;
				_received = _obj.mostMinutes(vector <string>(programs, programs+sizeof(programs)/sizeof(string))); break;
			}
			case 1:
			{
				string programs[] = {"01:15PM - 11:20PM", "08:00AM - 04:13PM", "03:12PM - 12:06AM", "02:00PM - 02:01PM" };
				_expected = 605;
				_received = _obj.mostMinutes(vector <string>(programs, programs+sizeof(programs)/sizeof(string))); break;
			}
			case 2:
			{
				string programs[] = {"12:34PM - 12:34PM"};
				_expected = 1440;
				_received = _obj.mostMinutes(vector <string>(programs, programs+sizeof(programs)/sizeof(string))); break;
			}
			/*case 3:
			{
				string programs[] = ;
				_expected = ;
				_received = _obj.mostMinutes(vector <string>(programs, programs+sizeof(programs)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string programs[] = ;
				_expected = ;
				_received = _obj.mostMinutes(vector <string>(programs, programs+sizeof(programs)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string programs[] = ;
				_expected = ;
				_received = _obj.mostMinutes(vector <string>(programs, programs+sizeof(programs)/sizeof(string))); break;
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
