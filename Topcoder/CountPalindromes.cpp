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


class CountPalindromes {
	public:
	int count(vector <string> words, int k) ;
};

const long long mod = 835454957;

int n;
vector<string> w;
vector<string> ww;
long long dp[110][55][16][2];
int m;

long long solve(int k, int i, int cur, int f) { //cout<<k<<" "<<i<<" "<<cur<<" "<<f<<endl;
    if (k>m) return 0;
    if (dp[k][i][cur][f]>=0) return dp[k][i][cur][f];

    long long tmp = 0;
    if (f==0) {
        if (cur==w[i].size()) {
            tmp++;
            for (int ii=0; ii<n; ii++) {
                tmp = (tmp + solve(k+w[ii].length()+1, ii, 0,0))%mod;
            }
        }
        else {
            bool good = 1;
            for (int ii=cur; ii<w[i].length(); ii+=2) {
                if (w[i][cur-(cur-ii)/2]!=w[i][w[i].length()-1+(cur-ii)/2]) {
                    good = 0;
                    break;
                }
            }
            if (good) {
                tmp++;
            }
            for (int ii=0; ii<n; ii++) {
                if (w[i].length()-cur >= w[ii].length()) {
                    bool bad = 0;
                    for (int j=w[ii].length()-1; j>=0; j--) {
                        int jj = w[ii].length()-1-j+cur;
                        if (w[i][jj]!=w[ii][j]) {
                            bad = 1;
                            break;
                        }
                    }
                    if (!bad) tmp = (tmp + solve(k+w[ii].length()+1, i, cur+w[ii].length(),0))%mod;
                }
                else {
                    bool bad = 0;
                    for (int j=cur; j<w[i].length(); j++) {
                        int jj = w[ii].length()-1-(j-cur);
                        if (w[ii][jj]!=w[i][j]) {
                            bad = 1;
                            break;
                        }
                    }
                    if (!bad) tmp = (tmp + solve(k+w[ii].length()+1, ii, (w[i].length()-cur),1))%mod;
                }
            }
        }
    }
    else {
        if (cur==ww[i].size()) {
            tmp++;
            for (int ii=0; ii<n; ii++) {
                tmp = (tmp + solve(k+ww[ii].length()+1, ii, 0, 1))%mod;
            }
        }
        else {
            bool good = 1;
            for (int ii=cur; ii<ww[i].length(); ii+=2) {
                if (ww[i][cur+(ii-cur)/2]!=ww[i][ww[i].length()-1-(ii-cur)/2]) {
                    good = 0;
                    break;
                }
            }
            if (good) {
                tmp++;
            }
            for (int ii=0; ii<n; ii++) {
                if (ww[i].length()-cur >= ww[ii].length()) {
                    bool bad = 0;
                    for (int j=ww[ii].length()-1; j>=0; j--) {
                        int jj = ww[ii].length()-1-j+cur;
                        if (ww[ii][j]!=ww[i][jj]) {
                            bad = 1;
                            break;
                        }
                    }
                    if (!bad) tmp = (tmp + solve(k+ww[ii].length()+1, i, cur+ww[ii].length(), 1))%mod;
                }
                else {
                    bool bad = 0;
                    for (int j=cur; j<ww[i].length(); j++) {
                        int jj = ww[ii].length()-1-(j-cur);
                        if (ww[i][j]!=ww[ii][jj]) {
                            bad = 1;
                            break;
                        }
                    }
                    if (!bad) tmp = (tmp + solve(k+ww[ii].length()+1, ii, (ww[i].length()-cur),0))%mod;
                }
            }
        }
    }
    //cout<<k<<" "<<i<<" "<<cur<<" "<<f<<" "<<tmp<<endl;
    dp[k][i][cur][f] = tmp;
    return tmp;
}

int CountPalindromes::count(vector <string> words, int kk) {
	n = words.size();
	w = words;
	ww = words;
	for (int i=0; i<n; i++) reverse(ww[i].begin(),ww[i].end());
	m = kk;
	for (int i=0; i<=m; i++) for (int j=0; j<=n; j++) for (int k=0; k<=15; k++) dp[i][j][k][0] = -1;
	for (int i=0; i<=m; i++) for (int j=0; j<=n; j++) for (int k=0; k<=15; k++) dp[i][j][k][1] = -1;
	long long ans = 0;
	for (int i=0; i<n; i++) {
        ans = (ans + solve(w[i].length(), i, 0,0))%mod;
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
		cout << "Testing CountPalindromes (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1388752255;
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
		CountPalindromes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"tragic","cigar"};
				int k = 24;
				_expected = 1;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), k); break;
			}
			case 1:
			{
				string words[] = {"z","zz"};
				int k = 4;
				_expected = 5;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), k); break;
			}
			case 2:
			{
				string words[] = {"aba","acaba","baca","cac","b","c","a"};
				int k = 70;
				_expected = 370786966;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), k); break;
			}
			case 3:
			{
				string words[] = {"hello"};
				int k = 100;
				_expected = 0;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), k); break;
			}
			/*case 4:
			{
				string words[] = ;
				int k = ;
				_expected = ;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), k); break;
			}*/
			/*case 5:
			{
				string words[] = ;
				int k = ;
				_expected = ;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), k); break;
			}*/
			/*case 6:
			{
				string words[] = ;
				int k = ;
				_expected = ;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), k); break;
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
