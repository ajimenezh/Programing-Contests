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

string s;
string v[51000];
int n;
string str;
int mapa[26] = {2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0};
int dp[105];
int pre[105];
string vs[51000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>s && s!="-1") {
        cin>>n;
        for (int i=0; i<n; i++) {
            cin>>str;
            string s2;
            for (int i=0; i<str.length(); i++) s2 += char(mapa[str[i]-'a']+'0');
            v[i] = s2;
            vs[i] = str;
        }
        for (int i=0; i<=s.length(); i++) dp[i] = 1000000;
        dp[0] = 0;
        for (int i=1; i<=s.length(); i++) {
            for (int j=0; j<n; j++) if (i-(int)v[j].length()>=0 && v[j]==s.substr(i-v[j].length(),v[j].length())) {
                if (dp[i]>dp[i-v[j].length()] + 1) {
                    dp[i] = dp[i-v[j].length()] + 1;
                    pre[i] = j;
                }
            }
        }
        if (dp[s.length()]>=1000000) cout<<"No solution."<<endl;
        else {
            string sol;
            int p = s.length();
            while (p!=0) {
                sol = vs[pre[p]] + " " + sol;
                p = p - v[pre[p]].length();
            }
            cout<<sol<<endl;
        }
    }


    return 0;

}
