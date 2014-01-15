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


class CardStraights {
	public:
	int longestStraight(vector <int> cards) ;
};

int p[55];
int n;

int CardStraights::longestStraight(vector <int> cards) {
    int joker = 0;
    int n = cards.size();
	for (int i=0; i<n; i++) p[i] = cards[i];
	sort(p,p+n);
	for (int i=0; i<n; i++) if (p[i]==0) joker++;
	int k = 0;
	for (int i=0; i<n; i++) {
        if (i==0 && p[i]!=0) p[k++] = p[i];
        else if (i!=0 && p[i]!=0 && p[i]!=p[i-1]) p[k++] = p[i];
	}
	n = k;
	int i = 0;
	int j = 0;
	int m = joker;
	//cout<<joker<<endl;
	while (i<n) {
        while (j<n) {
            int tmp = p[j]-p[i]+1;
            if (j-i+1+joker<tmp) break;
            j++;
        }
        //cout<<i<<" "<<j<<" "<<p[i]<<" "<<p[j-1]<<endl;
        //cout<<p[j-1]-p[i]+1 + joker - (p[j-1]-p[i]+1-(j-i))<<endl;
        m = max(m, p[j-1]-p[i]+1 + joker - (p[j-1]-p[i]+1-(j-i)));
        i++;
	}
	return m;
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
		cout << "Testing CardStraights (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388749485;
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
		CardStraights _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cards[] = {0,6,5,10,3,0,11};
				_expected = 5;
				_received = _obj.longestStraight(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
			}
			case 1:
			{
				int cards[] = {100,100,100,101,100,99,97,103};
				_expected = 3;
				_received = _obj.longestStraight(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
			}
			case 2:
			{
				int cards[] = {0,0,0,1,2,6,8,1000};
				_expected = 6;
				_received = _obj.longestStraight(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
			}
			case 3:
			{
				int cards[] = {1,9,5,7,3,4,0,0,0,10};
				_expected = 10;
				_received = _obj.longestStraight(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
			}
			/*case 4:
			{
				int cards[] = ;
				_expected = ;
				_received = _obj.longestStraight(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int cards[] = ;
				_expected = ;
				_received = _obj.longestStraight(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int cards[] = ;
				_expected = ;
				_received = _obj.longestStraight(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
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
