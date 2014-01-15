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


class TheBrickTowerMediumDivOne {
	public:
	vector <int> find(vector <int> heights) ;
};

vector<int> h;

void reduce(vector<int> & v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (h[v[i]]==h[v[j]] && v[j]<v[i]) swap(v[i],v[j]);
        }
    }
}

vector <int> TheBrickTowerMediumDivOne::find(vector <int> heights) {
	vector<pair<int,int> > v;
	h = heights;
	int n = heights.size();
	for (int i=0; i<n; i++) v.push_back(make_pair(heights[i],i));
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	vector<int> ans;
	bool done = 0;
	for (int i=0; i<n; i++) {
        vector<int> tmp;
        for (int j=0; j<i; j++) tmp.push_back(v[j].second);
        for (int j=n-1; j>=i; j--) tmp.push_back(v[j].second);
        reduce(tmp);
        if (!done) {
            ans = tmp;
            done = 1;
        }
        else if (tmp<ans) ans = tmp;

        reverse(tmp.begin(),tmp.end());

        reduce(tmp);

        if (tmp<ans) ans = tmp;

        for (int j=0; j<n; j++) cout<<tmp[j]<<" "; cout<<endl;
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
		cout << "Testing TheBrickTowerMediumDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383432945;
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
		TheBrickTowerMediumDivOne _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int heights[] = {4, 7, 5};
				int __expected[] = {0, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 1:
			{
				int heights[] = {4, 4, 4, 4, 4, 4, 4};
				int __expected[] = {0, 1, 2, 3, 4, 5, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 2:
			{
				int heights[] = {2, 3, 3, 2};
				int __expected[] = {0, 3, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 3:
			{
				int heights[] = {13, 32, 38, 25, 43, 47, 6};
				int __expected[] = {0, 6, 3, 1, 2, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 4:
			{
				int heights[] = {5,3,4,7,1,2,6};
				int __expected[] = {0,1,4,5,2,6,3};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			/*case 5:
			{
				int heights[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int heights[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
