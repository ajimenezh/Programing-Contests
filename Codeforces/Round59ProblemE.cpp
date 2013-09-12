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

bool dp[1<<19];
bool vis[1<<19];
int total;
string s[5];
int index[5][5];

bool solve(int mask) {
    if (mask == total) return 1;
    if (vis[mask]) return dp[mask];
    bool sol = 0;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (s[i][j]=='O') {
                if (mask & (1<<(index[i][j]))) continue;
                int m = mask;
                for (int p=i; p<5; p++) {
                    if (s[p][j]=='.') break;
                    if (m & (1<<(index[p][j]))) break;
                    m |= (1<<(index[p][j]));
                    sol |= solve(m);
                }
                m = mask;
                int k = 0;
                for (int p=i; p<5; p++) {
                    if (j-k<0) break;
                    if (s[p][j-k]=='.') break;
                    if (m & (1<<(index[p][j-k]))) break;
                    m |= (1<<(index[p][j-k]));
                    sol |= solve(m);
                    k++;
                }
                m = mask;
                for (int p=j; p<5; p++) {
                    if (s[i][p]=='.') break;
                    if (m & (1<<(index[i][p]))) break;
                    m |= (1<<(index[i][p]));
                    sol |= solve(m);
                }
            }
        }
    }
    sol = 1-sol;
    dp[mask] = sol;
    vis[mask] = 1;
    //cout<<mask<<" "<<f<<" "<<dp[mask][f]<<endl;
    return sol;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<5; i++) getline(cin,s[i]);
    for (int i=0; i<5; i++) {
        string str;
        for (int j=0; j<(2-i); j++) str += '.';
        for (int j=0; j<s[i].length(); j++) {
            if (s[i][j]=='.') str += '.';
            if (s[i][j]=='O') str += 'O';
        }
        for (int j=1; j<(i-1); j++) str += '.';
        s[i] = str;
    }
    int k = 0;
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) {
        if (s[i][j]=='O') index[i][j] = k++;
        else index[i][j] = -1;
    }
    total = (1<<k) - 1; //cout<<total<<endl;
    //for (int i=0; i<5; i++) {for (int j=0; j<5; j++) cout<<index[i][j]<<" "; cout<<endl;}
    !solve(0) ? cout<<"Karlsson" : cout<<"Lillebror";

    return 0;

}
