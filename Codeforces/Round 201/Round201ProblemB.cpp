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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

string s1;
string s2;
string s3;
string virus;

int dp[101][101][101];
int pre[101][101][101];

int fail[110];

void failfunction(string p) {
    int m = p.length();
    int cnt = fail[0] = -1;
    for (int i=1; i<=m; i++) {
        while (cnt>=0 && p[cnt] != p[i-1]) cnt = fail[cnt];
        fail[i] = ++cnt;
    }
}

int solve(int i, int j, int k) {
    if (i==s1.length() || j==s2.length()) return 0;
    if (dp[i][j][k]>=0) return dp[i][j][k];

    int tmp = -1;
    int est;
    if (s1[i]==s2[j]) {
        if (s1[i]==s3[k]) {
            if (k!=s3.length()-1) {
                int l = 1 + solve(i+1,j+1,k+1);
                if (tmp<l) {
                    tmp = l;
                    est = 4;
                }
            }
        }
        else {
            int next = k;
            while (true) {
                next = fail[next];
                if (next==-1 || s1[i]==s3[next]) break;
            }
            next++;
            int l = 1 + solve(i+1,j+1,next);
            if (tmp<l) {
                tmp = l;
                est = 3;
            }
        }
    }

    int l = solve(i,j+1,k);
    if (tmp<l) {
        tmp = l;
        est = 2;
    }
    l = solve(i+1,j,k);
    if (tmp<l) {
        tmp = l;
        est = 1;
    }

    dp[i][j][k] = tmp;
    pre[i][j][k] = est;

    return tmp;

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s1>>s2>>s3;

    failfunction(s3);

    for (int i=0; i<s1.length(); i++) for (int j=0; j<s2.length(); j++) for (int k=0; k<s3.length(); k++) dp[i][j][k] = -1;

    int ans = solve(0,0,0);

    if (ans==0) {
        cout<<0<<endl;
        return 0;
    }

    string sol;

    int i=0, j=0, k=0;
    while (true) {
        if (i==s1.length() || j==s2.length()) break;
        if (pre[i][j][k]==1) {
            i++;
        }
        else if (pre[i][j][k]==2) {
            j++;
        }
        else if (pre[i][j][k]==3) {
            sol = sol + s1[i];
            int next = k;
            while (true) {
                next = fail[next];
                if (next==-1 || s1[i]==s3[next]) break;
            }
            next++;
            k=next;
            j++;
            i++;
        }
        else if (pre[i][j][k]==4) {
            sol = sol + s1[i];
            j++;
            i++;
            k++;
        }
    }

    cout<<sol<<endl;

    return 0;

}
