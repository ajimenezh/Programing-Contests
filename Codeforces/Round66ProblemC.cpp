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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

string s;
int k;
int ca;

int c[28][28];
int dp[101][101][28];

int solve(int i, int m, int l) {
    if (i==s.length()) return 0;
    if (dp[i][m][l]!=-1) return dp[i][m][l];

    int tmp = 0;

    for (char a='a'; a<='z'; a++) {
        if (a==s[i]) {
            tmp = max(tmp,solve(i+1,m,a-'a')+c[l][a-'a']);
        }
        else {
            if (m>0)
                tmp = max(tmp,solve(i+1,m-1,a-'a')+c[l][a-'a']);
        }
    }

    dp[i][m][l] = tmp;

    return tmp;
}

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    for (int i=0; i<28; i++) for (int j=0; j<28; j++) c[i][j] = 0;

    cin>>s;
    cin>>k;
    cin>>ca;

    for (int i=0; i<ca; i++) {
        char x, y;
        int co;
        cin>>x>>y>>co;
        c[x-'a'][y-'a'] = max(c[x-'a'][y-'a'],co);
    }

    for (int i=0; i<s.length(); i++)
        for (int j=0; j<=k; j++)
            for (int k=0; k<28; k++)
                dp[i][j][k] = -1;

    int sol = sol = solve(1,k,s[0]-'a');
    for (char i = 'a'; i<='z'; i++) {
        if (s[0]!=i && k>0)
            sol = max(sol,solve(1,k-1,i-'a'));
    }

    cout<<sol;

	return 0;

}
