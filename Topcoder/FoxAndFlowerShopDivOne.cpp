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


class FoxAndFlowerShopDivOne {
	public:
	int theMaxFlowers(vector <string> flowers, int maxDiff) ;
};

int n,m;
int suml[35][35];
int sump[35][35];
int upper[1810];
int lower[1810];

int solve(vector<string> v, int dif) {
    n = v.size();
	m = v[0].length();

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            suml[i][j] = 0;
            sump[i][j] = 0;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            suml[i][j] = suml[i-1][j] + suml[i][j-1] - suml[i-1][j-1];
            sump[i][j] = sump[i-1][j] + sump[i][j-1] - sump[i-1][j-1];
            if (v[i-1][j-1]=='L') suml[i][j]++;
            if (v[i-1][j-1]=='P') sump[i][j]++;
        }
    }

    int ans = -1;
    for (int k=1; k<n; k++) {
        for (int i=0; i<=2*n*m; i++) upper[i] = -1;
        for (int i=1; i<=k; i++) {
            for (int j=1; j<=m; j++) {
                for (int ii=i; ii<=k; ii++) {
                    for (int jj=j; jj<=m; jj++) {
                        int l = suml[ii][jj] - suml[i-1][jj] - suml[ii][j-1] + suml[i-1][j-1];
                        int p = sump[ii][jj] - sump[i-1][jj] - sump[ii][j-1] + sump[i-1][j-1];
                        if (upper[l-p+n*m]<l+p) upper[l-p+n*m] = l+p;
                    }
                }
            }
        }
        for (int i=0; i<=2*n*m; i++) lower[i] = -1;
        for (int i=k+1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                for (int ii=i; ii<=n; ii++) {
                    for (int jj=j; jj<=m; jj++) {
                        int l = suml[ii][jj] - suml[i-1][jj] - suml[ii][j-1] + suml[i-1][j-1];
                        int p = sump[ii][jj] - sump[i-1][jj] - sump[ii][j-1] + sump[i-1][j-1];
                        if (lower[l-p+n*m]<l+p) lower[l-p+n*m] = l+p;
                        //if (l+p==0) cout<<suml[ii][jj]<<" "<<ii<<" "<<jj<<" "<<i<<" "<<j<<" "<<suml[ii][j-1]<<" "<<suml[i-1][jj]<<" "<<suml[i-1][j-1]<<endl;
                    }
                }
            }
        }

        for (int i=0; i<=2*n*m; i++) if (upper[i]>=0) {
            for (int j=0; j<=2*n*m; j++) if (lower[j]>=0) {
                if (abs(i-n*m+j-n*m)<=dif) {
                    ans = max(ans, upper[i]+lower[j]);
                }
            }
        }
    }

    return ans;

}

int FoxAndFlowerShopDivOne::theMaxFlowers(vector <string> flowers, int maxDiff) {
    n = flowers.size();
	m = flowers[0].length();

	vector<string> reversed;

	for (int i=0; i<m; i++) {
        string tmp;
        for (int j=0; j<n; j++) tmp += flowers[j][m-i-1];
        reversed.push_back(tmp);
	}

	return max(solve(flowers,maxDiff),solve(reversed,maxDiff));

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
		cout << "Testing FoxAndFlowerShopDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1383475542;
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
		FoxAndFlowerShopDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string flowers[] = {"LLL",
				                    "PPP",
				                    "LLL"};
				int maxDiff = 1;
				_expected = 7;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 1:
			{
				string flowers[] = {"LLL",
				                    "PPP",
				                    "LLL"};
				int maxDiff = 0;
				_expected = 6;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 2:
			{
				string flowers[] = {"...",
				                    "...",
				                    "..."};
				int maxDiff = 3;
				_expected = 0;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 3:
			{
				string flowers[] = {"LLPL.LPP",
				                    "PLPPPPLL",
				                    "L.P.PLLL",
				                    "LPL.PP.L",
				                    ".LLL.P.L",
				                    "PPLP..PL"};
				int maxDiff = 2;
				_expected = 38;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 4:
			{
				string flowers[] = {"LLLLLLLLLL",
				                    "LLLLLLLLLL",
				                    "LLLLLLLLLL",
				                    "LLLLLLLLLL",
				                    "LLLLLLLLLL"};
				int maxDiff = 0;
				_expected = -1;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 5:
			{
				string flowers[] = {"LLLP..LLP.PLL.LL..LP",
				                    "L.PL.L.LLLL.LPLLPLP.",
				                    "PLL.LL.LLL..PL...L..",
				                    ".LPPP.PPPLLLLPLP..PP",
				                    "LP.P.PPL.L...P.L.LLL",
				                    "L..LPLPP.PP...PPPL..",
				                    "PP.PLLL.LL...LP..LP.",
				                    "PL...P.PPPL..PLP.L..",
				                    "P.PPPLPLP.LL.L.LLLPL",
				                    "PLLPLLP.LLL.P..P.LPL",
				                    "..LLLPLPPPLP.P.LP.LL",
				                    "..LP..L..LLPPP.LL.LP",
				                    "LPLL.PLLPPLP...LL..P",
				                    "LL.....PLL.PLL.P....",
				                    "LLL...LPPPPL.PL...PP",
				                    ".PLPLLLLP.LPP...L...",
				                    "LL...L.LL.LLLPLPPPP.",
				                    "PLPLLLL..LP.LLPLLLL.",
				                    "PP.PLL..L..LLLPPL..P",
				                    ".LLPL.P.PP.P.L.PLPLL"};
				int maxDiff = 9;
				_expected = 208;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			/*case 6:
			{
				string flowers[] = ;
				int maxDiff = ;
				_expected = ;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}*/
			/*case 7:
			{
				string flowers[] = ;
				int maxDiff = ;
				_expected = ;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}*/
			/*case 8:
			{
				string flowers[] = ;
				int maxDiff = ;
				_expected = ;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
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
