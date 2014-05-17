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


class Glossary {
	public:
	vector <string> buildGlossary(vector <string> items) ;
};

vector<string> vs[26];
vector<string> res;
struct mycomp{
    bool operator()(const string &a, const string &b) {
        string aa = a, bb = b;
        for (int i=0; i<aa.length(); i++) if (aa[i]>='A' && aa[i]<='Z') aa[i] = char(aa[i]-'A'+'a');
        for (int i=0; i<bb.length(); i++) if (bb[i]>='A' && bb[i]<='Z') bb[i] = char(bb[i]-'A'+'a');
        return aa<bb;
    }
}comp;

vector <string> Glossary::buildGlossary(vector <string> items) {
    for (int i=0; i<items.size(); i++) {
        char c = items[i][0];
        if (c>='A' && c<='Z') c = char(c-'A'+'a');
        vs[c-'a'].push_back(items[i]);
    }
    for (int i=0; i<26; i++) sort(vs[i].begin(), vs[i].end(), comp);
    string str = "";
    for (int i=0; i<13; i++) if (vs[i].size()>0) {
        char c = char(i+'A');
        str = "";
        str += c;
        for (int j=0; j<20; j++) str += " ";
        res.push_back(str);
        str = "";
        for (int j=0; j<19; j++) str += "-";
        str += "  ";
        res.push_back(str);
        for (int j=0; j<vs[i].size(); j++) {
            str = "  ";
            str += vs[i][j];
            while (str.length()<21) str += " ";
            res.push_back(str);
        }
    }
    int cur = 0;
    for (int i=13; i<26; i++) if (vs[i].size()>0) {
        if (cur==res.size()) {
            str = "";
            for (int j=0; j<21; j++) str += " ";
            res.push_back(str);
        }
        char c = char(i+'A');
        res[cur] += c;
        for (int j=0; j<18; j++) res[cur] += " ";
        cur++;

        if (cur==res.size()) {
            str = "";
            for (int j=0; j<21; j++) str += " ";
            res.push_back(str);
        }
        for (int j=0; j<19; j++) res[cur] += "-";
        cur++;

        for (int j=0; j<vs[i].size(); j++) {
            if (cur==res.size()) {
                str = "";
                for (int k=0; k<21; k++) str += " ";
                res.push_back(str);
            }
            res[cur] += "  ";
            res[cur]+= vs[i][j];
            while (res[cur].length()<19) res[cur] += " ";
            cur++;
        }
    }
    for (int i=0; i<res.size(); i++) {
        while (res[i].length()<40) res[i] += " ";
    }
    return res;
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
		cout << "Testing Glossary (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393587618;
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
		Glossary _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string items[] = {"Canada", "France", "Germany", "Italy", "Japan", "Russia",
				                  "United Kingdom", "United States"};
				string __expected[] = {"C                    R                  ", "-------------------  -------------------", "  Canada               Russia           ", "F                    U                  ", "-------------------  -------------------", "  France               United Kingdom   ", "G                      United States    ", "-------------------                     ", "  Germany                               ", "I                                       ", "-------------------                     ", "  Italy                                 ", "J                                       ", "-------------------                     ", "  Japan                                 " };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buildGlossary(vector <string>(items, items+sizeof(items)/sizeof(string))); break;
			}
			case 1:
			{
				string items[] = {"alpha", "beta", "gamma", "delta", "omega"};
				string __expected[] = {"A                    O                  ", "-------------------  -------------------", "  alpha                omega            ", "B                                       ", "-------------------                     ", "  beta                                  ", "D                                       ", "-------------------                     ", "  delta                                 ", "G                                       ", "-------------------                     ", "  gamma                                 " };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buildGlossary(vector <string>(items, items+sizeof(items)/sizeof(string))); break;
			}
			case 2:
			{
				string items[] = {"AVL tree", "backtracking", "array", "balanced tree", "binary search"};
				string __expected[] = {"A                                       ", "-------------------                     ", "  array                                 ", "  AVL tree                              ", "B                                       ", "-------------------                     ", "  backtracking                          ", "  balanced tree                         ", "  binary search                         " };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buildGlossary(vector <string>(items, items+sizeof(items)/sizeof(string))); break;
			}
			case 3:
			{
				string items[] = {"XXXXXXXXXXXXXXXXX",
				                  "YYYYYYYYYYYYYYYYY",
				                  "ZZZZZZZZZZZZZZZZZ"};
				string __expected[] = {"                     X                  ", "                     -------------------", "                       XXXXXXXXXXXXXXXXX", "                     Y                  ", "                     -------------------", "                       YYYYYYYYYYYYYYYYY", "                     Z                  ", "                     -------------------", "                       ZZZZZZZZZZZZZZZZZ" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buildGlossary(vector <string>(items, items+sizeof(items)/sizeof(string))); break;
			}
			case 4:
			{
				string items[] = {"Asteria", "Astraeus", "Atlas", "Clymene", "Coeus", "Crius",
				                  "Cronus", "Dione", "Epimetheus", "Helios", "Hyperion", "Iapetus",
				                  "Leto", "Mnemosyne", "Oceanus", "Ophion", "Phoebe", "Prometheus",
				                  "Rhea", "Tethys", "Theia", "Themis"};
				string __expected[] = {"A                    O                  ", "-------------------  -------------------", "  Asteria              Oceanus          ", "  Astraeus             Ophion           ", "  Atlas              P                  ", "C                    -------------------", "-------------------    Phoebe           ", "  Clymene              Prometheus       ", "  Coeus              R                  ", "  Crius              -------------------", "  Cronus               Rhea             ", "D                    T                  ", "-------------------  -------------------", "  Dione                Tethys           ", "E                      Theia            ", "-------------------    Themis           ", "  Epimetheus                            ", "H                                       ", "-------------------                     ", "  Helios                                ", "  Hyperion                              ", "I                                       ", "-------------------                     ", "  Iapetus                               ", "L                                       ", "-------------------                     ", "  Leto                                  ", "M                                       ", "-------------------                     ", "  Mnemosyne                             " };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buildGlossary(vector <string>(items, items+sizeof(items)/sizeof(string))); break;
			}
			/*case 5:
			{
				string items[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buildGlossary(vector <string>(items, items+sizeof(items)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string items[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buildGlossary(vector <string>(items, items+sizeof(items)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string items[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.buildGlossary(vector <string>(items, items+sizeof(items)/sizeof(string))); break;
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
