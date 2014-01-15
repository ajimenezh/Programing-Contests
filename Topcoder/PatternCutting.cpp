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


class PatternCutting {
	public:
	int getMax(int width, int height, vector <string> pattern) ;
};

vector<string> s1, s2, s3, s4;
map<long long, int> dp;
int n,m;

int rec(long long mask) {
    if (dp.find(mask)!=dp.end()) return dp[mask];

    char buf[n][m];
    for (int i=0; i<n*m; i++) {
        if ((1LL<<i)&mask) buf[i/m][i%m] = 'X';
    }

    int tmp = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {

            if (i+s1.size()<=n && j+s1[0].length()<=m) {
                bool good = 1;
                for (int ii=i; ii<i+s1.size(); ii++) {
                    for (int jj=j; jj<j+s1[0].length(); jj++) {
                        if (buf[ii][jj]=='X' && s1[ii-i][jj-j]=='X') {
                            good = 0;
                            break;
                        }
                    }
                }
                if (good) {
                    for (int ii=i; ii<i+s1.size(); ii++) {
                        for (int jj=j; jj<j+s1[0].length(); jj++) {
                            if (s1[ii-i][jj-j]=='X') {
                                buf[ii][jj] = 'X';
                            }
                        }
                    }
                    long long h = 0;
                    for (int ii=0; ii<n*m; ii++) {
                        if (buf[ii/m][ii%m]=='X') h += (1LL<<ii);
                    }
                    tmp = max(tmp,1+rec(h));
                    for (int ii=i; ii<i+s1.size(); ii++) {
                        for (int jj=j; jj<j+s1[0].length(); jj++) {
                            if (s1[ii-i][jj-j]=='X') {
                                buf[ii][jj] = '.';
                            }
                        }
                    }
                }
            }

            if (i+s2.size()<=n && j+s2[0].length()<=m) {
                bool good = 1;
                for (int ii=i; ii<i+s2.size(); ii++) {
                    for (int jj=j; jj<j+s2[0].length(); jj++) {
                        if (buf[ii][jj]=='X' && s2[ii-i][jj-j]=='X') {
                            good = 0;
                            break;
                        }
                    }
                }
                if (good) {
                    for (int ii=i; ii<i+s2.size(); ii++) {
                        for (int jj=j; jj<j+s2[0].length(); jj++) {
                            if (s2[ii-i][jj-j]=='X') {
                                buf[ii][jj] = 'X';
                            }
                        }
                    }
                    long long h = 0;
                    for (int ii=0; ii<n*m; ii++) {
                        if (buf[ii/m][ii%m]=='X') h += (1LL<<ii);
                    }
                    tmp = max(tmp,1+rec(h));
                    for (int ii=i; ii<i+s2.size(); ii++) {
                        for (int jj=j; jj<j+s2[0].length(); jj++) {
                            if (s2[ii-i][jj-j]=='X') {
                                buf[ii][jj] = '.';
                            }
                        }
                    }
                }
            }

            if (i+s3.size()<=n && j+s3[0].length()<=m) {
                bool good = 1;
                for (int ii=i; ii<i+s3.size(); ii++) {
                    for (int jj=j; jj<j+s3[0].length(); jj++) {
                        if (buf[ii][jj]=='X' && s3[ii-i][jj-j]=='X') {
                            good = 0;
                            break;
                        }
                    }
                }
                if (good) {
                    for (int ii=i; ii<i+s3.size(); ii++) {
                        for (int jj=j; jj<j+s3[0].length(); jj++) {
                            if (s3[ii-i][jj-j]=='X') {
                                buf[ii][jj] = 'X';
                            }
                        }
                    }
                    long long h = 0;
                    for (int ii=0; ii<n*m; ii++) {
                        if (buf[ii/m][ii%m]=='X') h += (1LL<<ii);
                    }
                    tmp = max(tmp,1+rec(h));
                    for (int ii=i; ii<i+s3.size(); ii++) {
                        for (int jj=j; jj<j+s3[0].length(); jj++) {
                            if (s3[ii-i][jj-j]=='X') {
                                buf[ii][jj] = '.';
                            }
                        }
                    }
                }
            }

            if (i+s4.size()<=n && j+s4[0].length()<=m) {
                bool good = 1;
                for (int ii=i; ii<i+s4.size(); ii++) {
                    for (int jj=j; jj<j+s4[0].length(); jj++) {
                        if (buf[ii][jj]=='X' && s4[ii-i][jj-j]=='X') {
                            good = 0;
                            break;
                        }
                    }
                }
                if (good) {
                    for (int ii=i; ii<i+s4.size(); ii++) {
                        for (int jj=j; jj<j+s4[0].length(); jj++) {
                            if (s4[ii-i][jj-j]=='X') {
                                buf[ii][jj] = 'X';
                            }
                        }
                    }
                    long long h = 0;
                    for (int ii=0; ii<n*m; ii++) {
                        if (buf[ii/m][ii%m]=='X') h += (1LL<<ii);
                    }
                    tmp = max(tmp,1+rec(h));
                    for (int ii=i; ii<i+s4.size(); ii++) {
                        for (int jj=j; jj<j+s4[0].length(); jj++) {
                            if (s4[ii-i][jj-j]=='X') {
                                buf[ii][jj] = '.';
                            }
                        }
                    }
                }
            }
        }
    }

    dp[mask] = tmp;

    return tmp;
}



