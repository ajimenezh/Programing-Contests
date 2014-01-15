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


class ServiceNames {
	public:
	vector <string> makeList(vector <string> services) ;
};

vector <string> ServiceNames::makeList(vector <string> services) {
	map<string, vector<string> > all;
	int n = services.size();
	for (int i=0; i<n; i++) {
        string s = services[i];
        stringstream ss(s);
        string item;
        ss>>item;
        while (ss>>s) {
            all[s].push_back(item);
        }
	}
	vector<string> vs;
	rep(it, all) {
        string str;
        str = (*it).first + " ==> ";
        sort((*it).second.begin(), (*it).second.end());
        for (int j=0; j<(*it).second.size(); j++) {
            str += (*it).second[j] + ", ";
        }
        str = str.substr(0,str.length()-2);
        vs.push_back(str);
	}

	return vs;
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
		cout << "Testing ServiceNames (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388663225;
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
		ServiceNames _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string services[] = {"BLAST Genome Annotation Sensitivity","PING","X Annotation"};
				string __expected[] = {"Annotation ==> BLAST, X", "Genome ==> BLAST", "Sensitivity ==> BLAST" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeList(vector <string>(services, services+sizeof(services)/sizeof(string))); break;
			}
			case 1:
			{
				string services[] = {"PING"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeList(vector <string>(services, services+sizeof(services)/sizeof(string))); break;
			}
			case 2:
			{
				string services[] = {"BLAST Genome annotation Sensitivity","PING","X Annotation","Apple X ample"};
				string __expected[] = {"Annotation ==> X", "Genome ==> BLAST", "Sensitivity ==> BLAST", "X ==> Apple", "ample ==> Apple", "annotation ==> BLAST" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeList(vector <string>(services, services+sizeof(services)/sizeof(string))); break;
			}
			/*case 3:
			{
				string services[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeList(vector <string>(services, services+sizeof(services)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string services[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeList(vector <string>(services, services+sizeof(services)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string services[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeList(vector <string>(services, services+sizeof(services)/sizeof(string))); break;
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
