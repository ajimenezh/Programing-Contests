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


class GuitarConcert {
	public:
	vector <string> buyGuitars(vector <string> guitarNames, vector <string> guitarSongs) ;
};

bool check(vector<string> a, vector<string> b) {
    for (int i=0; i<a.size(); i++) {
        if (a[i]>b[i]) return true;
        if (a[i]<b[i]) return false;
    }
    return false;
}

vector <string> GuitarConcert::buyGuitars(vector <string> guitarNames, vector <string> guitarSongs) {
	int best = -1;
	vector<string> ans;
	for (int i=0; i<(1<<guitarNames.size()); i++) {
        int tot = 0;
        for (int j=0; j<guitarSongs[0].length(); j++) {
            for (int k=0; k<guitarNames.size(); k++) if (((1<<k)&i) && guitarSongs[k][j]=='Y') {
                tot++;
                break;
            }
        }
        if (tot>best) {
            best = tot;
            ans.clear();
            for (int k=0; k<guitarNames.size(); k++) if ((1<<k)&i) ans.push_back(guitarNames[k]);
            sort(ans.begin(), ans.end());
        }
        else if (tot==best) {
            int t = __builtin_popcount(i);
            if (t<ans.size()) {
                ans.clear();
                for (int k=0; k<guitarNames.size(); k++) if ((1<<k)&i) ans.push_back(guitarNames[k]);
                sort(ans.begin(), ans.end());
            }
            else if (t==ans.size()) {
                vector<string> tmp;
                for (int k=0; k<guitarNames.size(); k++) if ((1<<k)&i) tmp.push_back(guitarNames[k]);
                sort(tmp.begin(), tmp.end());
                if (check(ans, tmp)) {
                    ans = tmp;
                }
            }
        }
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
		cout << "Testing GuitarConcert (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394110410;
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
		GuitarConcert _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string guitarNames[] = {"GIBSON","FENDER", "TAYLOR"};
				string guitarSongs[] = {"YNYYN", "NNNYY", "YYYYY"};
				string __expected[] = {"TAYLOR" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buyGuitars(vector <string>(guitarNames, guitarNames+sizeof(guitarNames)/sizeof(string)), vector <string>(guitarSongs, guitarSongs+sizeof(guitarSongs)/sizeof(string))); break;
			}
			case 1:
			{
				string guitarNames[] = {"GIBSON", "CRAFTER", "FENDER", "TAYLOR"};
				string guitarSongs[] = {"YYYNN", "NNNYY", "YYNNY", "YNNNN"};
				string __expected[] = {"CRAFTER", "GIBSON" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buyGuitars(vector <string>(guitarNames, guitarNames+sizeof(guitarNames)/sizeof(string)), vector <string>(guitarSongs, guitarSongs+sizeof(guitarSongs)/sizeof(string))); break;
			}
			case 2:
			{
				string guitarNames[] = {"AB", "AA", "BA"};
				string guitarSongs[] = {"YN", "YN", "NN"};
				string __expected[] = {"AA" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buyGuitars(vector <string>(guitarNames, guitarNames+sizeof(guitarNames)/sizeof(string)), vector <string>(guitarSongs, guitarSongs+sizeof(guitarSongs)/sizeof(string))); break;
			}
			case 3:
			{
				string guitarNames[] = {"FENDER", "GIBSON", "CRAFTER", "EPIPHONE", "BCRICH"};
				string guitarSongs[] = {"YYNNYNN", "YYYNYNN", "NNNNNYY", "NNYNNNN", "NNNYNNN"};
				string __expected[] = {"BCRICH", "CRAFTER", "GIBSON" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buyGuitars(vector <string>(guitarNames, guitarNames+sizeof(guitarNames)/sizeof(string)), vector <string>(guitarSongs, guitarSongs+sizeof(guitarSongs)/sizeof(string))); break;
			}
			case 4:
			{
				string guitarNames[] = {"GIBSON","FENDER"};
				string guitarSongs[] = {"NNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNN"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buyGuitars(vector <string>(guitarNames, guitarNames+sizeof(guitarNames)/sizeof(string)), vector <string>(guitarSongs, guitarSongs+sizeof(guitarSongs)/sizeof(string))); break;
			}
			case 5:
			{
				string guitarNames[] = {"MAGAWPEMGYIYJPUWZCBE", "PGIJNQYGPZNOVZYAIJZJIOIBIFADU", "MFVUZRNMYVQVVDUT", "OZLSJDPELGLFKHKKUUPROQMXJBEANYUWHMZWMAMQTWTJHVB", "UXBVRBETNGRXQGDHFFFAGYZNVCKQIWYAJMRUBYLTDPBUMJSWJ", "VPVNLXZCMDYDGHXZPAGVXWJCDCWN", "ESGDUGDVHQAQKUQOQLBKRAUL", "EVQZYVTNQQJPGNXQLOIQ", "HTSRJXHAOCTZUXOST", "HGOIHDRWFQBFK"};
				string guitarSongs[] = {"YNNYYNNYNYNNYNY", "YNNYYNYNNNNYNNN", "NNNNYYYNYNYYYNN", "YNNYNYNNNYNNYYN", "YYYYYYNYYYNNNYN", "YNNYYYYNYNYNYYY", "NYNYNYNYNYYYYNN", "NNNNYNYNNNNNYNY", "NNYYYNYNYYNYNNY", "YNYYNNNYNNNYNNY"};
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buyGuitars(vector <string>(guitarNames, guitarNames+sizeof(guitarNames)/sizeof(string)), vector <string>(guitarSongs, guitarSongs+sizeof(guitarSongs)/sizeof(string))); break;
			}
			/*case 6:
			{
				string guitarNames[] = ;
				string guitarSongs[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buyGuitars(vector <string>(guitarNames, guitarNames+sizeof(guitarNames)/sizeof(string)), vector <string>(guitarSongs, guitarSongs+sizeof(guitarSongs)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string guitarNames[] = ;
				string guitarSongs[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buyGuitars(vector <string>(guitarNames, guitarNames+sizeof(guitarNames)/sizeof(string)), vector <string>(guitarSongs, guitarSongs+sizeof(guitarSongs)/sizeof(string))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