int PatternCutting::getMax(int width, int height, vector <string> pattern) {
	s1 = pattern;
	s2 = pattern;
	for (int i=0; i<pattern.size(); i++) {
        for (int j=0; j<pattern[0].length(); j++) {
            s2[i][j] = pattern[pattern.size()-1-i][pattern[0].length()-1-j];
        }
	}
	string tmp;
	for (int i=0; i<pattern.size(); i++) tmp += ".";
	s3 = vector<string> (pattern[0].length(),tmp);
	for (int i=0; i<pattern[0].length(); i++) {
        for (int j=0; j<pattern.size(); j++) {
            s3[i][j] = pattern[j][pattern[0].length()-1-i];
        }
	}
	s4 = s3;
	for (int i=0; i<s3.size(); i++) {
        for (int j=0; j<s3[0].length(); j++) {
            s4[i][j] = s3[s3.size()-1-i][s3[0].length()-1-j];
        }
	}

	n = height;
	m = width;

	if (pattern.size()==1 && pattern[0].length()<3) return n*m/2;
	if (pattern.size()<3 && pattern[0].length()==1) return n*m/2;
	if (pattern.size()==1 && pattern[0].length()==1) return n*m;

	return rec(0);
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
		cout << "Testing PatternCutting (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1379798183;
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
		PatternCutting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 4;
				int height = 5;
				string pattern[] = {"XXX",
				                    ".X."};
				_expected = 4;
				_received = _obj.getMax(width, height, vector <string>(pattern, pattern+sizeof(pattern)/sizeof(string))); break;
			}
			case 1:
			{
				int width = 6;
				int height = 5;
				string pattern[] = {"XX",
				                    "XX"};
				_expected = 6;
				_received = _obj.getMax(width, height, vector <string>(pattern, pattern+sizeof(pattern)/sizeof(string))); break;
			}
			case 2:
			{
				int width = 4;
				int height = 3;
				string pattern[] = {"XXXXX",
				                    "XX..."};
				_expected = 0;
				_received = _obj.getMax(width, height, vector <string>(pattern, pattern+sizeof(pattern)/sizeof(string))); break;
			}
			case 3:
			{
				int width = 6;
				int height = 6;
				string pattern[] = {"XXX",
				                    "X.X",
				                    "XXX"};
				_expected = 4;
				_received = _obj.getMax(width, height, vector <string>(pattern, pattern+sizeof(pattern)/sizeof(string))); break;
			}
			/*case 4:
			{
				int width = ;
				int height = ;
				string pattern[] = ;
				_expected = ;
				_received = _obj.getMax(width, height, vector <string>(pattern, pattern+sizeof(pattern)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int width = ;
				int height = ;
				string pattern[] = ;
				_expected = ;
				_received = _obj.getMax(width, height, vector <string>(pattern, pattern+sizeof(pattern)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int width = ;
				int height = ;
				string pattern[] = ;
				_expected = ;
				_received = _obj.getMax(width, height, vector <string>(pattern, pattern+sizeof(pattern)/sizeof(string))); break;
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
