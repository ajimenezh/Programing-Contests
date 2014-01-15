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


class TagalogDictionary {
	public:
	vector <string> sortWords(vector <string> words) ;
};

string s1 = "abkdeghilmn";
string s2 = "oprstuwy";
map<char,char> id;
const char sp = 'l';

vector <string> TagalogDictionary::sortWords(vector <string> words) {
	for (int i=0; i<s1.length(); i++) id[s1[i]] = char('a'+i);
	for (int i=0; i<s2.length(); i++) id[s2[i]] = char('m'+i);
	vector<pair<string,int> > vs;
	for (int i=0; i<words.size(); i++) {
        string str;
        for (int j=0; j<words[i].length(); j++) {
            if (words[i][j]=='n' && j<words[i].length()-1 && words[i][j+1]=='g') {
                j++;
                str += "l";
            }
            else str += id[words[i][j]];
        }
        vs.push_back(make_pair(str,i));
	}
	sort(vs.begin(),vs.end());
	vector<string> ans;
	for (int i=0; i<vs.size(); i++) ans.push_back(words[vs[i].second]);
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
		cout << "Testing TagalogDictionary (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389186154;
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
		TagalogDictionary _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"abakada","alpabet","tagalog","ako"};
				string __expected[] = {"abakada", "ako", "alpabet", "tagalog" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortWords(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"ang","ano","anim","alak","alam","alab"};
				string __expected[] = {"alab", "alak", "alam", "anim", "ano", "ang" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortWords(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"siya","niya","kaniya","ikaw","ito","iyon"};
				string __expected[] = {"kaniya", "ikaw", "ito", "iyon", "niya", "siya" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortWords(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"kaba","baka","naba","ngipin","nipin"};
				string __expected[] = {"baka", "kaba", "naba", "nipin", "ngipin" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortWords(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string words[] = {"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","dingdont","ingkblot"};
				string __expected[] = {"kingkong", "knilngiggnngginggn", "dindong", "dingdont", "dingdong", "ingkblot", "ingkigningg" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortWords(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 5:
			{
				string words[] = {"silangang", "baka", "bada", "silang"};
				string __expected[] = {"baka", "bada", "silang", "silangang" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortWords(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 6:
			{
				string words[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortWords(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string words[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortWords(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string words[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortWords(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
