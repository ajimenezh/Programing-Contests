#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

typedef vector<int> VI;
typedef vector<VI> VVI;

int n,m;
string s1,s2;

#define UP 1
#define LEFT 2
#define DIAG 3

struct CyclicAlignment {
	string s,t,tt;
	VVI dp, par, lower, upper;
	
	CyclicAlignment(const string&s, const string &t) :
		s(s), t(t), tt(t+t),
		dp(s.length() + 1, VI(2 * t.length() + 1)),
        par(s.length() + 1, VI(2 * t.length() + 1)),
        lower(t.length() + 1, VI(2 * t.length() + 1, 0)),
        upper(t.length() + 1, VI(2 * t.length() + 1, int(s.length())))
    {}
    
    inline bool valid(int offset, int left, int right, int i, int j) {
        return (j >= offset) && (j <= offset + int(t.length())) &&
               (i >= lower[right][j]) && (i <= upper[left][j]);
    } 
    
    int lcs(int offset, int left, int right) {

        for (int j = offset; j <= offset + int(t.length()); j++) {
            for (int i = lower[right][j]; i <= upper[left][j]; i++) {
                dp[i][j] = 0;
				par[i][j] = 0;
                if (valid(offset, left, right, i-1, j) && dp[i][j] <= dp[i-1][j]) {
                    dp[i][j] = dp[i-1][j];
                    par[i][j] = UP;
                }
                if (valid(offset, left, right, i, j-1) && dp[i][j] <= dp[i][j-1]) {
                    dp[i][j] = dp[i][j-1];
                    par[i][j] = LEFT;
                }
                if (valid(offset, left, right, i-1, j-1) && dp[i][j] <= dp[i-1][j-1] + (s[i-1] == tt[j-1])) {
                    dp[i][j] = dp[i-1][j-1] + (s[i-1] == tt[j-1]);
                    par[i][j] = DIAG;
                }
            }
        }

        for (int j = offset; j <= offset + int(t.length()); ++j) {
            lower[offset][j] = int(s.length());
            upper[offset][j] = 0;
        }
        
        int i = int(s.length());
        int j = offset + int(t.length());
        lower[offset][j] = i;
        upper[offset][j] = i;
        while (j != offset || i != 0) {
			if (par[i][j]==UP) {i--; break;}
			if (par[i][j]==LEFT) {j--; break;}
			if (par[i][j]==DIAG) {i--; j--; break;}

            lower[offset][j] = min(lower[offset][j], i);
            upper[offset][j] = max(upper[offset][j], i);
        }
        return dp[s.length()][offset + int(t.length())];
    }
    
    
    int solve(int left, int right) {
        if (left + 1 < right) {
            int mid = (left + right) / 2;
            int best = lcs(mid, left, right);
            return max(best, max(solve(left, mid), solve(mid, right)));
        }
        return 0;
    }

    int solve() {
        int best1 = lcs(0, 0, 0);

        return max(best1, solve(0, t.length()));
    }
};
		

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	string s;
	while (getline(cin,s)) {
		stringstream ss(s);
		ss>>s1;
		ss>>s2;
		string s3 = s1;
		reverse(s3.begin(),s3.end());
		CyclicAlignment align1(s1,s2);
		CyclicAlignment align2(s3,s2);
		cout<<2*max(align1.solve(),align2.solve())<<endl;
	}
	
    return 0;

}
