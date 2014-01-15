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


class BusTrip {
	public:
	int returnTime(int N, vector <string> buses) ;
};

int cnt[55];
int sz[55];
int bus[55][100];
int pos[55];

int BusTrip::returnTime(int N, vector <string> buses) {
    int n = buses.size();
    int m = N;
    for (int i=0; i<n; i++) {
        int j = 0;
        stringstream ss(buses[i]);
        string s;
        while (ss>>s) {
            int a = atoi(s.c_str());
            bus[i][j++] = a;
        }
        sz[i] = j;
    }
    for (int i=0; i<n; i++) {
        pos[i] = -1;
        cnt[i] = 0;
    }
    int now = 0;
    int tmp = 0;
    int t = 0;
    int free = 0;
    int last = 0;
    while (t<1001) {
        //cout<<t<<endl;
        //cout<<now<<" "<<free<<" "<<last<<endl;
        //cout<<pos[0]<<" "<<cnt[0]<<endl;

        if (free==0) {
            bool done = 0;
            for (int j=0; j<n; j++) if (!last) {
                if (cnt[j]==0) {
                    int p = (pos[j]+1)%sz[j];
                    if (free==0 && bus[j][p]==now) {
                        int next = (p+1)%sz[j];
                        free = abs(bus[j][next]-bus[j][p])-1;
                        now = bus[j][next];
                        if (now==0) tmp++;
                        done = 1;
                        break;
                    }
                }
            }
            last = 0;
            if (done) last = 1;
        }
        else free--;
        for (int j=0; j<n; j++) {
            if (cnt[j]==0) {
                int p = (pos[j]+1)%sz[j];
                int next = (p+1)%sz[j];
                cnt[j] = abs(bus[j][next]-bus[j][p])-1;
                pos[j] = p;
            }
            else cnt[j] --;
        }
        t++;
        if (tmp==1) break;
    }
    t += free;
    if (t>1000) return -1;
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
		cout << "Testing BusTrip (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388922291;
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
		BusTrip _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				string buses[] = {"0 1 2"};
				_expected = 12;
				_received = _obj.returnTime(N, vector <string>(buses, buses+sizeof(buses)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 51;
				string buses[] = {"0 5 10 15 20 25 30 35 40 50"};
				_expected = 1000;
				_received = _obj.returnTime(N, vector <string>(buses, buses+sizeof(buses)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 3;
				string buses[] = {"0 1 2", "2 1 0"};
				_expected = -1;
				_received = _obj.returnTime(N, vector <string>(buses, buses+sizeof(buses)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 5;
				string buses[] = {"0 1 2 3 4", "3 1 2 0", "4 1 2 3 0", "1 2 0 3 4", "4 0"};
				_expected = 12;
				_received = _obj.returnTime(N, vector <string>(buses, buses+sizeof(buses)/sizeof(string))); break;
			}
			case 4:
			{
				int N = 25;
				string buses[] = {"24 14 9 7 2", "21 4 18 24 7 1 2 11 8 9 14 16 5 17 13 23 19 15 22", "12 22 24 9 1 5 10 8 7 18 16 19 4 13 17",
				                  "14 5 17 9 23 7 16 22 10 4 6", "19 8 1 9 24 3 5 22 16 7 6 4 10 23 17 0 13 15",
				                  "2 16 10 13 14 1 11 20 0 24 22 23 19 4 18", "19 15 18 0", "15 9 22 5 20 8 23 14 24 18 21 6 13 19",
				                  "2 6 19 3 21 10 20 22 24 13 16 15 8 18 17 14 5", "19 10 1 7 5 11 21 8 14 0 17 23 12 2 3 16"};
				_expected = 157;
				_received = _obj.returnTime(N, vector <string>(buses, buses+sizeof(buses)/sizeof(string))); break;
			}
			case 5:
			{
				int N = 100;
				string buses[] = {"0 10 30 45 60 46 39 31 20", "9 20 0 86"};
				_expected = -1;
				_received = _obj.returnTime(N, vector <string>(buses, buses+sizeof(buses)/sizeof(string))); break;
			}
			/*case 6:
			{
				int N = ;
				string buses[] = ;
				_expected = ;
				_received = _obj.returnTime(N, vector <string>(buses, buses+sizeof(buses)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int N = ;
				string buses[] = ;
				_expected = ;
				_received = _obj.returnTime(N, vector <string>(buses, buses+sizeof(buses)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				int N = ;
				string buses[] = ;
				_expected = ;
				_received = _obj.returnTime(N, vector <string>(buses, buses+sizeof(buses)/sizeof(string))); break;
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
