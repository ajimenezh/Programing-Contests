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


class MetroNetwork {
	public:
	double minimizeTime(int start, int destination, vector <string> lines, vector <string> times, vector <int> probabilities, int changeTime, int delay) ;
};

double MetroNetwork::minimizeTime(int start, int destination, vector <string> lines, vector <string> times, vector <int> probabilities, int changeTime, int delay) {
		
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
		cout << "Testing MetroNetwork (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391175692;
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
		MetroNetwork _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int start = 0;
				int destination = 7;
				string lines[] = {"0 1 2 3 4 5 6 7"};
				string times[] = {"2 2 2 2 2 2 2"};
				int probabilities[] = {50};
				int changeTime = 5;
				int delay = 5;
				_expected = 41.5;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
			}
			case 1:
			{
				int start = 0;
				int destination = 3;
				string lines[] = {"0 1","0 2","1 3","2 3"};
				string times[] = {"5","5","5","5"};
				int probabilities[] = {0,0,50,50};
				int changeTime = 5;
				int delay = 20;
				_expected = 40.0;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
			}
			case 2:
			{
				int start = 0;
				int destination = 3;
				string lines[] = {"0 1","0 2","0 1 3","2 3"};
				string times[] = {"5","5","100 5","5"};
				int probabilities[] = {0,0,50,50};
				int changeTime = 5;
				int delay = 20;
				_expected = 35.0;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
			}
			case 3:
			{
				int start = 0;
				int destination = 4;
				string lines[] = {"0 1 2 3","1 3 4","2 4"};
				string times[] = {"10 10 20","100 10","80"};
				int probabilities[] = {0,50,0};
				int changeTime = 5;
				int delay = 100;
				_expected = 105.0;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
			}
			case 4:
			{
				int start = 12;
				int destination = 9;
				string lines[] = {"0 30 1 2 3 4 31 5 6 7",
				                 "38 6 8 32 9 33 10 34 11 0 12 13 14 15 16 36 5 38",
				                 "17 39 18 19 5 8 9 20 21",
				                 "17 39 22 16 23 24 3 25 20 21",
				                 "28 9 20 25 2 27 14 17",
				                 "12 13 27 26 24 4 9 28",
				                 "29 10 1 27 15 22 19",
				                 "11 10 2 26 23 16 22 18"};
				string times[] = {"3 3 2 3 2 3 2 2 5",
				                 "2 1 3 4 3 2 4 2 4 5 1 4 4 2 4 5 4",
				                 "2 4 4 2 2 6 2 4",
				                 "2 8 2 1 1 2 3 1 6",
				                 "6 1 2 2 2 2 6",
				                 "1 7 1 2 2 4 8",
				                 "7 2 3 2 2 4",
				                 "4 4 2 2 1 2 9"};
				int probabilities[] = {20,5,15,50,45,5,10,5};
				int changeTime = 3;
				int delay = 10;
				_expected = 23.228506624999994;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
			}
			case 5:
			{
				int start = 0;
				int destination = 3;
				string lines[] = {"0 1","2 3"};
				string times[] = {"2","2"};
				int probabilities[] = {50,50};
				int changeTime = 5;
				int delay = 5;
				_expected = -1.0;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
			}
			case 6:
			{
				int start = 31;
				int destination = 8;
				string lines[] = {"35 38 1 3 4 7 9 10 12 14 16 18 19 20 21 24 25 26"
				                 ,"7 10 11 13 15 16 19 22 23 25 26 27 30 33 35 38 1"
				                 ,"35 38 1 3 5 6 9 11 13 16 17 19 22 25 26 29 30 32"
				                 ,"24 26 28 29 32 34 37 39 1 4 6 8 11 13 16 17 18 19"
				                 ,"13 15 17 20 22 25 26 29 30 32 35 37 0 2 3 6 7 8"
				                 ,"20 22 24 26 29 31 32 33 36 38 0 3 6 8 9 12 13 14"
				                 ,"12 15 16 18 19 21 22 24 25 26 28 30 31 32 33 35"
				                 ,"32 34 37 38 39 0 2 4 7 9 12 15 17 20 22 23 24 27"};
				string times[] = {"2 4 9 9 4 4 2 9 7 5 8 3 3 6 7 4 1"
				                 ,"1 6 6 8 8 10 7 1 8 10 9 8 9 3 3 2"
				                 ,"2 2 7 9 9 1 9 7 9 6 4 4 1 1 10 2 3"
				                 ,"10 10 6 5 1 9 9 6 10 5 4 7 5 3 1 2 2"
				                 ,"5 1 3 9 2 5 5 6 5 6 3 5 8 8 5 1 6"
				                 ,"4 10 4 1 7 1 9 3 5 3 6 9 2 10 3 9 7"
				                 ,"9 3 6 6 6 3 5 6 10 10 2 2 5 2 6"
				                 ,"1 7 3 6 1 10 2 1 7 4 7 9 7 10 7 3 2"};
				int probabilities[] = {81,5,54,32,6,12,80,38};
				int changeTime = 4;
				int delay = 88;
				_expected = 56.38865447903488;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
			}
			/*case 7:
			{
				int start = ;
				int destination = ;
				string lines[] = ;
				string times[] = ;
				int probabilities[] = ;
				int changeTime = ;
				int delay = ;
				_expected = ;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
			}*/
			/*case 8:
			{
				int start = ;
				int destination = ;
				string lines[] = ;
				string times[] = ;
				int probabilities[] = ;
				int changeTime = ;
				int delay = ;
				_expected = ;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
			}*/
			/*case 9:
			{
				int start = ;
				int destination = ;
				string lines[] = ;
				string times[] = ;
				int probabilities[] = ;
				int changeTime = ;
				int delay = ;
				_expected = ;
				_received = _obj.minimizeTime(start, destination, vector <string>(lines, lines+sizeof(lines)/sizeof(string)), vector <string>(times, times+sizeof(times)/sizeof(string)), vector <int>(probabilities, probabilities+sizeof(probabilities)/sizeof(int)), changeTime, delay); break;
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
