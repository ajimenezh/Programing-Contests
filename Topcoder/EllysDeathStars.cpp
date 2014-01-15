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


class EllysDeathStars {
	public:
	double getMax(vector <string> stars, vector <string> ships) ;
};

double EllysDeathStars::getMax(vector <string> stars, vector <string> ships) {
		
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
		cout << "Testing EllysDeathStars (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384034341;
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
		EllysDeathStars _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string stars[] = {"2 2"};
				string ships[] = {"1 1 5 3 2 1 2"};
				_expected = 0.894427190999916;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 1:
			{
				string stars[] = {"12 10", "7 5"};
				string ships[] = {"10 10 12 10 1 1 3", "6 1 8 10 1 2 3", "3 6 8 2 5 3 1", "42 42 42 42 6 6 6"};
				_expected = 4.983770744659944;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 2:
			{
				string stars[] = {"5 77", "60 50", "10 46", "22 97", "87 69"};
				string ships[] = {"42 17 66 11 5 7 13", "10 10 20 20 3 3 3", "13 15 18 9 4 1 2",
				                  "99 71 63 81 19 4 60", "27 34 56 43 11 3 12"};
				_expected = 0.0;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 3:
			{
				string stars[] = {"141 393", "834 847", "568 43", "18 228", "515 794",
				                  "167 283", "849 333", "719 738", "434 261", "613 800",
				                  "127 340", "466 938", "598 601"};
				string ships[] = {"410 951 472 100 337 226 210", "713 352 677 908 731 687 300",
				                  "191 41 337 92 446 716 213", "598 889 446 907 148 650 203",
				                  "168 556 470 924 344 369 198", "300 182 350 936 737 533 45",
				                  "410 871 488 703 746 631 80", "270 777 636 539 172 103 56",
				                  "466 906 522 98 693 77 309", "768 698 846 110 14 643 14",
				                  "755 724 664 465 263 759 120"};
				_expected = 31.965770956316362;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			/*case 4:
			{
				string stars[] = ;
				string ships[] = ;
				_expected = ;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string stars[] = ;
				string ships[] = ;
				_expected = ;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string stars[] = ;
				string ships[] = ;
				_expected = ;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
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
