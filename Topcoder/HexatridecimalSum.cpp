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


class HexatridecimalSum {
	public:
	string maximizeSum(vector <string> numbers, int k) ;
};

int cnt[36][55];
int p[36];

string sum(string s, string w) {
    reverse(s.begin(), s.end());
    reverse(w.begin(), w.end());
    string str;
    int i = 0, j = 0;
    int r = 0;
    while (i<s.length() || j<w.length()) {
        if (i==s.length()) {
            char c = w[j];
            int t;
            if (c<='9' && c>='0') t = c-'0';
            else t = c-'A' + 10;

            t += r;
            r = t/36;
            t = t%36;

            if (t<10) c = char('0'+t);
            else c = char('A'+t-10);

            str = c + str;

            j++;
        }
        else if (j==w.length()) {
            char c = s[i];
            int t;
            if (c<='9' && c>='0') t = c-'0';
            else t = c-'A' + 10;

            t += r;
            r = t/36;
            t = t%36;

            if (t<10) c = char('0'+t);
            else c = char('A'+t-10);

            str = c + str;

            i++;
        }
        else {
            char c = s[i];
            int t;
            if (c<='9' && c>='0') t = c-'0';
            else t = c-'A' + 10;

            c = w[j];
            if (c<='9' && c>='0') t += c-'0';
            else t += c-'A' + 10;

            t += r;
            r = t/36;
            t = t%36;

            if (t<10) c = char('0'+t);
            else c = char('A'+t-10);

            str = c + str;

            i++;
            j++;
        }
    }

    char c;
    if (r) {
        if (r<10) c = char('0'+r);
        else c = char('A'+r-10);

        str = c + str;
    }
    return str;
}

string HexatridecimalSum::maximizeSum(vector <string> numbers, int k) {
	for (int i=0; i<numbers.size(); i++) {
        for (int j=0; j<numbers[i].length(); j++) {
            char c = numbers[i][j];
            int t;
            if (c<='9' && c>='0') t = c-'0';
            else t = c-'A' + 10;

            cnt[t][numbers[i].length()-j]++;
        }
	}

	for (int i=0; i<36; i++) for (int j=0; j<52; j++) {
        cnt[i][j+1] += cnt[i][j] / 36;
        cnt[i][j] = cnt[i][j]%36;
	}
	for (int i=0; i<36; i++) p[i] = i;
	for (int i=0; i<36; i++) {
        //for (int k=0; k<10; k++) cout<<cnt[i][k]<<" "; cout<<endl;
        for (int j=i+1; j<36; j++) {
            bool l = 0;
            for (int k=53; k>=0; k--) {
                if (cnt[p[j]][k]>cnt[p[i]][k]) {
                    l = 1;
                    break;
                }
                if (cnt[p[j]][k]<cnt[p[i]][k]) break;
            }
            if (l) swap(p[i],p[j]);
        }
	}
	map<char,char> id;
	for (int i=0; i<k; i++) {
        int t = p[i];
        char c;
        if (t<10) c = char('0'+t);
        else c = char('A'+t-10);
        cout<<c<<endl;
        id[c] = 'Z';
	}
	for (int i=0; i<numbers.size(); i++) {
        for (int j=0; j<numbers[i].length(); j++) {
            char c = numbers[i][j];
            if (id.find(c)!=id.end()) numbers[i][j] = 'Z';
        }
	}
	string s = "";
	for (int i=0; i<numbers.size(); i++) {
        s = sum(s, numbers[i]);
	}
	return s;
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
		cout << "Testing HexatridecimalSum (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397045729;
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
		HexatridecimalSum _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string numbers[] = {"HELLO"};
				int k = 2;
				_expected = "ZZLLO";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 1:
			{
				string numbers[] = {"500", "POINTS", "FOR", "THIS", "PROBLEM"};
				int k = 5;
				_expected = "1100TC85";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 2:
			{
				string numbers[] = {"TO", "BE", "OR", "NOT", "TO", "BE"};
				int k = 0;
				_expected = "QNO";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 3:
			{
				string numbers[] = {"KEQUALS36"};
				int k = 36;
				_expected = "ZZZZZZZZZ";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 4:
			{
				string numbers[] = {"GOOD", "LUCK", "AND", "HAVE", "FUN"};
				int k = 7;
				_expected = "31YUB";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			/*case 5:
			{
				string numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}*/
			/*case 6:
			{
				string numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}*/
			/*case 7:
			{
				string numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
